#include <mymath.h>
#include <math.h>


// copy vec3 into dest
void copy_vec3(vec3_t vec, vec3_t dest) {
  dest[0] = vec[0];
  dest[1] = vec[1];
  dest[2] = vec[2];
}

// return le produit scalaire entre vec1 et vec2
float dot_product_vec3(vec3_t vec1, vec3_t vec2) {
  float acc = vec1[0] * vec2[0];
  acc += vec1[1] * vec2[1];
  acc += vec1[2] * vec2[2];
  return acc;
}

// normalise le vecteur
void normalize(vec3_t vec) {
  float norm = sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]); 
  vec[0] /= norm;
  vec[1] /= norm;
  vec[3] /= norm;
}

// multiplie vec par le scalaire x
void mult_vec3_float(vec3_t vec, float x) {
  vec[0] *= x;
  vec[1] *= x;
  vec[2] *= x;
}