#ifndef MYCORE_HEADER
#define MYCORE_HEADER

#include <buffer.h>
#include <mymath.h>

// vertex data buffer
typedef buffer_t vertex_data_b;

// index buffer
// stocke tout les triangles de la mesh
// [ ... 0, 1, 2, ... ] signifie que les vertices 0 1 et 2 sont reliés
typedef uint16_buffer_t index_b;

// vertex buffer
// stocke la position les vertex calculés par le vertex shader (voir OpenGL) 
typedef float_buffer_t vertex_b;

// variant buffer
// stock les variants calculés par le vertex shader (voir OpenGL)
typedef buffer_t variant_b;

// fragment buffer
// stocke l'id du triangle affiché dans ce pixel
// si le pixel n'est pas occupé l'id est fixé à EMPTY_FRAG_ID
typedef uint16_buffer_t fragment_b;
#define EMPTY_FRAG_ID 0xfff

// depth buffer
// stocke la profondeur de chaque pixel de l'écran
typedef float_buffer_t depth_b;

// fragment variant buffer
// contient les données de variants calculés par interpolation linéaire pour chaque pixel
// c'est la data qui est donné au fragment shader
typedef buffer_t fragment_variant_b;

// pixel buffer
// contiens la couleur finale à afficher
// dans notre cas ce sera un uint8 qui peut prendre un valeur entre 0 et 7 dépenement de la lumineusité du px
typedef uint8_buffer_t pixel_b;


// uniforms (voir OpenGL)
// liste de l'adresse de tout les uniforms
typedef void *uniforms_t;

// vertex shader (voir OpenGL)
typedef void (*vertex_shader_t)(vertex_data_b vertex_data, uniforms_t uniforms, vertex_b vertex, variant_b variant);

// fragment shader (voir OpenGL)
typedef void (*fragment_shader_t)(fragment_variant_b variant, pixel_b pixel);

#endif