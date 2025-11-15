#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *strLastToken = S21_NULL;
  int error = 0;
  if (str == S21_NULL) {
    str = strLastToken;
  } else {
    strLastToken = str;
  }
  if (str == S21_NULL) {
    error++;
  }
  if (error == 0) {
    while (*str && s21_strpbrk(str, delim) == str) {
      str++;
    }
    if (*str == '\0' && error == 0) {
      error++;
    }
    if (error == 0) {
      char *tokenEnd = s21_strpbrk(str, delim);
      if (!tokenEnd) strLastToken = S21_NULL;
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }
  return str;
}