#include <stdio.h>

int main() {
  int i = 10;
  float f = 2.34;
  char ch = 'k';

  void *void_pointer;

  void_pointer = &i;
  printf("Value of i = %d\n", *(int*)void_pointer);

  void_pointer = &f;
  printf("Value of f = %.2f\n", *(float*)void_pointer);

  void_pointer = &ch;
  printf("Value of ch = %c\n", *(char*)void_pointer);

  return 0;
}