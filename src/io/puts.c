#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <string.h>
#include <internal/io.h>

int puts(const char *s)
{
    char newline = '\n';

    int ret = write(1, s, strlen(s));
    int ret_newline = write(1, &newline, 1);

    return ret + ret_newline;
}
