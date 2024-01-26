#include <render.h>
#include <mymath.h>
#include <types.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Renderer create_renderer(Mesh *mesh, Camera *camera, int scr_width, int scr_height) {
  Renderer renderer;

  renderer.scr_width = scr_width;
  renderer.scr_height = scr_height;

  renderer.pixel_b = create_buffer(scr_width * scr_height, sizeof(uint8_t));
  renderer.vertex_b = create_buffer(mesh->vertex_length, sizeof(mat4_t));
  renderer.variant_b = create_buffer(mesh->vertex_length, sizeof(Variant));
  renderer.depth_b = create_buffer(scr_width * scr_height, sizeof(float));
  renderer.fragment_b = create_buffer(scr_width * scr_height, sizeof(uint16_t));
  renderer.fragment_variant_b = create_buffer(scr_width * scr_height, sizeof(Variant));

  return renderer;
}

void free_renderer(Renderer renderer) {
  free(renderer.vertex_b);
  free(renderer.variant_b);
  free(renderer.depth_b) ;
  free(renderer.fragment_b);
  free(renderer.pixel_b);
  free(renderer.fragment_variant_b);
}


void render(Renderer *renderer, Mesh *mesh, Camera *camera) {

  int scr_length = renderer->scr_width * renderer->scr_height;

  // application du vertex shader à la mesh
  for(int i=0; i<mesh->vertex_length; i++) {
    mesh->vertex_shader(
      &mesh->vertex_data[i],
      renderer->vertex_b[i],
      &renderer->variant_b[i],
      camera->proj_matrix,
      mesh->matrix,
      mesh->rotation_matrix
    );
  }

  // initialisation du fragment buffer
  for(int i=0; i<scr_length; i++) {
    renderer->fragment_b[i] = EMPTY_FRAG_ID;
  }

  // rasterisation
  float minx, miny, maxx, maxy;  // pour encadrer le triangle dans un carré
  uint16_t i1, i2, i3;  // id des 3 vertices du triangle
  int scr_minx, scr_miny, scr_maxx, scr_maxy;
  int x, y;  // coordonées x et y de pixel
  float _x, _y;
  float pv1, pv2, pv3;  // produits vectoriel
  float depth;
  int px_index;
  vec3_t interpolation_vec;
  vec3_t depth_vec;
  vec3_t normal_vec;
  for(int i=0; i<mesh->index_length; i++) {

    // i1 c'est l'index du premier vertex
    i1 = mesh->index[i*3];
    i2 = mesh->index[i*3+1];
    i3 = mesh->index[i*3+2];
    
    maxx = max3(renderer->vertex_b[i1][0], renderer->vertex_b[i2][0], renderer->vertex_b[i3][0]);
    minx = min3(renderer->vertex_b[i1][0], renderer->vertex_b[i2][0], renderer->vertex_b[i3][0]);
    maxy = max3(renderer->vertex_b[i1][1], renderer->vertex_b[i2][1], renderer->vertex_b[i3][1]);
    miny = min3(renderer->vertex_b[i1][1], renderer->vertex_b[i2][1], renderer->vertex_b[i3][1]);

    // si le triangle est totalement en dehors de l'écran alors on passe au suivant
    if(minx > 1 || maxx < -1 || miny > 1 || maxy < -1) continue;

    scr_minx = to_int((minx + 1) / 2 * renderer->scr_width);
    scr_miny = to_int((miny + 1) / 2 * renderer->scr_height);
    scr_maxx = to_int((maxx + 1) / 2 * renderer->scr_width) + 1;
    scr_maxy = to_int((maxy + 1) / 2 * renderer->scr_height) + 1;

    scr_minx = clamp(scr_minx, 0, renderer->scr_width);
    scr_miny = clamp(scr_miny, 0, renderer->scr_height);
    scr_maxx = clamp(scr_maxx, 0, renderer->scr_width);
    scr_maxy = clamp(scr_maxy, 0, renderer->scr_height);

    for(y=scr_miny; y<scr_maxy; y++) {
      for(x=scr_minx; x<scr_maxx; x++) {

        // pour chaque pixel de coordoné x, y on regarde maintant si il est dans la triangle ou non
        _x = ((to_float(x) + 0.5) / renderer->scr_width * 2) - 1;
        _y = ((to_float(y) + 0.5) / renderer->scr_height * 2) - 1;

        pv1 = (renderer->vertex_b[i2][0] - renderer->vertex_b[i1][0]) * (_y - renderer->vertex_b[i1][1]) - (_x - renderer->vertex_b[i1][0]) * (renderer->vertex_b[i2][1] - renderer->vertex_b[i1][1]);
        pv2 = (renderer->vertex_b[i3][0] - renderer->vertex_b[i2][0]) * (_y - renderer->vertex_b[i2][1]) - (_x - renderer->vertex_b[i2][0]) * (renderer->vertex_b[i3][1] - renderer->vertex_b[i2][1]);
        pv3 = (renderer->vertex_b[i1][0] - renderer->vertex_b[i3][0]) * (_y - renderer->vertex_b[i3][1]) - (_x - renderer->vertex_b[i3][0]) * (renderer->vertex_b[i1][1] - renderer->vertex_b[i3][1]);

        // interpolation linéaire de la profondeur
        depth_vec[0] = renderer->vertex_b[i1][2];
        depth_vec[1] = renderer->vertex_b[i2][2];
        depth_vec[2] = renderer->vertex_b[i3][2];
        interpolation_vec[0] = sqrt(square(_y - renderer->vertex_b[i1][1]) + square(_x - renderer->vertex_b[i1][0]));
        interpolation_vec[1] = sqrt(square(_y - renderer->vertex_b[i2][1]) + square(_x - renderer->vertex_b[i2][0]));
        interpolation_vec[2] = sqrt(square(_y - renderer->vertex_b[i3][1]) + square(_x - renderer->vertex_b[i3][0]));
        mult_vec3_float(interpolation_vec, 1/(interpolation_vec[0] + interpolation_vec[1] + interpolation_vec[2]));
        depth = dot_product_vec3(interpolation_vec, depth_vec);

        px_index = y*renderer->scr_width + x;

        if(
          ((pv1 <= 0 && pv2 <= 0 && pv3 <= 0) || (pv1 >= 0 && pv2 >= 0 && pv3 >= 0)) &&  // in triangle check
          (renderer->fragment_b[px_index] == EMPTY_FRAG_ID || depth < renderer->depth_b[px_index])  // depth check
        ) {
          renderer->fragment_b[px_index] = i;
          renderer->depth_b[px_index] = depth;

          // variant interpolation
          normal_vec[0] = renderer->variant_b[i1].normal[0];
          normal_vec[1] = renderer->variant_b[i2].normal[0];
          normal_vec[2] = renderer->variant_b[i3].normal[0];
          renderer->fragment_variant_b[px_index].normal[0] = dot_product_vec3(interpolation_vec, normal_vec);
          normal_vec[0] = renderer->variant_b[i1].normal[1];
          normal_vec[1] = renderer->variant_b[i2].normal[1];
          normal_vec[2] = renderer->variant_b[i3].normal[1];
          renderer->fragment_variant_b[px_index].normal[1] = dot_product_vec3(interpolation_vec, normal_vec);
          normal_vec[0] = renderer->variant_b[i1].normal[2];
          normal_vec[1] = renderer->variant_b[i2].normal[2];  
          normal_vec[2] = renderer->variant_b[i3].normal[2];
          renderer->fragment_variant_b[px_index].normal[2] = dot_product_vec3(interpolation_vec, normal_vec);
        }
      }
    }
  }

  // fragment buffer
  for(int i=0; i<scr_length; i++) {
    if(renderer->fragment_b[i] != EMPTY_FRAG_ID) {
      mesh->fragment_shader(
        &renderer->fragment_variant_b[i],
        &renderer->pixel_b[i]
      );
    }
    else {
      renderer->pixel_b[i] = 0;
    }
  }

}