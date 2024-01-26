#ifndef MYCORE_HEADER
#define MYCORE_HEADER

#include <buffer.h>
#include <mymath.h>
#include <types.h>

// typedef for structs
typedef struct VertexData_s VertexData;
typedef struct Variant_s Variant;

// vertex data struct
struct VertexData_s {
  vec4_t vertex;
  vec3_t normal;
};

// variant data struct
struct Variant_s {
  vec3_t normal;
};


// vertex data buffer
typedef VertexData *vertex_data_t;

// index buffer
// stocke tout les triangles de la mesh
// [ ... 0, 1, 2, ... ] signifie que les vertices 0 1 et 2 sont reliés
typedef uint16_t *index_t;

// vertex buffer
// stocke la position les vertex calculés par le vertex shader (voir OpenGL) 
typedef mat4_t *vertex_t;

// variant buffer
// stock les variants calculés par le vertex shader (voir OpenGL)
typedef Variant *variant_t;

// fragment buffer
// stocke l'id du triangle affiché dans ce pixel
// si le pixel n'est pas occupé l'id est fixé à EMPTY_FRAG_ID
typedef uint16_t *fragment_t;
#define EMPTY_FRAG_ID 0xffff

// depth buffer
// stocke la profondeur de chaque pixel de l'écran
typedef float *depth_t;

// fragment variant buffer
// contient les données de variants calculés par interpolation linéaire pour chaque pixel
// c'est la data qui est donné au fragment shader
typedef Variant *fragment_variant_t;

// pixel buffer
// contiens la couleur finale à afficher
// dans notre cas ce sera un uint8 qui peut prendre un valeur entre 0 et 7 dépenement de la lumineusité du px
typedef uint8_t *pixel_t;


// vertex shader (voir OpenGL)
typedef void (*vertex_shader_t)(VertexData *vertex_data, vec4_t vertex, Variant *variant, mat4_t proj_matrix, mat4_t transforamtion_matrix, mat4_t rotation_matrix);

// fragment shader (voir OpenGL)
typedef void (*fragment_shader_t)(Variant *variant, pixel_t pixel);

#endif