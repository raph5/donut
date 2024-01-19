#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// create vec4 on the heap
vec4_t create_vec4() {
  vec4_t vec = (float*) malloc(sizeof(int) * 4);
  
  if(vec == NULL) {
    printf("vec4 malloc error");
    abort();
  }

  // init vecrix values to 0
  for(int i=0; i<4; i++) {
    vec[i] = 0;
  }

  return vec;
}

// free vec4 from heap
void free_vec4(vec4_t vec) {
  free(vec);
}

// add up vec2 to vec2
void add_vec4(vec4_t vec1, vec4_t vec2) {
  for(int i=0; i<4; i++) {
    vec1[i] += vec2[i];
  }
}