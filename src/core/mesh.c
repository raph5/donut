#include <mesh.h>
#include <mymath.h>
#include <math.h>
#include <utils.h>

void init_mesh_pos(Mesh *mesh) {
  mesh->x = 0;
  mesh->y = 0;
  mesh->z = 0;
  mesh->rx = 0;
  mesh->ry = 0;
  mesh->rz = 0;
  mesh->scale = 1;
}

void update_matrix(Mesh *mesh) {
  mat4_t mat1;
  mat4_t mat2;

  set_rotationx_mat4(mesh->rotation_matrix, mesh->rx);
  set_rotationy_mat4(mat1, mesh->ry);
  mult_mat4(mesh->rotation_matrix, mat1, mat2);
  
  set_rotationz_mat4(mat1, mesh->rz);
  mult_mat4(mat2, mat1, mesh->rotation_matrix);

  set_translation_mat4(mesh->matrix, mesh->x, mesh->y, mesh->z);
  set_scale_mat4(mat1, mesh->scale);
  mult_mat4(mesh->matrix, mat1, mat2);

  mult_mat4(mat2, mesh->rotation_matrix, mesh->matrix);
}