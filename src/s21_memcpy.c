#include "s21_string.h"

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *s1 = (char *)dest;
  const char *s2 = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) *s1++ = *s2++;
  return dest;
}