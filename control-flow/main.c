#include <stdio.h>

int main()
{
  int number, remainder;

  printf("Pick a number: ");
  scanf("%d", &number);
  printf("\n");

  remainder = number % 2;

  if(remainder == 0) {
    printf("%d is even.\n", number);
  } else {
    printf("%d is odd.\n", number);
  }

  return 0;
}