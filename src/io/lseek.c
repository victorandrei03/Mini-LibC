// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_lseek), fildes, offset-ul si pozitia. Daca variabila este
//negativa inseamna ca apelul syscall nu a fost realizat cu succes si
//setez errno cu valoarea negativa a variabile respective, returnand -1.
//Daca operatia a avut succes, returnez variabila specificata.
off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int ret = syscall(__NR_lseek, fd, offset, whence);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
