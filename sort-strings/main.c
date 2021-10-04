#include <stdio.h>
#include <string.h>

void bubble_sort(char strings[20][20], const int num_strings);

int main() {
  int num_strings = -1;
  while(num_strings <= 0) {
    printf("How many strings (at least 2)? ");
    scanf("%d", &num_strings);
  }
  
  char strings[20][20];
  for(int i = 0; i < num_strings; i++) {
    printf("String %d: ", i+1);
    scanf("%s", strings[i]);
  }

  printf("Unordered strings: ");
  for(int i = 0; i < num_strings; i++) {
    printf("%s ", strings[i]);
  }
  printf("\n");

  bubble_sort(strings, num_strings);

  printf("Sorted strings: ");
  for(int i = 0; i < num_strings; i++) {
    printf("%s ", strings[i]);
  }
  printf("\n");

}

void bubble_sort(char strings[20][20], const int num_strings) {
  for(int i = 0; i < (num_strings-1); i++) {
    // assume the last i elements are correct
    for(int j = i + 1; j < num_strings; j++) {
      if(strcmp(strings[i], strings[j]) > 0) {
        char temp[20];
        strcpy(temp, strings[i]);
        strcpy(strings[i], strings[j]);
        strcpy(strings[j], temp);
      }
    }
  }
}
