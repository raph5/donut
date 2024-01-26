#include <utils.h>
#include <math.h>

void set_rotationx_mat4(mat4_t mat, float r) {
  set_unit_mat4(mat);
  mat[5] = cosf(r);
  mat[6] = sinf(r);
  mat[9] = -mat[6];
  mat[10] = mat[5];
}

void set_rotationy_mat4(mat4_t mat, float r) {
  set_unit_mat4(mat);
  mat[0] = cosf(r);
  mat[8] = sinf(r);
  mat[2] = -mat[8];
  mat[10] = mat[0];
}

void set_rotationz_mat4(mat4_t mat, float r) {
  set_unit_mat4(mat);
  mat[0] = cosf(r);
  mat[4] = sinf(r);
  mat[1] = -mat[4];
  mat[5] = mat[0];
}

void set_translation_mat4(mat4_t mat, float x, float y, float z) {
  set_unit_mat4(mat);
  mat[3] = x;
  mat[7] = y;
  mat[11] = z;
}

void set_scale_mat4(mat4_t mat, float s) {
  set_unit_mat4(mat);
  mat[0] = s;
  mat[5] = s;
  mat[10] = s;
  mat[15] = s;
}