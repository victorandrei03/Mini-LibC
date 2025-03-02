// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_ftruncate), fildes si length-ul. Daca variabila este
//negativa inseamna ca apelul syscall nu a fost realizat cu succes si
//setez errno cu valoarea negativa a variabile respective, returnand -1.
//Daca operatia a avut succes, returnez variabila specificata.
int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ret = syscall(__NR_ftruncate, fd, length);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
