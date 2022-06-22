#include "../s21_null_and_size_t.h"
#include "linux_error_codes.h"
#include "unknown_error.h"

char const* const s21_get_errlist(int errenum) {
  static char const* const s21_errlist_internal[] = {
#ifdef __linux__
#include "linux_error_msgs.h"
#endif
#if defined __APPLE__ || defined __MACH__ || defined __OSX__
#include "mach_error_msgs.h"
#endif
  };

  char* result = s21_NULL;
  if (errenum >= 0 &&
      errenum < sizeof(s21_errlist_internal) / sizeof(char const* const)) {
    /* if errnum is not in array result == NULL */
    result = (char*)s21_errlist_internal[errenum];
  }

  if (result == s21_NULL) {
    result = unknown_error_msg(errenum);
  }
  return result;
}