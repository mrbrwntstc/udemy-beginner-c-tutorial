#include <stdio.h>

int main() {
  int number = 0;
  int *p_number = NULL;

  number = 10;
  printf("Number's memory address: %p\n", &number);
  printf("Number's value: %d\n\n", number);

  p_number = &number;

  printf("p_number's memory address: %p\n", (void*)&p_number);
  printf("p_number's size: %zd\n", sizeof(p_number));
  printf("p_number's value: %p\n", p_number);
  printf("value p_number is pointing to: %d\n", *p_number);

  return 0;
}