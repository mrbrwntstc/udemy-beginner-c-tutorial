#include <stdio.h>

int main() {
  int minutes;
  double minutes_in_year = 5.2596e5;
  double years;
  double days;

  printf("How many minutes? ");
  scanf("%d", &minutes);

  years = minutes / minutes_in_year;
  days = years * 365;

  printf("%d minutes is %f years\n", minutes, years);
  printf("%d minutes is %f days\n", minutes, days);

  return 0;
}