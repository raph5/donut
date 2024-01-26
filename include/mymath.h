#ifndef MYMATH_HEADER
#define MYMATH_HEADER

typedef float vec3_t[3];
typedef float vec4_t[4];
typedef float mat4_t[16];

float square(float x);

void copy_mat4(mat4_t mat, mat4_t dest);
void set_unit_mat4(mat4_t mat);
void add_mat4(mat4_t mat1, mat4_t mat2);
void mult_mat4(mat4_t mat1, mat4_t mat2, mat4_t result);
void mult_vec4_mat4(vec4_t vec, mat4_t mat, vec4_t result);
void mult_vec4_mat4_local(vec4_t vec, mat4_t mat);
void mult_vec3_mat4(vec3_t vec, mat4_t mat, float fourth_value, vec3_t result);

void copy_vec3(vec3_t vec, vec3_t dest);
float dot_product_vec3(vec3_t vec1, vec3_t vec2);
void normalize(vec3_t vec);
void mult_vec3_float(vec3_t vec, float x);

#define average_vec3(vec1, vec2, vec3, result)\
  result[0] = (vec1[0] + vec2[0] + vec3[0]) / 3;\
  result[1] = (vec1[1] + vec2[1] + vec3[1]) / 3;\
  result[2] = (vec1[2] + vec2[2] + vec3[2]) / 3

#define PI 3.14159265358979323846

#endif