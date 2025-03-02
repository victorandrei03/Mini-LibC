#ifndef __TIME_H__
#define __TIME_H__	1
#ifdef __cplusplus
extern "C" {
#endif
typedef long int time_t;
struct timespec {
    time_t tv_sec;
    time_t tv_nsec;
};
int nanosleep(const struct timespec *req, struct timespec *rem);
#ifdef __cplusplus
}
#endif
#endif
