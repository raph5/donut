#ifndef CORE_HEADER
#define CORE_HEADER

#include <core.h>
#include <mesh.h>
#include <camera.h>

void init_renderer(Mesh *mesh, Camera *camera, pixel_b pixel_buffer, int width, int height);
void destroy_renderer();

void render();

#endif