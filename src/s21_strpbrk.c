#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  char *res = S21_NULL;
  int flag = 0;
  for (s21_size_t i = 0; (i < str1_len) && (flag == 0); i++) {
    for (s21_size_t j = 0; (j < str2_len) && (flag == 0); j++) {
      if (str1[i] == str2[j]) {
        res = (char *)(str1 + i);
        flag = 1;
      }
    }
  }
  return res;
}