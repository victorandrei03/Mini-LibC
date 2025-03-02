// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

// In aceasta functie apelez mmap ce intoarce un void * inceputul adresei
//de unde s-a alocat o pagina de memorie. Daca acest void * este egal cu
//MAP_FAILED returnez NULL, operatia neavand succes. In caz contrar, returnez
//acest void pointer si ma folosesc de variabila globala din mem_list.h in care
//imi setez lungimea, avand nevoie mai departe de ea in realizarea urmatoarelor
//functii.
void *malloc(size_t size)
{
    void *arr = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (arr == MAP_FAILED){
		return NULL;
	}
	mem_list_head.len = size;
    return arr;
}

// Pentru implementarea acestei functii calculez lungimea necesara alocarii si
//apelez functia malloc. Daca aceasta functie intoarce NULL, returnez NULL,
//altfel imi setez toate elementele egale cu 0, folosing memset si returnez
//adresa acestui pointer alocat.
void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t len = nmemb * sizeof ( size ) + sizeof(size);
	size_t *arr = (size_t *) malloc(len);
	if (arr == NULL){
		return NULL;
	}
	arr = memset(arr, 0, len);
	return arr;
}

// In aceasta functie verific prima data daca pointer-ul dat este null si daca
//da ies din aceasta. In caz contrar, apelez functia munmap cu parametrii
//pointer-ului dat in antetul functiei si lungimea acestuia ce se afla in
//mem_list_head.
void free(void *ptr)
{
	if (ptr == NULL)
    {
        return;
    }
    munmap(ptr, mem_list_head.len);
}

// Pentru realizarea acestei functii, ma folosesc un void pointer intors la
//apelul functiei mremap ce are rolul de a expanda pagina de memorie. Verific
//daca operatia a avut loc si daca nu returnez NULL si daca da returnez adresa
//data de functia mremap.
void *realloc(void *ptr, size_t size)
{
	void *new_ptr = mremap(ptr, mem_list_head.len, size, MREMAP_MAYMOVE);

	if (new_ptr == MAP_FAILED){
		return NULL;
	}
    return new_ptr;
}

// Aceasta functie este la fel ca cea de mai sus, cu exceptia ca imi calculez
//size-ul cu cei 2 parametrii din antetul functiei.
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	mem_list_head.len = nmemb * size;
	void *new_ptr = mremap(ptr, mem_list_head.len, size, MREMAP_MAYMOVE);

	if (new_ptr == MAP_FAILED){
		return NULL;
	}
    return new_ptr;
}
