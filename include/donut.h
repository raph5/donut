#ifndef DONUT_HEADER
#define DONUT_HEADER

#include <core.h>
#include <mesh.h>

Mesh create_donut(float radius, float tube, int radialSegment, int tubularSegment);
void free_donut(Mesh donut);

#endif