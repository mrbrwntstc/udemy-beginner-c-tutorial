#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a = 10;
  int b = 5;

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("\n");
  swap(&a,&b);
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}