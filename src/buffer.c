#include <buffer.h>
#include <stdlib.h>
#include <stdio.h>

buffer_t create_buffer(int length, int size) {
  buffer_t buffer = malloc(length*size);

  if(buffer == NULL) {
    printf("buffer malloc error");
    abort();
  }

  return buffer;
}

void free_buffer(buffer_t buffer) {
  free(buffer);
}