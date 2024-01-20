#ifndef BUFFER_HEADER
#define BUFFER_HEADER

typedef void *buffer_t;

typedef float *float_buffer_t;
typedef unsigned char *uint8_buffer_t;
typedef unsigned short *uint16_buffer_t;

buffer_t create_buffer(int length, int size);
void free_buffer(buffer_t buffer);

#endif