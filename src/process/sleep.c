#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

// In aceasta functie imi declar o variabila de tip timespec si ii initializez
//campul tv_sec cu parametru declarat in antetul functiei "sec". Prin urmare,
//initializez campul tv_nsec cu 0 si apelez functia nanosleep.
unsigned int sleep(unsigned int sec){
    struct timespec req;
    req.tv_sec = sec;
    req.tv_nsec = 0;

    nanosleep(&req, NULL);
    return 1;
}
