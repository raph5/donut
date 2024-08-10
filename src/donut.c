#include <donut.h>
#include <math.h>
#include <stdlib.h>
#include <mymath.h>

vec3_t LIGHT_SOURCE = { 0.577, -0.577, 0.577 };

void donut_vertex_shader(VertexData *vertex_data, vec4_t vertex, Variant *variant, mat4_t proj_matrix, mat4_t transforamtion_matrix, mat4_t rotation_matrix) {
  mult_vec4_mat4(vertex_data->vertex, transforamtion_matrix, vertex);
  mult_vec4_mat4_local(vertex, proj_matrix);
  mult_vec3_mat4(vertex_data->normal, rotation_matrix, 0, variant->normal);
}

void donut_fragment_shader(Variant *variant, pixel_t pixel) {
  *pixel = to_int(5 + 4.5 * dot_product_vec3(variant->normal, LIGHT_SOURCE));
  // *pixel = 3;
}

Mesh create_donut(float radius, float tube, int radialSegment, int tubularSegment) {
  Mesh donut;

  init_mesh_pos(&donut);
  update_matrix(&donut);

  donut.fragment_shader = donut_fragment_shader;
  donut.vertex_shader = donut_vertex_shader;
  donut.index_length = radialSegment * tubularSegment * 2;
  donut.vertex_length = radialSegment * tubularSegment;
  donut.vertex_data = create_buffer(donut.vertex_length, sizeof(VertexData));
  donut.index = create_buffer(donut.index_length, 3*sizeof(uint16_t));
  
  float phi = 0;
  float theta = 0;
  float delta_phi = PI / radialSegment * 2;
  float delta_theta = PI / tubularSegment * 2;
  float sin_phi, cos_phi, sin_theta, cos_theta;

  int r, t;
  for(r=0; r<radialSegment; r++) {
    for(t=0; t<tubularSegment; t++) {
      sin_phi = sinf(phi);
      cos_phi = cosf(phi);
      sin_theta = sinf(theta);
      cos_theta = cosf(theta);

      donut.vertex_data[r*tubularSegment + t].vertex[0] = radius*sin_phi + tube*sin_phi*sin_theta;
      donut.vertex_data[r*tubularSegment + t].vertex[1] = radius*cos_phi + tube*cos_phi*sin_theta;
      donut.vertex_data[r*tubularSegment + t].vertex[2] = tube*cos_theta;
      donut.vertex_data[r*tubularSegment + t].vertex[3] = 1;

      donut.vertex_data[r*tubularSegment + t].normal[0] = sin_phi*sin_theta;
      donut.vertex_data[r*tubularSegment + t].normal[1] = cos_phi*sin_theta;
      donut.vertex_data[r*tubularSegment + t].normal[2] = cos_theta;

      donut.index[(r*tubularSegment + t)*6 + 0] = r*tubularSegment + t;
      donut.index[(r*tubularSegment + t)*6 + 1] = r*tubularSegment + ((t+1)%tubularSegment);
      donut.index[(r*tubularSegment + t)*6 + 2] = ((r+1)%radialSegment)*tubularSegment + t;

      donut.index[(r*tubularSegment + t)*6 + 3] = r*tubularSegment + ((t+1)%tubularSegment);
      donut.index[(r*tubularSegment + t)*6 + 4] = ((r+1)%radialSegment)*tubularSegment + t;
      donut.index[(r*tubularSegment + t)*6 + 5] = ((r+1)%radialSegment)*tubularSegment + ((t+1)%tubularSegment);

      theta += delta_theta;
    }
    phi += delta_phi;
  }

  return donut;
}

void free_donut(Mesh donut) {
  free(donut.index);
  free(donut.vertex_data);
}
