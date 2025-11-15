#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t len = s21_strlen(str);
  char *res = S21_NULL;
  s21_size_t i = 0;
  for (; i < len; i++) {
    if (str[i] == c) res = (char *)str + i;
  }
  if (c == '\0') res = (char *)str + i;
  return res;
}