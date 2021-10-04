#include <stdio.h>
#include <ctype.h>

int main() {
  int exit_code = 0;
  char *original_file_name = "/Users/gbaby/repos/udemy-beginner-c-tutorial/uppercase-all-letters-in-file/file.txt";
  char *temp_file_name = "/Users/gbaby/repos/udemy-beginner-c-tutorial/uppercase-all-letters-in-file/temp_file.txt";
  FILE *p_original_file, *p_temp_file;
  int ch;
  
  p_original_file = fopen(original_file_name, "r");
  p_temp_file = fopen(temp_file_name, "w");
  if(p_original_file == NULL || p_temp_file == NULL) {
    perror("Could not open or create file\n");
    exit_code = -1;
  } else {
    while((ch = fgetc(p_original_file)) != EOF) {
      fputc(islower(ch) ? toupper(ch) : ch, p_temp_file);
    }

    fclose(p_original_file);
    fclose(p_temp_file);
    remove(original_file_name);
    p_original_file = NULL;
    p_temp_file = NULL;
    rename(temp_file_name, original_file_name);

    p_original_file = fopen(original_file_name, "r");
    while((ch = fgetc(p_original_file)) != EOF) {
      printf("%c", ch);
    }

    fclose(p_original_file);
    p_original_file = NULL;
  }

  return exit_code;

}