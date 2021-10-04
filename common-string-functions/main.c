#include <stdio.h>
#include <string.h>

int main() {
  char my_string[] = "Hello, world!";

  // string length
  printf("\"%s\" has %lu characters in it\n", my_string, strlen(my_string));

  // string copy
  char temp[50];
  // safe copy; don't put more characters than the length of temp
  strncpy(temp, my_string, sizeof(temp) - 1);
  printf("temp should contain %s\n", temp);

  // string concatenation
  char input[80];

  printf("Enter string to concat: ");
  scanf("%s", input);
  printf("The string \"%s\" concatenated with \"%s\" is \"%s\"\n", my_string, input, strcat(input, my_string));

  // string comparison
  printf("strcmp(\"A\",\"A\") is %d\n", strcmp("A","A"));
  printf("strcmp(\"A\",\"B\") is %d\n", strcmp("A","B"));
  printf("strcmp(\"B\",\"A\") is %d\n", strcmp("B","A"));
  printf("strcmp(\"C\",\"A\") is %d\n", strcmp("C","A"));
  printf("strcmp(\"Z\",\"a\") is %d\n", strcmp("Z","a"));
  printf("strcmp(\"apples\",\"apple\") is %d\n", strcmp("apples","apple"));

  return 0;
}