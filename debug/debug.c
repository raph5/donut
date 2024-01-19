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