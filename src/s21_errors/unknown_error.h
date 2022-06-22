#ifndef SRC_S21_ERRORS_MACH_ERROR_MSGS_H_
#define SRC_S21_ERRORS_MACH_ERROR_MSGS_H_

#include "../utils/write_int_into_str_buffer.h"

#ifdef __linux__
char s21_unknown_error[32] = {"Unknown error "};
int s21_unkerrmsg_len = 14;
#endif
#if defined __APPLE__ || defined __MACH__ || defined __OSX__
char s21_unknown_error[32] = {"Unknown error: "};
int s21_unkerrmsg_len = 15;
#endif

char *unknown_error_msg(int unknown_errno) {
  write_int(s21_unknown_error + s21_unkerrmsg_len, unknown_errno);
  return s21_unknown_error;
}

#endif /* SRC_S21_ERRORS_MACH_ERROR_MSGS_H_ */