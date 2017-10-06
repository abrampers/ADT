#include <stdio.h>

float toR(float t) {
  return 4.0/5 * t;
}

float toK(float t) {
  return t + 273.15;
}

float toF(float t) {
  return (9.0/5 * t) + 32;
}

int main(int argc, char const *argv[]) {

  float t;
  char c;

  scanf("%f %c", &t, &c);

  float result;

  switch (c) {
    case 'R': result = toR(t);
      break;
    case 'F': result = toF(t);
      break;
    case 'K': result = toK(t);
      break;
  }

  printf("%.2f\n",result );

  return 0;
}
