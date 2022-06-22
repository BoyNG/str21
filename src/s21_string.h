#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include "s21_null_and_size_t.h"

// 1
void *s21_memchr(const void *str, int c, s21_size_t n);
// 2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

// 6
void s21_strcat(char *to, const char *from);
// 9
int s21_strcmp(const char *str1, const char *str2);
// 10
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
// 14
char *s21_strerror(int errnum);
// 15
s21_size_t s21_strlen(const char *str);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memmove(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);

s21_size_t s21_strspn(const char *str1, const char *str2);

#endif  // SRC_S21_STRING_H_
