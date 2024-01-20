#ifndef CORE_HEADER
#define CORE_HEADER

#include <buffer.h>
#include <mymath.h>

// vertex data buffer
typedef buffer vertex_data_b;

// index buffer
// stocke tout les triangles de la mesh
// [ ... 0, 1, 2, ... ] signifie que les vertices 0 1 et 2 sont reliés
typedef uint16_buffer index_b;

// vertex buffer
// stocke la position les vertex calculés par le vertex shader (voir OpenGL) 
typedef float_buffer vertex_b;

// variant buffer
// stock les variants calculés par le vertex shader (voir OpenGL)
typedef buffer variant_b;

// fragment buffer
// stocke l'id du triangle affiché dans ce pixel
// si le pixel n'est pas occupé l'id est fixé à empty_frag_id
typedef uint16_buffer fragment_b;
const u_int16_t empty_frag_id = 0xffff;

// depth buffer
// stocke la profondeur de chaque px de l'écran
typedef float_buffer depth_b;

// pixel buffer
// contiens la couleur finale à afficher
// dans notre cas ce sera un uint8 qui peut prendre un valeur entre 0 et 7 dépenement de la lumineusité du px
typedef uint8_buffer pixel_b;


// uniforms (voir OpenGL)
// liste de l'adresse de tout les uniforms
typedef void *uniforms_t;

// vertex shader (voir OpenGL)
typedef void (*vertex_shader_t)(vertex_data_b vertex_data, uniforms_t uniforms, vertex_b vertex, variant_b variant);

// fragment shader (voir OpenGL)
typedef void (*fragment_shader_t)(vertex_b vertex, variant_b variant, pixel_b pixel);

#endif