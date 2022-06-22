#ifndef SRC_S21_ERRORS_ERROR_CODES_H_
#define SRC_S21_ERRORS_ERROR_CODES_H_

#ifdef __linux__
#include "linux_error_codes.h"
#endif

#if defined __APPLE__ || defined __MACH__ || defined __OSX__
#include "mach_error_codes.h"
#endif

#endif  // SRC_S21_ERRORS_ERROR_CODES_H_