#include <render.h>
#include <mymath.h>

// variables de travail du renderer (rw pour render worksapce)
vertex_b rw_vertex_buffer;
depth_b rw_depth_buffer;
fragment_b rw_fragment_buffer;
variant_b rw_variant_buffer;
fragment_variant_b rw_fragment_variant_buffer;
pixel_b rw_pixel_buffer;

Mesh *rw_mesh;
Camera *rw_camera;

int rw_scr_width;
int rw_scr_height;

// initialiser les variables de travail du renderer
void init_renderer(Mesh *mesh, Camera *camera, pixel_b pixel_buffer, int scr_width, int scr_height) {
  rw_mesh = mesh;
  rw_camera = camera;
  rw_pixel_buffer = pixel_buffer;
  rw_scr_width = scr_width;
  rw_scr_height = scr_height;

  rw_vertex_buffer = create_buffer(mesh->vertex_length, mesh->vertex_size);
  rw_variant_buffer = create_buffer(mesh->vertex_length, mesh->variant_size);
  rw_fragment_variant_buffer = create_buffer(mesh->vertex_length, mesh->variant_size);
  rw_depth_buffer = create_buffer(scr_width * scr_height, 4);
  rw_fragment_buffer = create_buffer(scr_width * scr_height, 2);
}

void destroy_renderer() {
  free_buffer(rw_vertex_buffer);
  free_buffer(rw_variant_buffer);
  free_buffer(rw_depth_buffer);
  free_buffer(rw_fragment_buffer);
  free_buffer(rw_fragment_variant_buffer);
}


void render() {
  
  int i = 0;
  for(int y=0; y<rw_scr_height; y++) {
    for(int x=0; x<rw_scr_width; x++) {
      rw_pixel_buffer[i] = (4*x) / rw_scr_width + (4*y) / rw_scr_height;
      i++;
    }
  }

}