#include <stdio.h>

int main() {
  int return_code = 0;
  FILE *fp;
  int c;

  fp = fopen("/Users/gbaby/repos/udemy-beginner-c-tutorial/read-file/file.txt", "r");

  if(fp == NULL) {
    perror("Could not open file");
    return_code = -1;
  }

  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  fclose(fp);
  fp = NULL;
  
  return return_code;
}