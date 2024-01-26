#ifndef CORE_HEADER
#define CORE_HEADER

#include <core.h>
#include <mesh.h>
#include <camera.h>

typedef struct Renderer_s Renderer;

struct Renderer_s {
  vertex_t vertex_b;
  depth_t depth_b;
  fragment_t fragment_b;
  variant_t variant_b;
  fragment_variant_t fragment_variant_b;
  pixel_t pixel_b;

  int scr_width;
  int scr_height;
};

Renderer create_renderer(Mesh *mesh, Camera *camera, int scr_width, int scr_height);
void free_renderer(Renderer renderer);

void render(Renderer *renderer, Mesh *mesh, Camera *camera);

#endif