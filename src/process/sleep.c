#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <internal/arch/x86_64/syscall_list.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec time;
    time.tv_sec = seconds;
    time.tv_nsec = 0;

	if (nanosleep(&time, &time))
		return time.tv_sec;
	return 0;
}
