#include <stdio.h>

#define HOURLY_RATE 12.00
#define TAXRATE_300 0.15
#define TAXRATE_150 0.20
#define TAXRATE_REST 0.25
#define OVERTIME 40
#define OVERTIME_RATE 1.5

int main() {
  int hours = 0;
  double gross_pay = 0;
  double taxes = 0;

  printf("Enter the number of hours worked this week: ");
  scanf("%d", &hours);

  if(hours <= OVERTIME) {
    gross_pay = hours * HOURLY_RATE;
  } else {
    gross_pay = OVERTIME * HOURLY_RATE;
    double overtime_pay = (hours - OVERTIME) * (HOURLY_RATE * OVERTIME_RATE);
    gross_pay += overtime_pay;
  }
  
  if(gross_pay <= 300) {
    taxes = gross_pay * TAXRATE_300;
  } else if((gross_pay > 300) && (gross_pay <= 450)) {
    taxes = (300 * TAXRATE_300);
    taxes += (gross_pay - 300) * TAXRATE_150;
  } else if (gross_pay > 450) {
    taxes = (300 * TAXRATE_300);
    taxes += (150 * TAXRATE_150);
    taxes += (gross_pay - 450) * TAXRATE_REST;
  }

  double net_pay = gross_pay - taxes;
  printf("Net pay for %d hours worked is %.2lf.\n", hours, net_pay);

  return 0;
}