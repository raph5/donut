#ifndef TYPES_HEADER
#define TYPES_HEADER

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

#define uint8(n) ((uint8_t*) n)
#define uint16(n) ((uint16_t*) n)

#define max(v1, v2) (v1 > v2 ? v1 : v2)
#define min(v1, v2) (v1 < v2 ? v1 : v2)
#define max3(v1, v2, v3) (v1 > v2 && v1 > v3 ? v1 : (v2 > v3 ? v2 : v3))
#define min3(v1, v2, v3) (v1 < v2 && v1 < v3 ? v1 : (v2 < v3 ? v2 : v3))

#define to_int(f) ((int) (f))
#define to_float(i) ((float) (i))

#define clamp(x, min, max) (x < min ? min : (x > max ? max : x))

#endif