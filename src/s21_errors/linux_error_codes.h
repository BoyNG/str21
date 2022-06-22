#ifndef SRC_S21_ERRORS_LINUX_ERROR_CODES_H_
#define SRC_S21_ERRORS_LINUX_ERROR_CODES_H_

#define s21_ZERO_ERROR 0    /* Success */
#define s21_EPERM 1         /* Operation not permitted */
#define s21_EPERM 1         /* Operation not permitted */
#define s21_ENOENT 2        /* No such file or directory */
#define s21_ESRCH 3         /* No such process */
#define s21_EINTR 4         /* Interrupted system call */
#define s21_EIO 5           /* Input/output error */
#define s21_ENXIO 6         /* No such device or address */
#define s21_E2BIG 7         /* Argument list too long */
#define s21_ENOEXEC 8       /* Exec format error */
#define s21_EBADF 9         /* Bad file descriptor */
#define s21_ECHILD 10       /* No child processes */
#define s21_EAGAIN 11       /* Resource temporarily unavailable */
#define s21_ENOMEM 12       /* Cannot allocate memory */
#define s21_EACCES 13       /* Permission denied */
#define s21_EFAULT 14       /* Bad address */
#define s21_ENOTBLK 15      /* Block device required */
#define s21_EBUSY 16        /* Device or resource busy */
#define s21_EEXIST 17       /* File exists */
#define s21_EXDEV 18        /* Invalid cross-device link */
#define s21_ENODEV 19       /* No such device */
#define s21_ENOTDIR 20      /* Not a directory */
#define s21_EISDIR 21       /* Is a directory */
#define s21_EINVAL 22       /* Invalid argument */
#define s21_ENFILE 23       /* Too many open files in system */
#define s21_EMFILE 24       /* Too many open files */
#define s21_ENOTTY 25       /* Inappropriate ioctl for device */
#define s21_ETXTBSY 26      /* Text file busy */
#define s21_EFBIG 27        /* File too large */
#define s21_ENOSPC 28       /* No space left on device */
#define s21_ESPIPE 29       /* Illegal seek */
#define s21_EROFS 30        /* Read-only file system */
#define s21_EMLINK 31       /* Too many links */
#define s21_EPIPE 32        /* Broken pipe */
#define s21_EDOM 33         /* Numerical argument out of domain */
#define s21_ERANGE 34       /* Numerical result out of range */
#define s21_EDEADLK 35      /* Resource deadlock avoided */
#define s21_ENAMETOOLONG 36 /* File name too long */
#define s21_ENOLCK 37       /* No locks available */
#define s21_ENOSYS 38       /* Function not implemented */
#define s21_ENOTEMPTY 39    /* Directory not empty */
#define s21_ELOOP 40        /* Too many levels of symbolic links */
#define s21_EWOULDBLOCK 11  /* Resource temporarily unavailable */
#define s21_ENOMSG 42       /* No message of desired type */
#define s21_EIDRM 43        /* Identifier removed */
#define s21_ECHRNG 44       /* Channel number out of range */
#define s21_EL2NSYNC 45     /* Level 2 not synchronized */
#define s21_EL3HLT 46       /* Level 3 halted */
#define s21_EL3RST 47       /* Level 3 reset */
#define s21_ELNRNG 48       /* Link number out of range */
#define s21_EUNATCH 49      /* Protocol driver not attached */
#define s21_ENOCSI 50       /* No CSI structure available */
#define s21_EL2HLT 51       /* Level 2 halted */
#define s21_EBADE 52        /* Invalid exchange */
#define s21_EBADR 53        /* Invalid request descriptor */
#define s21_EXFULL 54       /* Exchange full */
#define s21_ENOANO 55       /* No anode */
#define s21_EBADRQC 56      /* Invalid request code */
#define s21_EBADSLT 57      /* Invalid slot */
#define s21_EDEADLOCK 35    /* Resource deadlock avoided */
#define s21_EBFONT 59       /* Bad font file format */
#define s21_ENOSTR 60       /* Device not a stream */
#define s21_ENODATA 61      /* No data available */
#define s21_ETIME 62        /* Timer expired */
#define s21_ENOSR 63        /* Out of streams resources */
#define s21_ENONET 64       /* Machine is not on the network */
#define s21_ENOPKG 65       /* Package not installed */
#define s21_EREMOTE 66      /* Object is remote */
#define s21_ENOLINK 67      /* Link has been severed */
#define s21_EADV 68         /* Advertise error */
#define s21_ESRMNT 69       /* Srmount error */
#define s21_ECOMM 70        /* Communication error on send */
#define s21_EPROTO 71       /* Protocol error */
#define s21_EMULTIHOP 72    /* Multihop attempted */
#define s21_EDOTDOT 73      /* RFS specific error */
#define s21_EBADMSG 74      /* Bad message */
#define s21_EOVERFLOW 75    /* Value too large for defined data type */
#define s21_ENOTUNIQ 76     /* Name not unique on network */
#define s21_EBADFD 77       /* File descriptor in bad state */
#define s21_EREMCHG 78      /* Remote address changed */
#define s21_ELIBACC 79      /* Can not access a needed shared library */
#define s21_ELIBBAD 80      /* Accessing a corrupted shared library */
#define s21_ELIBSCN 81      /* .lib section in a.out corrupted */
#define s21_ELIBMAX 82  /* Attempting to link in too many shared libraries */
#define s21_ELIBEXEC 83 /* Cannot exec a shared library directly */
#define s21_EILSEQ 84   /* Invalid or incomplete multibyte or wide character */
#define s21_ERESTART 85 /* Interrupted system call should be restarted */
#define s21_ESTRPIPE 86 /* Streams pipe error */
#define s21_EUSERS 87   /* Too many users */
#define s21_ENOTSOCK 88 /* Socket operation on non-socket */
#define s21_EDESTADDRREQ 89    /* Destination address required */
#define s21_EMSGSIZE 90        /* Message too long */
#define s21_EPROTOTYPE 91      /* Protocol wrong type for socket */
#define s21_ENOPROTOOPT 92     /* Protocol not available */
#define s21_EPROTONOSUPPORT 93 /* Protocol not supported */
#define s21_ESOCKTNOSUPPORT 94 /* Socket type not supported */
#define s21_EOPNOTSUPP 95      /* Operation not supported */
#define s21_EPFNOSUPPORT 96    /* Protocol family not supported */
#define s21_EAFNOSUPPORT 97    /* Address family not supported by protocol */
#define s21_EADDRINUSE 98      /* Address already in use */
#define s21_EADDRNOTAVAIL 99   /* Cannot assign requested address */
#define s21_ENETDOWN 100       /* Network is down */
#define s21_ENETUNREACH 101    /* Network is unreachable */
#define s21_ENETRESET 102      /* Network dropped connection on reset */
#define s21_ECONNABORTED 103   /* Software caused connection abort */
#define s21_ECONNRESET 104     /* Connection reset by peer */
#define s21_ENOBUFS 105        /* No buffer space available */
#define s21_EISCONN 106        /* Transport endpoint is already connected */
#define s21_ENOTCONN 107       /* Transport endpoint is not connected */
#define s21_ESHUTDOWN 108    /* Cannot send after transport endpoint shutdown */
#define s21_ETOOMANYREFS 109 /* Too many references: cannot splice */
#define s21_ETIMEDOUT 110    /* Connection timed out */
#define s21_ECONNREFUSED 111 /* Connection refused */
#define s21_EHOSTDOWN 112    /* Host is down */
#define s21_EHOSTUNREACH 113 /* No route to host */
#define s21_EALREADY 114     /* Operation already in progress */
#define s21_EINPROGRESS 115  /* Operation now in progress */
#define s21_ESTALE 116       /* Stale file handle */
#define s21_EUCLEAN 117      /* Structure needs cleaning */
#define s21_ENOTNAM 118      /* Not a XENIX named type file */
#define s21_ENAVAIL 119      /* No XENIX semaphores available */
#define s21_EISNAM 120       /* Is a named type file */
#define s21_EREMOTEIO 121    /* Remote I/O error */
#define s21_EDQUOT 122       /* Disk quota exceeded */
#define s21_ENOMEDIUM 123    /* No medium found */
#define s21_EMEDIUMTYPE 124  /* Wrong medium type */
#define s21_ECANCELED 125    /* Operation canceled */
#define s21_ENOKEY 126       /* Required key not available */
#define s21_EKEYEXPIRED 127  /* Key has expired */
#define s21_EKEYREVOKED 128  /* Key has been revoked */
#define s21_EKEYREJECTED 129 /* Key was rejected by service */
#define s21_EOWNERDEAD 130   /* Owner died */
#define s21_ENOTRECOVERABLE 131 /* State not recoverable */
#define s21_ERFKILL 132         /* Operation not possible due to RF-kill */
#define s21_EHWPOISON 133       /* Memory page has hardware error */
#define s21_ENOTSUP 95          /* Operation not supported */

#endif  // SRC_S21_ERRORS_LINUX_ERROR_CODES_H_