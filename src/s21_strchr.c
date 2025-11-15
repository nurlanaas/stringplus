#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в
// строке, на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  char temp = (char)c;
  while (*str && *str != temp) str++;
  if (*str == temp) res = (char *)str;
  return res;
}