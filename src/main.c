#include <render.h>
#include <canvas.h>
#include <stdio.h>
#include <mesh.h>
#include <donut.h>

int main() {

  int width;
  int height;
  
  init_cnv(&width, &height);

  Mesh mesh = create_donut(4, 2, 36, 16);
  // Mesh mesh = create_donut(4, 2, 12, 6);
  Camera camera = create_orthographic_camera(width/height*0.35);
  Renderer renderer = create_renderer(&mesh, &camera, width, height);

  // mesh.ry += 0.001;
  // update_matrix(&mesh);
  // render(&renderer, &mesh, &camera);
  // update_cnv(renderer.pixel_b, width, height);
  // while(!key_pressed());

  while(!key_pressed()) {
    render(&renderer, &mesh, &camera);
    update_cnv(renderer.pixel_b, width, height);

    mesh.ry += 0.001;
    update_matrix(&mesh);
  }

  end_cnv();
  free_donut(mesh);
  free_renderer(renderer);

  return 0;
}