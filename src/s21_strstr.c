#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  int flagNull = 0;
  if (!needle[0]) {
    res = (char *)haystack;
    flagNull = 1;
  }
  if (flagNull == 0) {
    for (s21_size_t i = 0; res == S21_NULL && haystack[i] != '\0'; i++) {
      s21_size_t j = 0;
      while (haystack[i + j] == needle[j] && needle[j] != '\0') j++;
      if (needle[j] == '\0') res = (char *)&haystack[i];
    }
  }
  return res;
}