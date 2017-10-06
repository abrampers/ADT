#include <stdio.h>

int main(int argc, char const *argv[]) {

  int i, a;
  int sum = 0;

  scanf("%d", &a);

  for (i = 1; i <= a; i++) {
    sum += i;
  }

  printf("%d\n", sum);

  return 0;
}
