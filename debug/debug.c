#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_mat4(mat4_t mat) {
  for(int i=0; i<4; i++) {
    printf("| ");
    for(int j=0; j<4; j++) {
      printf("%0.01f ", mat[i*4 + j]);
    }
    printf("|\n");
  }
}

void triangle_vertex_shader(vertex_data_b vertex_data, uniforms_t uniforms, vertex_b vertex, variant_b variant) {}

void triangle_fragment_shader(vertex_b vertex, variant_b variant, pixel_b pixel) {}

void create_triangle() {
  
}