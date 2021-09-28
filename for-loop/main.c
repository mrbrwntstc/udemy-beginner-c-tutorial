#include <stdio.h>

int main() {
  // stores the sum of integers
  unsigned long long sum = 0ll;
  // the number of integers to be summed
  unsigned int count = 0;

  printf("How many numbers to sum? ");
  scanf("%d", &count);

  for(unsigned int i = 1; i <= count; ++i) {
    sum += i;
  }

  printf("\nThe sum of the first %u numbers is %llu.\n", count, sum);
}