#include <mesh.h>
#include <stdlib.h>
#include <stdio.h>

Mesh *create_mesh(void) {
  Mesh *mesh = (Mesh *) malloc(sizeof(Mesh));

  if(mesh == NULL) {
    printf("mesh malloc error");
    abort();
  }

  mat4_t matrix = create_mat4();
  set_unit_mat4(matrix);
  mesh->matrix = matrix;

  return mesh;
}

void free_mesh(Mesh *mesh) {
  free(mesh->matrix);
  free(mesh);
}