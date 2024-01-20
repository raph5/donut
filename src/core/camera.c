#include <camera.h>
#include <stdlib.h>
#include <stdio.h>

Camera *create_camera() {
  Camera *camera = malloc(sizeof(Camera));
  
  if(camera == NULL) {
    printf("camera malloc error");
    abort();
  }

  mat4_t matrix = create_mat4();
  camera->proj_matrix = matrix;

  return camera;
}

void free_camera(Camera *camera) {
  free(camera->proj_matrix);
  free(camera);
}

void init_camera(Camera *camera) {
  set_orthographic_projection_matrix(camera->proj_matrix, -10, 10, -10, 10, -10, 10);
}

void set_orthographic_projection_matrix(mat4_t matrix, float left, float right, float bottom, float top, float near, float far) {
  for(int i=0; i<16; i++) matrix[i] = 0;

  matrix[0] = 2 / (right-left);
  matrix[3] = -(right+left) / (right-left);
  matrix[5] = 2/(top-bottom);
  matrix[7] = -(top+bottom)/(top-bottom);
  matrix[10] = -2/(far-near);
  matrix[11] = -(far+near)/(far-near);
  matrix[15] = 1;
}