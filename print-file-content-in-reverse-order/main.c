#include <stdio.h>

int main() {
  int exit_code = 0;
  FILE *p_file;
  int ch;
  long num_bytes_in_file;
  long index = 0;

  p_file = fopen("/Users/gbaby/repos/udemy-beginner-c-tutorial/print-file-content-in-reverse-order/file.txt", "r");
  if(p_file == NULL) {
    perror("Could not open file.txt\n");
    exit_code = -1;
  } else {
    fseek(p_file, 0, SEEK_END);
    num_bytes_in_file = ftell(p_file);
    while (index < num_bytes_in_file) {
      index++;
      fseek(p_file, -index, SEEK_END);
      printf("%c", fgetc(p_file));
    }
    printf("\n");
  }

  fclose(p_file);
  p_file = NULL;

  return exit_code;
}