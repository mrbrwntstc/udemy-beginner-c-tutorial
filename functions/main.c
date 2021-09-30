#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int num1, int num2);
float absolute_value(float num);
float square_root(float num);

int main() {
  gcd(270, 192); // should be 6
  gcd(45, 210); // should be 15

  printf("Absolute value if %.1f is %.1f\n", -1.1f, absolute_value(-1.1f)); // should be 1.1
  printf("Absolute value of %.1f is %.1f\n", 0.0f, absolute_value(0.0f)); // should be 0

  printf("The square root of %.1f is %.1f\n", -5.0f, square_root(-5.0f)); // should be -1.0
  printf("The square root of %.0f is %.0f\n", 4.0f, square_root(4.0f)); // should be 2
  printf("The square root of %.0f is %.5f\n", 10.0f, square_root(10.0f));
}

/**
 * @brief Find the Greatest Common Divisor (GCD) of 2 numbers
 * using the Euclidean Algorithm
 * 
 * @param num1 
 * @param num2 
 * @return the greatest common divisor between num1 and num2
 */
int gcd(int num1, int num2) {
  int a, b;

  if(num1 > num2) {
    a = num1;
    b = num2;
  } else {
    a = num2;
    b = num1;
  }
  
  do {
    // need to express the larger number in quotient form
    // given two ints A,B where A > B
    // A = B*Q + R, where Q = quotient and R = remainder
    div_t div_result = div(a,b);

    // because GCD(A,B) = GCD(B,R), all we need to determine is GCD(B,R)
    a = b;
    b = div_result.rem;

  } while ((a != 0) && (b != 0));

  int gcd = (a == 0) && (b != 0) ? b : a;
  printf("Greatest Common Divisor (GCD) of %d and %d is %d\n", num1, num2, gcd);
  return gcd;
}

/**
 * @brief Determine the absolute value of a number
 * 
 * @param num the number to determine its absolute value
 * @return the number if it's positive, the negated number if it's negative
 */
float absolute_value(float num) {
  return num < 0 ? (num * -1.0f) : num;
}

/**
 * @brief Return the square root of a number
 * 
 * @param num the number to square root
 * @return -1 if num < 0, the square root of num otherwise
 */
float square_root(float num) {
  if(num < 0) {
    printf("Cannot find square root of %f because it is negative.\n", num);
    return -1.0f;
  }

  return sqrt(num);
}
