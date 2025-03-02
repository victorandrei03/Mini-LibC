// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_open), numele fisierului si flag-urile. Daca variabila este
//negativa inseamna ca apelul syscall nu a fost realizat cu succes si
//setez errno cu valoarea negativa a variabile respective, returnand -1.
//Daca operatia a avut succes, returnez variabila specificata.
int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int ret = syscall(__NR_open, filename, flags);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}
