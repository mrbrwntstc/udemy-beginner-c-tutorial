#include <stdio.h>
#include <stdbool.h>

int string_length(const char string[]);
void concatenate_string(char result[], const char str1[], const char str2[]);
bool string_equals(const char str1[], const char str2[]);


int main() {
  const char string1[] = "Hello";
  const char string2[] = "World!";

  printf("\"%s\" contains 5 characters: %s\n", string1, string_length(string1) == 5 ? "Yes" : "No");
  printf("\"%s\" contains 5 characters: %s\n", string2, string_length(string2) == 5 ? "Yes" : "No");
  printf("NULL should have 0 character length: %s\n", string_length(NULL) == 0 ? "Yes" : "No");

  char concatenated_string[80];
  concatenate_string(concatenated_string, string1, string2);
  printf("\"%s\" concatenated with \"%s\" makes \"%s\"\n", string1, string2, concatenated_string);

  concatenate_string(concatenated_string, string1, NULL);
  printf("\"%s\" concatenated with NULL makes \"%s\"\n", string1, concatenated_string);

  concatenate_string(concatenated_string, NULL, string2);
  printf("NULL concatenated with \"%s\" makes \"%s\"\n", string2, concatenated_string);

  concatenate_string(concatenated_string, NULL, NULL);
  printf("NULL concatenated with NULL makes \"%s\"\n", concatenated_string);

  printf("NULL is not equal to \"%s\": %s\n", string1, !(string_equals(NULL, string1) || string_equals(string1, NULL)) ? "Yes" : "No");

  printf("string_equals is reflexive: %s\n", string_equals(string2, string2) && string_equals(NULL, NULL) ? "Yes" : "No");
  printf("string_equals is symmetric: %s\n", !(string_equals(string1,string2) || string_equals(string2, string1)) ? "Yes" : "No");
  printf("string_equals should compare two empty strings correctly: %s\n", string_equals("","") ? "Yes" : "No");
  printf("string_equals should compare empty and non-empty string correctly: %s\n", !(string_equals("", string1) || string_equals(string1, "")) ? "Yes" : "No");
}

int string_length(const char string[]) {
  int length = 0;

  if(string != NULL) {
    for(int i = 0; string[i] != '\0'; ++i) {
      length++;
    }
  }

  return length;
}

/**
 * @brief append string2 to string1 and put it in result
 * 
 * @param result  the string that contains string1 and string2 concatenated
 * @param string1 the string to append to
 * @param string2 the string to append
 */
void concatenate_string(char result[], const char string1[], const char string2[]) {
  int result_length = 0;

  if(string1 != NULL) {
    for(int i = 0; string1[i] != '\0'; ++i) {
      result[result_length++] = string1[i];
    }
  }

  if(string2 != NULL) {
    for(int i = 0; string2[i] != '\0'; ++i) {
      result[result_length++] = string2[i];
    }
  }

  result[result_length] = '\0';
}

/**
 * @brief Check if two strings have the same content
 * 
 * @param string1 can be NULL
 * @param string2 can be NULL
 * @return true   both strings are NULL or contain the same content
 * @return false  strings do not match
 */
bool string_equals(const char string1[], const char string2[]) {
  bool strings_are_equal = true;

  if((string1 != NULL) && (string2 != NULL)) {
    if(((string1 == NULL) && (string2 != NULL)) || (string1 != NULL) && (string2 == NULL)) {
      // if either string is null and the other is not null, then the strings are not equal
      strings_are_equal = false;
    } else {
      for(int i = 0; ((string1[i] != '\0') || (string2[i] != '\0')) && strings_are_equal; ++i) {
        strings_are_equal = (string1[i] == string2[i]);
      }
    }
  }

  return strings_are_equal;
}
