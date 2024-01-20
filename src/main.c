#include <render.h>
#include <canvas.h>
#include <stdio.h>
#include "../debug/debug.c"

int main() {

  int width;
  int height;
  
  init_cnv(&width, &height);

  pixel_b pixel_buffer = create_buffer(width*height, 1);
  init_renderer(NULL, NULL, pixel_buffer, width, height);

  while(!key_pressed()) {
    render();
    update_cnv(pixel_buffer, width, height);
  }

  end_cnv();
  free_buffer(pixel_buffer);
  destroy_renderer();

  return 0;
}