#include <stdio.h>

#define MONTHS 12

int main() {
  // C does not provide a shortcut mechanism to initialize all elements in an array
  int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for(int index = 0; index < MONTHS; index++) {
    printf("Month %d has %2d days.\n", index + 1, days[index]);
  }

  return 0;
}