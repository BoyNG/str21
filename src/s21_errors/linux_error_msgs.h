#ifndef SRC_S21_ERRORS_LINUX_ERROR_MSGS_H_
#define SRC_S21_ERRORS_LINUX_ERROR_MSGS_H_

#ifdef s21_ZERO_ERROR
[s21_ZERO_ERROR] = "Success",
#endif
#ifdef s21_EPERM
    [s21_EPERM] = "Operation not permitted",
#endif
#ifdef s21_ENOENT
    [s21_ENOENT] = "No such file or directory",
#endif
#ifdef s21_ESRCH
    [s21_ESRCH] = "No such process",
#endif
#ifdef s21_EINTR
    [s21_EINTR] = "Interrupted system call",
#endif
#ifdef s21_EIO
    [s21_EIO] = "Input/output error",
#endif
#ifdef s21_ENXIO
    [s21_ENXIO] = "No such device or address",
#endif
#ifdef s21_E2BIG
    [s21_E2BIG] = "Argument list too long",
#endif
#ifdef s21_ENOEXEC
    [s21_ENOEXEC] = "Exec format error",
#endif
#ifdef s21_EBADF
    [s21_EBADF] = "Bad file descriptor",
#endif
#ifdef s21_ECHILD
    [s21_ECHILD] = "No child processes",
#endif
#ifdef s21_EAGAIN
    [s21_EAGAIN] = "Resource temporarily unavailable",
#endif
#ifdef s21_ENOMEM
    [s21_ENOMEM] = "Cannot allocate memory",
#endif
#ifdef s21_EACCES
    [s21_EACCES] = "Permission denied",
#endif
#ifdef s21_EFAULT
    [s21_EFAULT] = "Bad address",
#endif
#ifdef s21_ENOTBLK
    [s21_ENOTBLK] = "Block device required",
#endif
#ifdef s21_EBUSY
    [s21_EBUSY] = "Device or resource busy",
#endif
#ifdef s21_EEXIST
    [s21_EEXIST] = "File exists",
#endif
#ifdef s21_EXDEV
    [s21_EXDEV] = "Invalid cross-device link",
#endif
#ifdef s21_ENODEV
    [s21_ENODEV] = "No such device",
#endif
#ifdef s21_ENOTDIR
    [s21_ENOTDIR] = "Not a directory",
#endif
#ifdef s21_EISDIR
    [s21_EISDIR] = "Is a directory",
#endif
#ifdef s21_EINVAL
    [s21_EINVAL] = "Invalid argument",
#endif
#ifdef s21_ENFILE
    [s21_ENFILE] = "Too many open files in system",
#endif
#ifdef s21_EMFILE
    [s21_EMFILE] = "Too many open files",
#endif
#ifdef s21_ENOTTY
    [s21_ENOTTY] = "Inappropriate ioctl for device",
#endif
#ifdef s21_ETXTBSY
    [s21_ETXTBSY] = "Text file busy",
#endif
#ifdef s21_EFBIG
    [s21_EFBIG] = "File too large",
#endif
#ifdef s21_ENOSPC
    [s21_ENOSPC] = "No space left on device",
#endif
#ifdef s21_ESPIPE
    [s21_ESPIPE] = "Illegal seek",
#endif
#ifdef s21_EROFS
    [s21_EROFS] = "Read-only file system",
#endif
#ifdef s21_EMLINK
    [s21_EMLINK] = "Too many links",
#endif
#ifdef s21_EPIPE
    [s21_EPIPE] = "Broken pipe",
#endif
#ifdef s21_EDOM
    [s21_EDOM] = "Numerical argument out of domain",
#endif
#ifdef s21_ERANGE
    [s21_ERANGE] = "Numerical result out of range",
#endif
#ifdef s21_EDEADLK
    [s21_EDEADLK] = "Resource deadlock avoided",
#endif
#ifdef s21_ENAMETOOLONG
    [s21_ENAMETOOLONG] = "File name too long",
#endif
#ifdef s21_ENOLCK
    [s21_ENOLCK] = "No locks available",
#endif
#ifdef s21_ENOSYS
    [s21_ENOSYS] = "Function not implemented",
#endif
#ifdef s21_ENOTEMPTY
    [s21_ENOTEMPTY] = "Directory not empty",
#endif
#ifdef s21_ELOOP
    [s21_ELOOP] = "Too many levels of symbolic links",
#endif
#ifdef s21_EWOULDBLOCK
    [s21_EWOULDBLOCK] = "Resource temporarily unavailable",
#endif
#ifdef s21_ENOMSG
    [s21_ENOMSG] = "No message of desired type",
#endif
#ifdef s21_EIDRM
    [s21_EIDRM] = "Identifier removed",
#endif
#ifdef s21_ECHRNG
    [s21_ECHRNG] = "Channel number out of range",
#endif
#ifdef s21_EL2NSYNC
    [s21_EL2NSYNC] = "Level 2 not synchronized",
#endif
#ifdef s21_EL3HLT
    [s21_EL3HLT] = "Level 3 halted",
