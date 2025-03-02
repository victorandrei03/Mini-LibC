// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_stat), un sir de caractere path si un pointer la o structura stat.
//Daca variabila este negativa inseamna ca apelul syscall nu a fost realizat
//cu succes si setez errno cu valoarea negativa a variabile respective,
//returnand -1. Daca operatia a avut succes, returnez variabila specificata.
int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int ret = syscall(__NR_stat, path, buf);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}
