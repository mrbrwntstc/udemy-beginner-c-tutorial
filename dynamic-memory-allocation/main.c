#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *str = NULL;

  // initial memory allocation
  str = (char*) malloc(15);
  strcpy(str, "jason");
  printf("String = %s, Address = %u\n", str, str);

  // reallocate memory
  str = (char*) realloc(str, 25);
  strcat(str, ".com");
  printf("String = %s, Address = %u\n", str, str);

  free(str);

  return 0;
}