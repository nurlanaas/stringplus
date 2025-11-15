#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который
// полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int end = 0;
  int res = 0;
  while (*str1 != '\0' && end == 0) {
    for (const char *p = str2; *p != '\0'; p++) {
      if (*str1 == *p) {
        end = 1;
      }
    }
    if (end == 0) {
      res++;
    }
    str1++;
  }
  return res;
}