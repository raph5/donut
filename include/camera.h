#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <mymath.h>

typedef struct Camera_s Camera;

struct Camera_s {
  mat4_t proj_matrix;  // camera projection matrix
};

Camera create_orthographic_camera(float aspect_ratio);

void set_orthographic_projection_matrix(mat4_t matrix, float left, float right, float bottom, float top, float near, float far);

#endif