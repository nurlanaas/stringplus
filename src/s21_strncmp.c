#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int end = 0;
  int res = 0;
  while (n > 0 && end == 0) {
    if ((unsigned char)*str1 == '\0' ||
        (unsigned char)*str1 != (unsigned char)*str2) {
      res = (unsigned char)*str1 - (unsigned char)*str2;
      end = 1;
    }
    n--;
    str1 += 1;
    str2 += 1;
  }
  return res;
}