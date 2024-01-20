#ifndef CANVAS_BUFFER
#define CANVAS_BUFFER

#include <core.h>
#include <stdbool.h>

bool key_pressed();

void init_cnv(int *width, int *height);
void update_cnv(pixel_b pixel_buffer, int width, int height);
void end_cnv();

#endif