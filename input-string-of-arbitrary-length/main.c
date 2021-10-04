#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *string = NULL;
  int string_length = -1;

  while (string_length <= 0) {
    printf("How many characters will this string hold (at least 1)? ");
    scanf("%d", &string_length);
  }

  string = (char*) calloc(string_length, sizeof(char));

  if(string != NULL) {
    printf("Enter the string of %d characters: ", string_length);
    scanf("%s", string);

    printf("Entered %s\n", string);

    free(string);
  }

  return 0;
}