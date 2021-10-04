#include <stdio.h>
#include <string.h>

struct employee
{
  char name[10];
  int hire_date;
  float salary;
};


int main() {
  struct employee e1 = {.hire_date = 10, .salary = 1234.56, .name = "Jerry"};

  struct employee e2;
  printf("Name? ");
  scanf("%s", e2.name);
  
  printf("Hire date? ");
  scanf("%d", &e2.hire_date);

  printf("Salary? ");
  scanf("%f", &e2.salary);

  printf("%s %d %.2f\n", e1.name, e1.hire_date, e1.salary);
  printf("%s %d %.2f\n", e2.name, e2.hire_date, e2.salary);

  return 0;
}