#include <mymath.h>
#include "../debug/debug.c"
#include <stdio.h>

int main() {
  mat4_t mat = create_mat4();
  mat[5] = 5.7;
  print_mat4(mat);
  return 0;
}