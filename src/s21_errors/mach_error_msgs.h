#ifndef SRC_S21_ERRORS_MACH_ERROR_MSGS_H_
#define SRC_S21_ERRORS_MACH_ERROR_MSGS_H_

#ifdef s21_EPERM
[s21_EPERM] = "Operation not permitted.",
#endif
#ifdef s21_ENOENT
    [s21_ENOENT] = "No such file or directory.",
#endif
#ifdef s21_ESRCH
    [s21_ESRCH] = "No such process.",
#endif
#ifdef s21_EINTR
    [s21_EINTR] = "Interrupted function call.",
#endif
#ifdef s21_EIO
    [s21_EIO] = "Input/output error.",
#endif
#ifdef s21_ENXIO
    [s21_ENXIO] = "No such device or address.",
#endif
#ifdef s21_E2BIG
    [s21_E2BIG] = "Arg list too long.",
#endif
#ifdef s21_ENOEXEC
    [s21_ENOEXEC] = "Exec format error.",
#endif
#ifdef s21_EBADF
    [s21_EBADF] = "Bad file descriptor.",
#endif
#ifdef s21_ECHILD
    [s21_ECHILD] = "No child processes.",
#endif
#ifdef s21_EDEADLK
    [s21_EDEADLK] = "Resource deadlock avoided.",
#endif
#ifdef s21_ENOMEM
    [s21_ENOMEM] = "Cannot allocate memory.",
#endif
#ifdef s21_EACCES
    [s21_EACCES] = "Permission denied.",
#endif
#ifdef s21_EFAULT
    [s21_EFAULT] = "Bad address.",
#endif
#ifdef s21_ENOTBLK
    [s21_ENOTBLK] = "Not a block device.",
#endif
#ifdef s21_EBUSY
    [s21_EBUSY] = "Resource busy.",
#endif
#ifdef s21_EEXIST
    [s21_EEXIST] = "File exists.",
#endif
#ifdef s21_EXDEV
    [s21_EXDEV] = "Improper link.",
#endif
#ifdef s21_ENODEV
    [s21_ENODEV] = "Operation not supported by device.",
#endif
#ifdef s21_ENOTDIR
    [s21_ENOTDIR] = "Not a directory.",
#endif
#ifdef s21_EISDIR
    [s21_EISDIR] = "Is a directory.",
#endif
#ifdef s21_EINVAL
    [s21_EINVAL] = "Invalid argument.",
#endif
#ifdef s21_ENFILE
    [s21_ENFILE] = "Too many open files in system.",
#endif
#ifdef s21_EMFILE
    [s21_EMFILE] = "Too many open files.",
#endif
#ifdef s21_ENOTTY
    [s21_ENOTTY] = "Inappropriate ioctl for device.",
#endif
#ifdef s21_ETXTBSY
    [s21_ETXTBSY] = "Text file busy.",
#endif
#ifdef s21_EFBIG
    [s21_EFBIG] = "File too large.",
#endif
#ifdef s21_ENOSPC
    [s21_ENOSPC] = "Device out of space.",
#endif
#ifdef s21_ESPIPE
    [s21_ESPIPE] = "Illegal seek.",
#endif
#ifdef s21_EROFS
    [s21_EROFS] = "Read-only file system.",
#endif
#ifdef s21_EMLINK
    [s21_EMLINK] = "Too many links.",
#endif
#ifdef s21_EPIPE
    [s21_EPIPE] = "Broken pipe.",
#endif
#ifdef s21_EDOM
    [s21_EDOM] = "Numerical argument out of domain.",
#endif
#ifdef s21_ERANGE
    [s21_ERANGE] = "Numerical result out of range.",
#endif
#ifdef s21_EAGAIN
    [s21_EAGAIN] = "Resource temporarily unavailable.",
#endif
#ifdef s21_EINPROGRESS
    [s21_EINPROGRESS] = "Operation now in progress.",
#endif
#ifdef s21_EALREADY
    [s21_EALREADY] = "Operation already in progress.",
#endif
#ifdef s21_ENOTSOCK
    [s21_ENOTSOCK] = "Socket operation on non-socket.",
#endif
#ifdef s21_EDESTADDRREQ
    [s21_EDESTADDRREQ] = "Destination address required.",
#endif
#ifdef s21_EMSGSIZE
    [s21_EMSGSIZE] = "Message too long.",
#endif
#ifdef s21_EPROTOTYPE
    [s21_EPROTOTYPE] = "Protocol wrong type for socket.",
#endif
#ifdef s21_ENOPROTOOPT
    [s21_ENOPROTOOPT] = "Protocol not available.",
#endif
#ifdef s21_EPROTONOSUPPORT
    [s21_EPROTONOSUPPORT] = "Protocol not supported.",
#endif
#ifdef s21_ESOCKTNOSUPPORT
    [s21_ESOCKTNOSUPPORT] = "Socket type not supported.",
#endif
#ifdef s21_ENOTSUP
    [s21_ENOTSUP] = "Not supported.",
#endif
#ifdef s21_EPFNOSUPPORT
    [s21_EPFNOSUPPORT] = "Protocol family not supported.",
#endif
#ifdef s21_EAFNOSUPPORT
    [s21_EAFNOSUPPORT] = "Address family not supported by protocol family.",
#endif
#ifdef s21_EADDRINUSE
    [s21_EADDRINUSE] = "Address already in use.",
#endif
#ifdef s21_EADDRNOTAVAIL
    [s21_EADDRNOTAVAIL] = "Cannot assign requested address.",
#endif
#ifdef s21_ENETDOWN
    [s21_ENETDOWN] = "Network is down.",
#endif
#ifdef s21_ENETUNREACH
    [s21_ENETUNREACH] = "Network is unreachable.",
