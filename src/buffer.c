#include <buffer.h>
#include <stdlib.h>
#include <stdio.h>

void *create_buffer(int length, int size) {
  void *buffer = malloc(length*size);

  if(buffer == NULL) {
    printf("buffer malloc error");
    abort();
  }

  return buffer;
}