#ifndef MESH_HEADER
#define MESH_HEADER

#include <core.h>

typedef struct Mesh_s Mesh;

// mesh data
struct Mesh_s {
  vertex_shader_t vertex_shader;
  fragment_shader_t fragment_shader;
  index_b index;
  int index_length;  // nombre de triangles
  vertex_data_b vertex_data;
  int vertex_length;  // nombre de vertices
  int vertex_size;  // nombre d'octés occupés par un vertex dans le vertex data buffer
  int variant_size;  // nombre d'octés occupes pas les variants d'un même vertex dans le variant buffer
  mat4_t matrix;  // matrice de tranformation
};

Mesh *create_mesh(void);
void free_mesh(Mesh *mesh_p);

#endif