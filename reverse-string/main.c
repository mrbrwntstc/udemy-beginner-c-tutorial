#include <stdio.h>
#include <string.h>

void reverse_string(char string[]);

int main() {
  char string[80];

  printf("Reverse this string: ");
  scanf("%s", string);
  reverse_string(string);
  printf("Reverse is %s\n", string);
}

void reverse_string(char string[]) {
  int length = strlen(string);

  for(int i = 0, j = (length - 1); i < (length / 2); i++, j--) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
  }
}