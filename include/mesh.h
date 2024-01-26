#ifndef MESH_HEADER
#define MESH_HEADER

#include <core.h>

typedef struct Mesh_s Mesh;

// mesh data
struct Mesh_s {
  vertex_shader_t vertex_shader;
  fragment_shader_t fragment_shader;

  index_t index;
  int index_length;  // nombre de triangles
  vertex_data_t vertex_data;
  int vertex_length;  // nombre de vertices

  float x;  // position
  float y;
  float z;
  float rx;  // euler rotation
  float ry;
  float rz;
  float scale;  // scale

  mat4_t matrix;  // matrice de tranformation
  mat4_t rotation_matrix;  // matrice de rotation
};

void init_mesh_pos(Mesh *mesh);
void update_matrix(Mesh *mesh);

#endif