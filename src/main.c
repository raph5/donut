#include <render.h>
#include <canvas.h>
#include <mesh.h>
#include <donut.h>
#include <types.h>

int main() {
  int width;
  int height;
  
  init_cnv(&width, &height);
  float aspect_ratio = to_float(width) / to_float(height) * 0.5;

  Mesh mesh = create_donut(4, 2, 36, 16);
  Camera camera = create_orthographic_camera(aspect_ratio);
  Renderer renderer = create_renderer(&mesh, &camera, width, height);

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
