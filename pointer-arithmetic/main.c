#include <stdio.h>

int array_sum(int *numbers, const int array_size);

int main() {
  int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
  int sum = array_sum(numbers, 10);

  printf("The sum of all integers from 1-10 is %d\n", sum);
}

int array_sum(int *numbers, const int array_size) {
  int sum = 0;
  int * const array_end = numbers + array_size;

  for(; numbers < array_end; numbers++) {
    sum += *numbers;
  }

  return sum;
}