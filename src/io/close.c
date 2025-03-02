// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_close) si fildes. Daca variabila este negativa inseamna
//ca apelul syscall nu a fost realizat cu succes si setez errno cu
//valoarea negativa a variabile respective, returnand -1.
//Daca operatia a avut succes, returnez variabila specificata.
int close(int fd)
{
	/* TODO: Implement close(). */
	int ret = syscall(__NR_close, fd);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}