#endif
#ifdef s21_EL3RST
    [s21_EL3RST] = "Level 3 reset",
#endif
#ifdef s21_ELNRNG
    [s21_ELNRNG] = "Link number out of range",
#endif
#ifdef s21_EUNATCH
    [s21_EUNATCH] = "Protocol driver not attached",
#endif
#ifdef s21_ENOCSI
    [s21_ENOCSI] = "No CSI structure available",
#endif
#ifdef s21_EL2HLT
    [s21_EL2HLT] = "Level 2 halted",
#endif
#ifdef s21_EBADE
    [s21_EBADE] = "Invalid exchange",
#endif
#ifdef s21_EBADR
    [s21_EBADR] = "Invalid request descriptor",
#endif
#ifdef s21_EXFULL
    [s21_EXFULL] = "Exchange full",
#endif
#ifdef s21_ENOANO
    [s21_ENOANO] = "No anode",
#endif
#ifdef s21_EBADRQC
    [s21_EBADRQC] = "Invalid request code",
#endif
#ifdef s21_EBADSLT
    [s21_EBADSLT] = "Invalid slot",
#endif
#ifdef s21_EDEADLOCK
    [s21_EDEADLOCK] = "Resource deadlock avoided",
#endif
#ifdef s21_EBFONT
    [s21_EBFONT] = "Bad font file format",
#endif
#ifdef s21_ENOSTR
    [s21_ENOSTR] = "Device not a stream",
#endif
#ifdef s21_ENODATA
    [s21_ENODATA] = "No data available",
#endif
#ifdef s21_ETIME
    [s21_ETIME] = "Timer expired",
#endif
#ifdef s21_ENOSR
    [s21_ENOSR] = "Out of streams resources",
#endif
#ifdef s21_ENONET
    [s21_ENONET] = "Machine is not on the network",
#endif
#ifdef s21_ENOPKG
    [s21_ENOPKG] = "Package not installed",
#endif
#ifdef s21_EREMOTE
    [s21_EREMOTE] = "Object is remote",
#endif
#ifdef s21_ENOLINK
    [s21_ENOLINK] = "Link has been severed",
#endif
#ifdef s21_EADV
    [s21_EADV] = "Advertise error",
#endif
#ifdef s21_ESRMNT
    [s21_ESRMNT] = "Srmount error",
#endif
#ifdef s21_ECOMM
    [s21_ECOMM] = "Communication error on send",
#endif
#ifdef s21_EPROTO
    [s21_EPROTO] = "Protocol error",
#endif
#ifdef s21_EMULTIHOP
    [s21_EMULTIHOP] = "Multihop attempted",
#endif
#ifdef s21_EDOTDOT
    [s21_EDOTDOT] = "RFS specific error",
#endif
#ifdef s21_EBADMSG
    [s21_EBADMSG] = "Bad message",
#endif
#ifdef s21_EOVERFLOW
    [s21_EOVERFLOW] = "Value too large for defined data type",
#endif
#ifdef s21_ENOTUNIQ
    [s21_ENOTUNIQ] = "Name not unique on network",
#endif
#ifdef s21_EBADFD
    [s21_EBADFD] = "File descriptor in bad state",
#endif
#ifdef s21_EREMCHG
    [s21_EREMCHG] = "Remote address changed",
#endif
#ifdef s21_ELIBACC
    [s21_ELIBACC] = "Can not access a needed shared library",
#endif
#ifdef s21_ELIBBAD
    [s21_ELIBBAD] = "Accessing a corrupted shared library",
#endif
#ifdef s21_ELIBSCN
    [s21_ELIBSCN] = ".lib section in a.out corrupted",
#endif
#ifdef s21_ELIBMAX
    [s21_ELIBMAX] = "Attempting to link in too many shared libraries",
#endif
#ifdef s21_ELIBEXEC
    [s21_ELIBEXEC] = "Cannot exec a shared library directly",
#endif
#ifdef s21_EILSEQ
    [s21_EILSEQ] = "Invalid or incomplete multibyte or wide character",
#endif
#ifdef s21_ERESTART
    [s21_ERESTART] = "Interrupted system call should be restarted",
#endif
#ifdef s21_ESTRPIPE
    [s21_ESTRPIPE] = "Streams pipe error",
#endif
#ifdef s21_EUSERS
    [s21_EUSERS] = "Too many users",
#endif
#ifdef s21_ENOTSOCK
    [s21_ENOTSOCK] = "Socket operation on non-socket",
#endif
#ifdef s21_EDESTADDRREQ
    [s21_EDESTADDRREQ] = "Destination address required",
#endif
#ifdef s21_EMSGSIZE
    [s21_EMSGSIZE] = "Message too long",
#endif
#ifdef s21_EPROTOTYPE
    [s21_EPROTOTYPE] = "Protocol wrong type for socket",
#endif
#ifdef s21_ENOPROTOOPT
    [s21_ENOPROTOOPT] = "Protocol not available",
