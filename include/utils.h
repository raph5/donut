#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <mymath.h>

void set_rotationx_mat4(mat4_t mat, float r);
void set_rotationy_mat4(mat4_t mat, float r);
void set_rotationz_mat4(mat4_t mat, float r);
void set_translation_mat4(mat4_t mat, float x, float y, float z);
void set_scale_mat4(mat4_t mat, float s);

#endif