#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "errlist.h"

void s21_itoa(int m, char *str) {
  if (m < 0) {
    m = abs(m);
    int power = 0, j = 0;
    j = m;
    for (power = 1; j >= 10; j /= 10) power = power * 10;
    *str++ = '-';
    for (; power > 0; power /= 10) {
      *str++ = '0' + m / power;
      m %= power;
    }
    *str = '\0';
  } else {
    int power = 0, j = 0;
    j = m;
    for (power = 1; j >= 10; j /= 10) power *= 10;

    for (; power > 0; power /= 10) {
      *str++ = '0' + m / power;
      m %= power;
    }
    *str = '\0';
  }
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *result = s21_NULL;
  for (s21_size_t count = 0; count < n; count++) {
    if (*((char *)str + count) == c) {
      result = (char *)str + count;
      break;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t count = 0; count < n; count++) {
    if (*((char *)str1 + count) == *((char *)str2 + count)) {
      result = 0;
    } else if (*((char *)str1 + count) >= *((char *)str2 + count)) {
      result = 1;
      break;
    } else if (*((char *)str1 + count) <= *((char *)str2 + count)) {
      result = -1;
      break;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (char *p = (char *)dest, *q = (char *)src; n > 0; n--, p++, q++) *p = *q;
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  void *ret = dest;
  if (dest <= src || (char *)dest >= ((char *)src + n)) {
    while (n--) {
      *(char *)dest = *(char *)src;
      dest = (char *)dest + 1;
      src = (char *)src + 1;
    }
  } else {
    dest = (char *)dest + n - 1;
    src = (char *)src + n - 1;
    while (n--) {
      *(char *)dest = *(char *)src;
      dest = (char *)dest - 1;
      src = (char *)src - 1;
    }
  }
  return ret;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (char *p = (char *)str; n > 0; n--, p++) *p = c;
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *tmp = dest;
  while (*dest) dest++;
  while (*src) *dest++ = *src++;
  *dest = '\0';
  return tmp;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest + s21_strlen(dest);
  for (const char *q = src; n > 0; n--, q++, p++) *p = *q;
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *temp = s21_NULL;
  if (str) {
    while (*str) {
      if (*str == c) {
        temp = (char *)(str);
        break;
      } else {
        str++;
      }
    }
  }
  if (c == '\0') {
    temp = (char *)(str);
  }
  return temp;
}

int s21_strcmp(const char *str1, const char *str2) {
  while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

int s21_strncmp(const char *str_1, const char *str_2, s21_size_t n) {
  int r = 0;
  while (n-- && r == 0)
    if (*str_1++ != *str_2++) r = *(str_1 - 1) - *(str_2 - 1);
  return r;
}

char *s21_strcpy(char *dest, const char *src) {
  int count = 0;
  for (char *p = (char *)dest, *q = (char *)src; *q != '\0'; p++, q++, count++)
    *p = *q;
  dest[count] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t size = s21_strlen(src);
  char *p = dest;
  if (size > n) {
    s21_memcpy(p, src, n);
  } else {
    s21_memcpy(p, src, size);
    int offset = n - size;
    char *q = p + size;
    while (offset--) *q++ = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int n;
  for (n = 0; *str1; str1++, n++)
    if (s21_strchr(str2, *str1) != s21_NULL) break;
  return n;
}

char *s21_strerror(int errnum) {
  static char *str[] = ERRORS;
  int max;
  char error[4096] = {'\0'};
  char stt[10];
  static char strr[4096] = {'\0'};
  for (int i = 0; i < 4096; i++) strr[i] = '\0';
#if defined(__APPLE__) && defined(__MACH__)
  max = 106;
#else
  max = 133;
#endif
  if (errnum > max || errnum < 0) {
    s21_itoa(errnum, stt);
    if (max == 133)
      s21_strcpy(error, "Unknown error ");
    else if (max == 106)
      s21_strcpy(error, "Unknown error: ");
    s21_strncat(error, stt, s21_strlen(error));
  } else {
    s21_strcat(error, str[errnum]);
  }
  s21_strcat(strr, error);
  return strr;
}

s21_size_t s21_strlen(const char *str) {
  const char *sc = str;
  while (*sc != '\0') sc++;
  return sc - str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *temp = s21_NULL;
  while (*str1) {
    if (s21_strchr(str2, *str1++)) {
      temp = (char *)(str1 - 1);
      break;
    }
  }
  return temp;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  if (c == '\0') {
    for (s21_size_t count = 0; count < s21_strlen(str) + 1; count++)
      if (*((char *)str + count) == c) result = (char *)str + count;
  }
  for (s21_size_t count = 0; count < s21_strlen(str); count++)
    if (*((char *)str + count) == c) result = (char *)str + count;
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t size = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1++)) {
      size++;
    } else {
      break;
    }
  }
  return size;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *p = s21_NULL;
  while (*haystack && !p) {
    char *start = (char *)haystack;
    char *n = (char *)needle;
    while (*haystack && *n && *haystack == *n) {
      haystack++;
      n++;
    }
    if (!*n) {
      p = start;
    }
    haystack = start + 1;
  }
  return p;
}

char *s21_strtok(char *str, const char *delim) {
  static char *buffer;
  if (str != s21_NULL) {
    buffer = str;
  }
  if (buffer[0] == '\0') {
    return s21_NULL;
  }
  char *ret = buffer, *b;
  const char *d;
  for (b = buffer; *b != '\0'; b++) {
    for (d = delim; *d != '\0'; d++) {
      if (*b == *d) {
        *b = '\0';
        buffer = b + 1;
        if (b == ret) {
          ret++;
          continue;
        }
        return ret;
      }
    }
  }
  return ret;
}

void *s21_to_upper(const char *str) {
  static char *buffer;
  buffer = malloc(s21_strlen(str));
  void *pt = s21_NULL;
  s21_size_t len = s21_strlen(str) + 1;
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      buffer[i] = str[i] - 32;
    else
      buffer[i] = str[i];
  }
  buffer[len] = '\0';
  pt = (void *)buffer;
  return pt;
}

void *s21_to_lower(const char *str) {
  static char *buffer;
  buffer = malloc(s21_strlen(str));
  void *pt = s21_NULL;
  s21_size_t len = s21_strlen(str) + 1;
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      buffer[i] = str[i] + 32;
    else
      buffer[i] = str[i];
  }
  buffer[len] = '\0';
  pt = (void *)buffer;
  return pt;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  static char *buffer;
  void *pt = s21_NULL;
  int flag = 0;
  int end_p = s21_strlen(src) + s21_strlen(str);
  if (s21_strlen(src) >= start_index) {
    buffer = malloc(end_p);
    for (s21_size_t i = 0; i < start_index; i++) {
      buffer[i] = src[i];
      flag++;
    }
    for (s21_size_t i = start_index; i < end_p + start_index; i++) {
      buffer[i] = str[i - start_index];
    }
    for (s21_size_t i = s21_strlen(str) + flag; i < end_p + start_index; i++) {
      buffer[i] = src[i - s21_strlen(str)];
    }
    buffer[end_p] = '\0';
    pt = (void *)buffer;
  }
  return pt;
}

void *s21_trim(const char *src, const char *trim_chars) {
  int i;
  static char *buffer;
  buffer = malloc(s21_strlen(src));
  void *pt = s21_NULL;
  s21_strcpy(buffer, src);
  for (i = s21_strlen(buffer) - 1;
       i >= 0 && s21_strchr(trim_chars, buffer[i]) != s21_NULL; i--) {
    buffer[i] = '\0';
  }
  while (buffer[0] != '\0' && s21_strchr(trim_chars, buffer[0]) != s21_NULL) {
    s21_memmove(&buffer[0], &buffer[1], s21_strlen(buffer));
  }
  pt = buffer;
  return pt;
}
