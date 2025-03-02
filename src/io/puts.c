#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

int puts(int fd, const void *buf, size_t len){
    int ret = syscall(1, fd, buf, len);
    if (ret < 0){
        errno = -ret;
        return -1;
    }
    return ret;
}
