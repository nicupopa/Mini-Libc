#ifndef	_TIME_H
#define	_TIME_H	1

// Source: https://linux.die.net/man/2/nanosleep

struct timespec {
    int tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);

#endif
