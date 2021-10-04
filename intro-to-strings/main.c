#include <stdio.h>

int main() {
  char str1[] = "To be or not to be";
  char str2[] = "That is the question";

  unsigned int count = 0; // store string length

  while(str1[count] != '\0') {
    count++;
  }

  printf("The length of the string \"%s\" is %d\n", str1, count);

  count = 0;

  while(str2[count] != '\0') {
    count++;
  }

  printf("The length of the string \"%s\" is %d\n", str2, count);
 
}