#endif
#ifdef s21_ENETRESET
    [s21_ENETRESET] = "Network dropped connection on reset.",
#endif
#ifdef s21_ECONNABORTED
    [s21_ECONNABORTED] = "Software caused connection abort.",
#endif
#ifdef s21_ECONNRESET
    [s21_ECONNRESET] = "Connection reset by peer.",
#endif
#ifdef s21_ENOBUFS
    [s21_ENOBUFS] = "No buffer space available.",
#endif
#ifdef s21_EISCONN
    [s21_EISCONN] = "Socket is already connected.",
#endif
#ifdef s21_ENOTCONN
    [s21_ENOTCONN] = "Socket is not connected.",
#endif
#ifdef s21_ESHUTDOWN
    [s21_ESHUTDOWN] = "Cannot send after socket shutdown.",
#endif
#ifdef s21_ETIMEDOUT
    [s21_ETIMEDOUT] = "Operation timed out.",
#endif
#ifdef s21_ECONNREFUSED
    [s21_ECONNREFUSED] = "Connection refused.",
#endif
#ifdef s21_ELOOP
    [s21_ELOOP] = "Too many levels of symbolic links.",
#endif
#ifdef s21_ENAMETOOLONG
    [s21_ENAMETOOLONG] = "File name too long.",
#endif
#ifdef s21_EHOSTDOWN
    [s21_EHOSTDOWN] = "Host is down.",
#endif
#ifdef s21_EHOSTUNREACH
    [s21_EHOSTUNREACH] = "No route to host.",
#endif
#ifdef s21_ENOTEMPTY
    [s21_ENOTEMPTY] = "Directory not empty.",
#endif
#ifdef s21_EPROCLIM
    [s21_EPROCLIM] = "Too many processes.",
#endif
#ifdef s21_EUSERS
    [s21_EUSERS] = "Too many users.",
#endif
#ifdef s21_EDQUOT
    [s21_EDQUOT] = "Disc quota exceeded.",
#endif
#ifdef s21_ESTALE
    [s21_ESTALE] = "Stale NFS file handle.",
#endif
#ifdef s21_EBADRPC
    [s21_EBADRPC] = "RPC struct is bad.",
#endif
#ifdef s21_ERPCMISMATCH
    [s21_ERPCMISMATCH] = "RPC version wrong.",
#endif
#ifdef s21_EPROGUNAVAIL
    [s21_EPROGUNAVAIL] = "RPC prog. not avail.",
#endif
#ifdef s21_EPROGMISMATCH
    [s21_EPROGMISMATCH] = "Program version wrong.",
#endif
#ifdef s21_EPROCUNAVAIL
    [s21_EPROCUNAVAIL] = "Bad procedure for program.",
#endif
#ifdef s21_ENOLCK
    [s21_ENOLCK] = "No locks available.",
#endif
#ifdef s21_ENOSYS
    [s21_ENOSYS] = "Function not implemented.",
#endif
#ifdef s21_EFTYPE
    [s21_EFTYPE] = "Inappropriate file type or format.",
#endif
#ifdef s21_EAUTH
    [s21_EAUTH] = "Authentication error.",
#endif
#ifdef s21_ENEEDAUTH
    [s21_ENEEDAUTH] = "Need authenticator.",
#endif
#ifdef s21_EPWROFF
    [s21_EPWROFF] = "Device power is off.",
#endif
#ifdef s21_EDEVERR
    [s21_EDEVERR] = "Device error.",
#endif
#ifdef s21_EOVERFLOW
    [s21_EOVERFLOW] = "Value too large to be stored in data type.",
#endif
#ifdef s21_EBADEXEC
    [s21_EBADEXEC] = "Bad executable (or shared library).",
#endif
#ifdef s21_EBADARCH
    [s21_EBADARCH] = "Bad CPU type in executable.",
#endif
#ifdef s21_ESHLIBVERS
    [s21_ESHLIBVERS] = "Shared library version mismatch.",
#endif
#ifdef s21_EBADMACHO
    [s21_EBADMACHO] = "Malformed Mach-o file.",
#endif
#ifdef s21_ECANCELED
    [s21_ECANCELED] = "Operation canceled.",
#endif
#ifdef s21_EIDRM
    [s21_EIDRM] = "Identifier removed.",
#endif
#ifdef s21_ENOMSG
    [s21_ENOMSG] = "No message of desired type.",
#endif
#ifdef s21_EILSEQ
    [s21_EILSEQ] = "Illegal byte sequence.",
#endif
#ifdef s21_ENOATTR
    [s21_ENOATTR] = "Attribute not found.",
#endif
#ifdef s21_EBADMSG
    [s21_EBADMSG] = "Bad message.",
#endif
#ifdef s21_EMULTIHOP
    [s21_EMULTIHOP] = "Reserved.",
#endif
#ifdef s21_ENODATA
    [s21_ENODATA] = "No message available.",
#endif
#ifdef s21_ENOLINK
    [s21_ENOLINK] = "Reserved.",
#endif
#ifdef s21_ENOSR
    [s21_ENOSR] = "No STREAM resources.",
#endif
#ifdef s21_ENOSTR
    [s21_ENOSTR] = "Not a STREAM.",
#endif
#ifdef s21_EPROTO
    [s21_EPROTO] = "Protocol error.",
#endif
#ifdef s21_ETIME
    [s21_ETIME] = "STREAM ioctl() timeout.",
#endif
#ifdef s21_EOPNOTSUPP
    [s21_EOPNOTSUPP] = "Operation not supported on socket.",
#endif

#endif  // SRC_S21_ERRORS_MACH_ERROR_MSGS_H_