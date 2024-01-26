#include <camera.h>

Camera create_orthographic_camera(float aspect_ratio) {
  Camera camera;

  set_orthographic_projection_matrix(camera.proj_matrix, -10*aspect_ratio, 10*aspect_ratio, -10/aspect_ratio, 10/aspect_ratio, -10, 10);
  
  return camera;
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