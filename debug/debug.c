#include <stdlib.h>
#include <stdio.h>
#include <core.h>
#include <mesh.h>
#include <mymath.h>
#include <types.h>

void print_mat4(mat4_t mat) {
  for(int i=0; i<4; i++) {
    printf("| ");
    for(int j=0; j<4; j++) {
      printf("%0.001f ", mat[i*4 + j]);
    }
    printf("|\n");
  }
}

vec3_t TRI_LIGHT_SOURCE = { 0, 0, 1 }; 

void tri_vertex_shader(VertexData *vertex_data, vec4_t vertex, Variant *variant, mat4_t proj_matrix, mat4_t transforamtion_matrix, mat4_t rotation_matrix) {
  mult_vec4_mat4(vertex_data->vertex, transforamtion_matrix, vertex);
  mult_vec4_mat4_local(vertex, proj_matrix);
  mult_vec3_mat4(vertex_data->normal, rotation_matrix, 0, variant->normal);
}

void tri_fragment_shader(Variant *variant, pixel_t pixel) {
  *pixel = 5;
}

Mesh create_triangle() {
  Mesh triangle;

  init_mesh_pos(&triangle);

  triangle.scale = 3;

  update_matrix(&triangle);

  triangle.fragment_shader = tri_fragment_shader;
  triangle.vertex_shader = tri_vertex_shader;
  triangle.index_length = 2;
  triangle.vertex_length = 4;

  triangle.index = create_buffer(triangle.index_length, 3*sizeof(uint16_t));
  triangle.index[0] = 0;
  triangle.index[1] = 1;
  triangle.index[2] = 2;
  triangle.index[3] = 0;
  triangle.index[4] = 2;
  triangle.index[5] = 3;

  triangle.vertex_data = create_buffer(triangle.vertex_length, sizeof(VertexData));
  
  for(int i=0; i<4; i++) {
    triangle.vertex_data[i].vertex[0] = 0;
    triangle.vertex_data[i].vertex[1] = 0;
    triangle.vertex_data[i].vertex[2] = 0;
    triangle.vertex_data[i].vertex[3] = 1;
    triangle.vertex_data[i].normal[0] = 0;
    triangle.vertex_data[i].normal[1] = 0;
    triangle.vertex_data[i].normal[2] = 1;
  }

  triangle.vertex_data[0].vertex[0] = -2;
  triangle.vertex_data[0].vertex[1] = 2;
  triangle.vertex_data[1].vertex[0] = 2;
  triangle.vertex_data[1].vertex[1] = 2;
  triangle.vertex_data[2].vertex[0] = 2;
  triangle.vertex_data[2].vertex[1] = -2;
  triangle.vertex_data[3].vertex[0] = -2;
  triangle.vertex_data[3].vertex[1] = -2;

  return triangle;
}

void free_triangle(Mesh triangle) {
  free(triangle.index);
  free(triangle.vertex_data);
}