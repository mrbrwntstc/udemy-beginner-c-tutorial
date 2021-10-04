#include <stdio.h>

int string_length(const char *string);

int main() {
  printf("hello should have 5 characters in it: %s\n", string_length("hello") == 5 ? "Yes" : "No");
  printf("an empty string should have 0 characters in it: %s\n", string_length("") == 0 ? "Yes" : "No");
}

int string_length(const char *string) {
  const char *ptr = string;

  // \0 has a numeric value of 0, which is false in C
  while (*ptr) {
    ptr++;
  }

  return (ptr - string);
}