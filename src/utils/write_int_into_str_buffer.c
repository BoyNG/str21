#include "write_int_into_str_buffer.h"

/* for positive pow */
int ten_pow_positive(int pow) {
  int n = 1;
  while (pow > 0) {
    n *= 10;
    --pow;
  }
  return n;
}

/* for positive n */
int cont_digits_positive(int n) {
  int res = 0;
  do {
    ++res;
    n /= 10;
  } while (n > 0);

  return res;
}

/* write num into buff */
void write_int(char* buff, int num) {
  const int ASCII_ZERO = 48;
  if (num < 0) {
    *buff++ = '-';
    num = -num;
  }

  int nlen = cont_digits_positive(num);
  int tenp = ten_pow_positive(nlen);
  while (tenp > 1) {
    int digit = (num % tenp) / (tenp / 10);
    *buff++ = (char)(ASCII_ZERO + digit);
    tenp /= 10;
  }
  *buff = '\0';
}