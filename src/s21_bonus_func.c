#include "s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *upper = (char *)calloc((len + 1), sizeof(char));
  if (upper != S21_NULL) {
    for (size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        upper[i] = str[i] - 32;
      } else {
        upper[i] = str[i];
      }
    }
  }
  return upper;
}

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *lower = (char *)calloc((len + 1), sizeof(char));
  if (lower != S21_NULL) {
    for (size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        lower[i] = str[i] + 32;
      } else {
        lower[i] = str[i];
      }
    }
  }
  return lower;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *buffer = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len + 1;
    if (src_len >= start_index) {
      buffer = (char *)calloc(new_len, sizeof(char));
      if (buffer != NULL) {
        s21_strcpy(buffer, src);
        s21_strcpy(buffer + start_index, str);
        s21_strcpy(buffer + start_index + str_len, src + start_index);
      }
    }
  }
  return buffer;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  if (src != NULL) {
    if (!trim_chars) {
      trim_chars = " ";
    }
    char *trim_start = (char *)src;
    char *trim_end = (char *)src + s21_strlen(src);
    for (; *trim_start && s21_strchr(trim_chars, *trim_start); trim_start++);
    for (; trim_end != trim_start && s21_strchr(trim_chars, *(trim_end - 1));
         trim_end--);
    s21_size_t trim_len = trim_end - trim_start;
    res = (char *)calloc(trim_len + 1, sizeof(char));
    if (res != NULL) {
      s21_strncpy(res, trim_start, trim_len);
      *(res + trim_len) = '\0';
    }
  }
  return res;
}