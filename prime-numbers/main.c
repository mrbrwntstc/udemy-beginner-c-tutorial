#include <stdio.h>
#include <stdbool.h>

#define MIN 5
#define MAX 100
#define ARRAY_LENGTH 100

// find all prime numbers from 1-100
int main() {
  int primes[ARRAY_LENGTH] = {2,3};

  int current_index = 2;
  for(int num = MIN; num < MAX; num += 2) {
    bool is_prime = true;
    // a simple algorithm to determine if a number is prime
    // is if it is not divisible by all prime numbers before it
    for(int i = 0; i < current_index; i += 1) {
      if((num % primes[i]) == 0) {
        is_prime = false;
        break;
      }
    }

    if(is_prime) {
      primes[current_index] = num;
      current_index += 1;
    }
  }

  printf("All prime numbers from 1 to 100:\n");
  for (int i = 0; i < current_index; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");
}