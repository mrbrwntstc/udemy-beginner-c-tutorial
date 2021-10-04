#include <stdio.h>

int main() {
  int exit_code = 0;
  FILE *p_file;
  int c;
  int num_lines = 0;

  p_file = fopen("/Users/gbaby/repos/udemy-beginner-c-tutorial/number-of-lines-in-file/file.txt", "r");

  if(p_file == NULL) {
    perror("Could not open file.txt\n");
    exit_code = -1;
  } else {
    while((c = fgetc(p_file)) != EOF) {
      if(c == '\n') {
        num_lines++;
      }
    }
    // include EOF line
    num_lines++;

    printf("There are %d lines in file.txt\n", num_lines);
  }

  fclose(p_file);
  p_file = NULL;
  return exit_code;
}