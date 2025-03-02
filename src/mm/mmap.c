// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_mmap), un void pointer, o lungime, un prot, flag-uri, fildes, offset.
//Daca variabila este negativa inseamna ca apelul syscall nu a fost realizat
//cu succes si setez errno cu valoarea negativa a variabile respective,
//returnand -1. Daca operatia a avut succes, returnez variabila specificata.
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long int ret = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    if (ret < 0) {
		errno = -ret;
        return MAP_FAILED;
    }
    return (void *)ret;
}

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_mremap), un void pointer, vechea lungime, noua lungime, flag-uri.
//Daca variabila este negativa inseamna ca apelul syscall nu a fost realizat
//cu succes si setez errno cu valoarea negativa a variabile respective,
//returnand -1. Daca operatia a avut succes, returnez variabila specificata.
void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long int ret = syscall(__NR_mremap, old_address, old_size, new_size, flags);
    if (ret < 0) {
		errno = -ret;
        return MAP_FAILED;
    }
    return (void *)ret;
}

// Pentru realizarea acestei functii, imi setez intr-o variabila
//apelui functiei syscall ce are ca parametrii numarul apelului cerut
//(__Nr_munmap), un void pointer, o lungime. Daca variabila este negativa
//inseamna ca apelul syscall nu a fost realizat cu succes si setez errno
//cu valoarea negativa a variabile respective, returnand -1. Daca operatia a
//avut succes, returnez variabila specificata.
int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int ret = syscall(__NR_munmap, addr, length);
	if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}
