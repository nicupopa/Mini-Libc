#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
    int ret = syscall(__NR_nanosleep, t1, t2);

    if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
