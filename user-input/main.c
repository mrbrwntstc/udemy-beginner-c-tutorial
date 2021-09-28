#include <stdio.h>

int main() 
{
  char str[100];
  int i;

  printf("Enter a value: ");
  // don't need to pass reference to str because str is a pointer
  scanf("%s %d", str, &i);

  printf("\nYou entered: %s %i", str, i);

  return 0;
}