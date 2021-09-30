#include <stdio.h>

// for a span of 5 years: 
// calculate the total rainfall each year
// calculate the average yearly rainfall
// calculate the average rainfall for each month

#define YEARS 5
#define MONTHS 12

int main() {
  int years[YEARS] = {2020, 2019, 2018, 2017, 2016};
  double monthly_rainfall_last_five_years[YEARS][MONTHS] = 
  {
    {5.50, 7.13, 5.44, 5.45, 4.51, 3.89, 3.68, 1.55, 6.79, 1.35, 0.85, 6.46},   // 2020
    {3.34, 2.17, 2.44, 9.88, 9.87, 7.12, 0.73, 1.07, 3.60, 4.05, 0.53, 1.13},   // 2019
    {2.97, 8.94, 4.86, 3.16, 0.80, 1.44, 2.03, 1.77, 7.04, 8.44, 7.46, 9.74},   // 2018
    {5.58, 3.09, 2.72, 4.39, 5.87, 5.55, 2.86, 7.17, 0.61, 2.11, 1.53, 7.21},   // 2017
    {1.78, 2.64, 11.38, 12.63, 5.30, 2.22, 0.23, 9.62, 2.40, 1.14, 3.22, 4.12}, // 2016
  };

  for(int year = 0; year < YEARS; year++) {
    double total_annual_rainfall = 0;
    double average_annual_rainfall = 0;
    for(int month = 0; month < MONTHS; month++) {
      total_annual_rainfall += monthly_rainfall_last_five_years[year][month];
    }

    printf("For the year %d:\n", years[year]);
    printf("Total rainfall was %.2lf inches\n", total_annual_rainfall);
    printf("Average rainfall was %.2lf inches\n\n", total_annual_rainfall / MONTHS);
  }

  double average_rainfall_per_month_last_five_years[MONTHS] = {0};
  for(int month = 0; month < MONTHS; month++) {
    double total_rainfall = 0;
    for(int year = 0; year < YEARS; year++) {
      total_rainfall += monthly_rainfall_last_five_years[year][month];
    }
    average_rainfall_per_month_last_five_years[month] = total_rainfall / YEARS;
  }

  printf("Average rainfall per month in the last 5 years:\n");
  printf("JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC\n");
  for(int month = 0; month < MONTHS; month++) {
    printf("%.2lf ", average_rainfall_per_month_last_five_years[month]);
  }
  printf("\n");

  return 0;
}