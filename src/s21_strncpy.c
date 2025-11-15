#include "s21_string.h"

// Копирует до n символов из строки, на
// которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  s21_size_t i = 0;
  int end = 0;
  while (i < n && end == 0) {
    if (src[i] == '\0') {
      p[i] = src[i];
      end = 1;
    }
    p[i] = src[i];
    i++;
  }
  if (i < n - 1) {
    for (; i < n; i++) {
      p[i] = 0;
    }
  }
  return dest;
}