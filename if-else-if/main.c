#include <stdio.h>

int main() {
  int number, sign;

  printf("Pick a number: ");
  scanf("%d", &number);
  printf("\n");

  if(number < 0) {
    sign = -1;
  } else if(number == 0) {
    sign = 0;
  } else { // must be positive
    sign = 1;
  }

  printf("sign is %d\n", sign);

  return 0;
}