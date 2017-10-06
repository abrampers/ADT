#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main(int argc, char const *argv[]) {

  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  int result = max(max(a,b),c);

  printf("%d\n", result);

  return 0;
}
