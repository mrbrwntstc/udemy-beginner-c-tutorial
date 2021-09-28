#include <stdio.h>

int main() {
  double hours_worked;
  double hourly_rate = 12.00;
  double overtime_hourly_rate = hourly_rate + (hourly_rate / 2.00);

  printf("Enter the number of hours worked: ");
  scanf("%.2f", &hours_worked);
  printf("\n");

  double gross_pay;
  if(hours_worked <= 40) {
    gross_pay = hours_worked * hourly_rate;
  } else {
    double overtime_hours = hours_worked - 40;
    gross_pay = (hourly_rate * 40) + (overtime_hourly_rate * overtime_hours);
  }

  double net_pay = 0.00;
  
}