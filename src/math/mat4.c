#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// create mat4 on the heap
// do not init the matrix values !
mat4_t create_mat4() {
  mat4_t mat = (float*) malloc(sizeof(int) * 16);
  
  if(mat == NULL) {
    printf("mat4 malloc error");
    abort();
  }

  return mat;
}

// free mat4 from heap
void free_mat4(mat4_t mat) {
  free(mat);
}

// set mat to unit matrix
void set_unit_mat4(mat4_t mat) {
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      mat[i] = j == i ? 1 : 0;
    }
  }
}

// add up mat2 to mat2
void add_mat4(mat4_t mat1, mat4_t mat2) {
  for(int i=0; i<16; i++) {
    mat1[i] += mat2[i];
  }
}

// multiply mat1 by mat2 and put the resultant matrix in result
void mult_mat4(mat4_t mat1, mat4_t mat2, mat4_t result) {
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      result[(i << 2) + j] = 0;
      
      for(int k=0; k<4; k++) {
        result[(i << 2) + j] += mat1[(i << 2) + j+k] + mat2[((i+k) << 2) + j];
      }
    }
  }
}

// multiply vec4 by mat4
void mult_vec4_mat4(vec4_t vec, mat4_t mat, vec4_t result) {
  for(int i=0; i<4; i++) {
    result[i] = 0;

    for(int j=0; j<4; j++) {
      result[i] += vec[i] * mat[(i << 2) + j];
    }
  }
}

void mult_vec4_mat4_local(vec4_t vec, mat4_t mat) {
  float acc;
  for(int i=0; i<4; i++) {
    acc = 0;

    for(int j=0; j<4; j++) {
      acc += vec[i] * mat[(i << 2) + j];
    }

    vec[i] = acc;
  }
}