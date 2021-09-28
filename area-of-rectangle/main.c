#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  double length = atoi(argv[1]);
  double width = atoi(argv[2]);
  double perimeter = 2.0 * (length * width);
  double area = length * width;

  printf("\nPerimeter of %fx%f rectangle is %f\n", length, width, perimeter);
  printf("\nArea of %fx%f rectangle is %f\n", length, width, area);

  return 0;
}