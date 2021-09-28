#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t t;
  int random_number;

  // seed the random number generator with the clock's time
  srand((unsigned) time(&t));

  // generate a random number from 0-20
  random_number = rand() % 21;

  int user_guess = -1;
  int chances = 5;

  while((chances > 0) && (user_guess != random_number)) {
    printf("I'm thinking of a number between 0 and 20. Guess the number: ");
    scanf("%d", &user_guess);

    if ((user_guess < 0) || (user_guess > 20)) {
      printf("%d is not between 0 and 20.\n", user_guess);
    } else if(user_guess < random_number) {
      printf("%d is too low.\n", user_guess);
    } else if(user_guess > random_number) {
      printf("%d is too high.\n", user_guess);
    }

    chances -= 1;
    printf("You have %d tr%s left.\n", chances, chances == 1 ? "y" : "ies");
  }

  if(user_guess == random_number) {
    printf("%d is correct!\n", user_guess);
  } else { // ran out of chances
    printf("The number was %d.\n", random_number);
  }
}