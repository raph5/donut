#ifndef MYMATH_HEADER
#define MYMATH_HEADER

typedef float *vec4_t;
typedef float *mat4_t;

// vecteur à 4 composantes
vec4_t create_vec4();
void free_vec4(vec4_t mat);
void add_vec4(vec4_t mat1, vec4_t mat2);

// matrices à 4 dimensions
mat4_t create_mat4();
void free_mat4(mat4_t mat);
void set_unit_mat4(mat4_t mat);
void add_mat4(mat4_t mat1, mat4_t mat2);
void mult_mat4(mat4_t mat1, mat4_t mat2, mat4_t result);
void mult_vec4_mat4(vec4_t vec, mat4_t mat, vec4_t result);
void mult_vec4_mat4_local(vec4_t vec, mat4_t mat);

#endif