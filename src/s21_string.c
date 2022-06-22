#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_errors/s21_errlist.h"

// 1
/*
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char ch = (char)c;
  const char *head = str;
  for (; n > 0 && *head != (ch); ++head, --n)
    ;
  return n > 0 ? (void *)head : s21_NULL;
}*/

// 2
/*
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *cstr1 = str1;
  const char *cstr2 = str2;
  for (; n > 0 && *cstr1 == *cstr2; ++cstr1, ++cstr2, --n)
    ;
  return n > 0 ? *cstr1 - *cstr2 : 0;
}*/

// 6
void s21_strcat(char *to, const char *from) {
  for (; *to != '\0'; *to++)
    ;
  while (*to++ = *from++)
    ;
  *to = '\0';
}

// 9
/**
 * @brief compare two c-strings lexicografically
 *
 * @param str1
 * @param str2
 * @return int < 0 if str1 < str2, > 0 if str1 < str 2, zero otherwise
 */
int s21_strcmp(const char *str1, const char *str2) {
  for (; (*str1 != '\0') && ((unsigned char)*str1 == (unsigned char)*str2);
       ++str1, ++str2) {
  }
  return ((unsigned char)*str1 - (unsigned char)*str2);
}

// 10
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int t = n;
  while ((t > 0) && (*str1 != '\0') &&
         ((unsigned char)*str1 == (unsigned char)*str2)) {
    ++str1;
    ++str2;
    --t;
  }

  int res = 0;
  if (n > 0) res = ((unsigned char)*str1 - (unsigned char)*str2);
  return res;
}

// 14
char *s21_strerror(int errnum) {
  /* This string must not be modified by the application */
  return (char *)s21_get_errlist(errnum);
}

// 15
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}


  /** 					**/
 /*	  <antwantu> mem functions	*/
/*				       */

void *s21_memchr(const void *str, int c, s21_size_t n) {
    char ch = (char)c;
    const char *pointer = str;
    while (n > 0 && *pointer != ch) {
      pointer++;
      n--;
}
return n > 0 ? (void *)str: s21_NULL;
}

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const char *cmp_str1 = str1;
    const char *cmp_str2 = str2;
    int res = 0;
    while(n > 0) {
      res += *cmp_str1 - *cmp_str2;
      cmp_str1++;
      cmp_str2++;
      n--;
    }
return res;
}

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *result = dest;
    const char *source = src;
    if ((dest != s21_NULL) &&(source != s21_NULL)) {
      for(; n > 0; n--) {
      *(result++) = *(source++);
      }
    }
return n == 0 ? (void *)dest : s21_NULL;
}

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *result = dest;
    const char *source = src;
    char *temp = (char *)calloc(sizeof(char), n);
    if(temp) {
      for(int i = 0; i < (int)n; i++) {
        *(temp +i) = *(source + i);
      }
      for(int i = 0; n > 0; n--, i++) {
        *(result++) = *(temp + i);
      }
    }
    free(temp);
    return n == 0 ? (void *)dest : s21_NULL;
}

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
    const char ch = (char)c;
    char *pointer = str;
    while(n > 0) {
      *pointer++ = ch;
      n--;
    }
return n == 0 ? (void *)str : s21_NULL;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  const char *tmp1, *tmp2;
  for (tmp1 = str1; *tmp1 != '\0'; ++tmp1) {
    for (tmp2 = str2; *tmp2 != '\0'; ++tmp2) {
      if (*tmp1 == *tmp2) break;
    }
    if (*tmp2 == '\0') break;
    ++length;
  }
  return length > 0 ? length : (s21_size_t)s21_NULL;
}

