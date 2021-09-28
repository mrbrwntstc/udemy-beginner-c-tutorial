#include <stdio.h>

int main() {
  enum Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
  };

  enum Weekday today = Monday;

  printf("Today is ");

  switch(today) {
    case Monday:
      printf("Monday.\n");
      break;
    case Tuesday:
      printf("Tuesday.\n");
      break;
    case Wednesday:
      printf("Wednesday.\n");
      break;
    case Thursday:
      printf("Thursday.\n");
      break;
    default:
      printf("the weekend.\n");
      break;
  }
}