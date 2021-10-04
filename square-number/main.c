#include <stdio.h>

void square_number(int *p_num);

int main() {
  int a = 5;
  int b = 0;
  int c = -1;

  square_number(&a);
  printf("5 squared is %d\n", a);

  square_number(&b);
  printf("0 squared is %d\n", b);

  square_number(&c);
  printf("-1 squared is %d\n", c);

  return 0;
}

void square_number(int *p_num) {
  *p_num *= *p_num;
}