#endif
#ifdef s21_EPROTONOSUPPORT
    [s21_EPROTONOSUPPORT] = "Protocol not supported",
#endif
#ifdef s21_ESOCKTNOSUPPORT
    [s21_ESOCKTNOSUPPORT] = "Socket type not supported",
#endif
#ifdef s21_EOPNOTSUPP
    [s21_EOPNOTSUPP] = "Operation not supported",
#endif
#ifdef s21_EPFNOSUPPORT
    [s21_EPFNOSUPPORT] = "Protocol family not supported",
#endif
#ifdef s21_EAFNOSUPPORT
    [s21_EAFNOSUPPORT] = "Address family not supported by protocol",
#endif
#ifdef s21_EADDRINUSE
    [s21_EADDRINUSE] = "Address already in use",
#endif
#ifdef s21_EADDRNOTAVAIL
    [s21_EADDRNOTAVAIL] = "Cannot assign requested address",
#endif
#ifdef s21_ENETDOWN
    [s21_ENETDOWN] = "Network is down",
#endif
#ifdef s21_ENETUNREACH
    [s21_ENETUNREACH] = "Network is unreachable",
#endif
#ifdef s21_ENETRESET
    [s21_ENETRESET] = "Network dropped connection on reset",
#endif
#ifdef s21_ECONNABORTED
    [s21_ECONNABORTED] = "Software caused connection abort",
#endif
#ifdef s21_ECONNRESET
    [s21_ECONNRESET] = "Connection reset by peer",
#endif
#ifdef s21_ENOBUFS
    [s21_ENOBUFS] = "No buffer space available",
#endif
#ifdef s21_EISCONN
    [s21_EISCONN] = "Transport endpoint is already connected",
#endif
#ifdef s21_ENOTCONN
    [s21_ENOTCONN] = "Transport endpoint is not connected",
#endif
#ifdef s21_ESHUTDOWN
    [s21_ESHUTDOWN] = "Cannot send after transport endpoint shutdown",
#endif
#ifdef s21_ETOOMANYREFS
    [s21_ETOOMANYREFS] = "Too many references: cannot splice",
#endif
#ifdef s21_ETIMEDOUT
    [s21_ETIMEDOUT] = "Connection timed out",
#endif
#ifdef s21_ECONNREFUSED
    [s21_ECONNREFUSED] = "Connection refused",
#endif
#ifdef s21_EHOSTDOWN
    [s21_EHOSTDOWN] = "Host is down",
#endif
#ifdef s21_EHOSTUNREACH
    [s21_EHOSTUNREACH] = "No route to host",
#endif
#ifdef s21_EALREADY
    [s21_EALREADY] = "Operation already in progress",
#endif
#ifdef s21_EINPROGRESS
    [s21_EINPROGRESS] = "Operation now in progress",
#endif
#ifdef s21_ESTALE
    [s21_ESTALE] = "Stale file handle",
#endif
#ifdef s21_EUCLEAN
    [s21_EUCLEAN] = "Structure needs cleaning",
#endif
#ifdef s21_ENOTNAM
    [s21_ENOTNAM] = "Not a XENIX named type file",
#endif
#ifdef s21_ENAVAIL
    [s21_ENAVAIL] = "No XENIX semaphores available",
#endif
#ifdef s21_EISNAM
    [s21_EISNAM] = "Is a named type file",
#endif
#ifdef s21_EREMOTEIO
    [s21_EREMOTEIO] = "Remote I/O error",
#endif
#ifdef s21_EDQUOT
    [s21_EDQUOT] = "Disk quota exceeded",
#endif
#ifdef s21_ENOMEDIUM
    [s21_ENOMEDIUM] = "No medium found",
#endif
#ifdef s21_EMEDIUMTYPE
    [s21_EMEDIUMTYPE] = "Wrong medium type",
#endif
#ifdef s21_ECANCELED
    [s21_ECANCELED] = "Operation canceled",
#endif
#ifdef s21_ENOKEY
    [s21_ENOKEY] = "Required key not available",
#endif
#ifdef s21_EKEYEXPIRED
    [s21_EKEYEXPIRED] = "Key has expired",
#endif
#ifdef s21_EKEYREVOKED
    [s21_EKEYREVOKED] = "Key has been revoked",
#endif
#ifdef s21_EKEYREJECTED
    [s21_EKEYREJECTED] = "Key was rejected by service",
#endif
#ifdef s21_EOWNERDEAD
    [s21_EOWNERDEAD] = "Owner died",
#endif
#ifdef s21_ENOTRECOVERABLE
    [s21_ENOTRECOVERABLE] = "State not recoverable",
#endif
#ifdef s21_ERFKILL
    [s21_ERFKILL] = "Operation not possible due to RF-kill",
#endif
#ifdef s21_EHWPOISON
    [s21_EHWPOISON] = "Memory page has hardware error",
#endif
#ifdef s21_ENOTSUP
    [s21_ENOTSUP] = "Operation not supported",
#endif

#endif  // SRC_S21_ERRORS_LINUX_ERROR_MSGS_H_