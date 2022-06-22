#ifndef SRC_S21_ERRORS_MACH_ERROR_CODES_H_
#define SRC_S21_ERRORS_MACH_ERROR_CODES_H_

#define s21_EPERM 1            /* Operation not permitted. */
#define s21_ENOENT 2           /* No such file or directory. */
#define s21_ESRCH 3            /* No such process. */
#define s21_EINTR 4            /* Interrupted function call. */
#define s21_EIO 5              /* Input/output error. */
#define s21_ENXIO 6            /* No such device or address. */
#define s21_E2BIG 7            /* Arg list too long. */
#define s21_ENOEXEC 8          /* Exec format error. */
#define s21_EBADF 9            /* Bad file descriptor. */
#define s21_ECHILD 10          /* No child processes. */
#define s21_EDEADLK 11         /* Resource deadlock avoided. */
#define s21_ENOMEM 12          /* Cannot allocate memory. */
#define s21_EACCES 13          /* Permission denied. */
#define s21_EFAULT 14          /* Bad address. */
#define s21_ENOTBLK 15         /* Not a block device. */
#define s21_EBUSY 16           /* Resource busy. */
#define s21_EEXIST 17          /* File exists. */
#define s21_EXDEV 18           /* Improper link. */
#define s21_ENODEV 19          /* Operation not supported by device. */
#define s21_ENOTDIR 20         /* Not a directory. */
#define s21_EISDIR 21          /* Is a directory. */
#define s21_EINVAL 22          /* Invalid argument. */
#define s21_ENFILE 23          /* Too many open files in system. */
#define s21_EMFILE 24          /* Too many open files. */
#define s21_ENOTTY 25          /* Inappropriate ioctl for device. */
#define s21_ETXTBSY 26         /* Text file busy. */
#define s21_EFBIG 27           /* File too large. */
#define s21_ENOSPC 28          /* Device out of space. */
#define s21_ESPIPE 29          /* Illegal seek. */
#define s21_EROFS 30           /* Read-only file system. */
#define s21_EMLINK 31          /* Too many links. */
#define s21_EPIPE 32           /* Broken pipe. */
#define s21_EDOM 33            /* Numerical argument out of domain. */
#define s21_ERANGE 34          /* Numerical result out of range. */
#define s21_EAGAIN 35          /* Resource temporarily unavailable. */
#define s21_EINPROGRESS 36     /* Operation now in progress. */
#define s21_EALREADY 37        /* Operation already in progress. */
#define s21_ENOTSOCK 38        /* Socket operation on non-socket. */
#define s21_EDESTADDRREQ 39    /* Destination address required. */
#define s21_EMSGSIZE 40        /* Message too long. */
#define s21_EPROTOTYPE 41      /* Protocol wrong type for socket. */
#define s21_ENOPROTOOPT 42     /* Protocol not available. */
#define s21_EPROTONOSUPPORT 43 /* Protocol not supported. */
#define s21_ESOCKTNOSUPPORT 44 /* Socket type not supported. */
#define s21_ENOTSUP 45         /* Not supported. */
#define s21_EPFNOSUPPORT 46    /* Protocol family not supported. */
#define s21_EAFNOSUPPORT \
  47                      /* Address family not supported by protocol family. */
#define s21_EADDRINUSE 48 /* Address already in use. */
#define s21_EADDRNOTAVAIL 49 /* Cannot assign requested address. */
#define s21_ENETDOWN 50      /* Network is down. */
#define s21_ENETUNREACH 51   /* Network is unreachable. */
#define s21_ENETRESET 52     /* Network dropped connection on reset. */
#define s21_ECONNABORTED 53  /* Software caused connection abort. */
#define s21_ECONNRESET 54    /* Connection reset by peer. */
#define s21_ENOBUFS 55       /* No buffer space available. */
#define s21_EISCONN 56       /* Socket is already connected. */
#define s21_ENOTCONN 57      /* Socket is not connected. */
#define s21_ESHUTDOWN 58     /* Cannot send after socket shutdown. */
#define s21_ETIMEDOUT 60     /* Operation timed out. */
#define s21_ECONNREFUSED 61  /* Connection refused. */
#define s21_ELOOP 62         /* Too many levels of symbolic links. */
#define s21_ENAMETOOLONG 63  /* File name too long. */
#define s21_EHOSTDOWN 64     /* Host is down. */
#define s21_EHOSTUNREACH 65  /* No route to host. */
#define s21_ENOTEMPTY 66     /* Directory not empty. */
#define s21_EPROCLIM 67      /* Too many processes. */
#define s21_EUSERS 68        /* Too many users. */
#define s21_EDQUOT 69        /* Disc quota exceeded. */
#define s21_ESTALE 70        /* Stale NFS file handle. */
#define s21_EBADRPC 72       /* RPC struct is bad. */
#define s21_ERPCMISMATCH 73  /* RPC version wrong. */
#define s21_EPROGUNAVAIL 74  /* RPC prog. not avail. */
#define s21_EPROGMISMATCH 75 /* Program version wrong. */
#define s21_EPROCUNAVAIL 76  /* Bad procedure for program. */
#define s21_ENOLCK 77        /* No locks available. */
#define s21_ENOSYS 78        /* Function not implemented. */
#define s21_EFTYPE 79        /* Inappropriate file type or format. */
#define s21_EAUTH 80         /* Authentication error. */
#define s21_ENEEDAUTH 81     /* Need authenticator. */
#define s21_EPWROFF 82       /* Device power is off. */
#define s21_EDEVERR 83       /* Device error. */
#define s21_EOVERFLOW 84     /* Value too large to be stored in data type. */
#define s21_EBADEXEC 85      /* Bad executable (or shared library). */
#define s21_EBADARCH 86      /* Bad CPU type in executable. */
#define s21_ESHLIBVERS 87    /* Shared library version mismatch. */
#define s21_EBADMACHO 88     /* Malformed Mach-o file. */
#define s21_ECANCELED 89     /* Operation canceled. */
#define s21_EIDRM 90         /* Identifier removed. */
#define s21_ENOMSG 91        /* No message of desired type. */
#define s21_EILSEQ 92        /* Illegal byte sequence. */
#define s21_ENOATTR 93       /* Attribute not found. */
#define s21_EBADMSG 94       /* Bad message. */
#define s21_EMULTIHOP 95     /* Reserved. */
#define s21_ENODATA 96       /* No message available. */
#define s21_ENOLINK 97       /* Reserved. */
#define s21_ENOSR 98         /* No STREAM resources. */
#define s21_ENOSTR 99        /* Not a STREAM. */
#define s21_EPROTO 100       /* Protocol error. */
#define s21_ETIME 101        /* STREAM ioctl() timeout. */
#define s21_EOPNOTSUPP 102   /* Operation not supported on socket. */

#endif  // SRC_S21_ERRORS_MACH_ERROR_CODES_H_