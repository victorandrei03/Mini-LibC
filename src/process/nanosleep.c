#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_nanosleep), 2 pointeri la 2 structuri de tip timespec declarate in
//time.h. Daca variabila este negativa inseamna ca apelul syscall nu a fost
//realizat cu succes si setez errno cu valoarea negativa a variabile
//respective, returnand -1. Daca operatia a avut succes, returnez variabila
//specificata.
int nanosleep(const struct timespec *req, struct timespec *rem){
    int ret = syscall(__NR_nanosleep, req, rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
