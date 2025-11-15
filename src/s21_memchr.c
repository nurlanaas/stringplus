#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *ptr = (const char *)str;
  unsigned char c1 = (unsigned char)c;
  int flag = 0;
  void *result = S21_NULL;
  for (s21_size_t i = 0; i < n && !flag; i++, ptr++) {
    if (*ptr == c1) {
      result = (void *)ptr;
      flag = 1;
    }
  }
  return result;
}