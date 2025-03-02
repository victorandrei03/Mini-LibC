// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

// In aceasta functie parcurg sirul source si introduc element cu
//element in sirul destination
char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	size_t i;
	for (i = 0; i < strlen(source); i++){
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

// Folosesc acelasi procedeu ca si mai sus, doar ca parcurg "len"
//elemente
char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	for (size_t i = 0; i < len; i++){
		destination[i] = source[i];
	}
	return destination;
}

// Ma folosesc de un contor "count" ce reprezinta lungimea initiala
//a sirului destination, dupa care parcurg sirul source, introducand
//element cu element in destination, avand grija sa cresc si "count"
char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int count = strlen(destination);
	for (size_t i = 0; i < strlen(source); i++){
		destination[count] = source[i];
		count++;
	}
	destination[count] = '\0';
	return destination;
}

// Acelasi principiu ca si mai sus, dar for0ul merge pana la "len",
//ce este dat in antetul functiei
char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int count = strlen(destination);
	for (size_t i = 0; i < len; i++){
		destination[count] = source[i];
		count++;
	}
	destination[count] = '\0';
	return destination;
}

// Ma folosesc de o variabila "max" ce reprezinta cea mai mare lungime
//dintre cele 2 siruri. Astfel, parcurg de la 0 pana la max, verificand
//daca exista un element diferit de altul si daca da: in primul caz
//returnez 1 daca elementul din primul sir este mai mare decat cel din al
//doilea si -1 in caz contrar.
int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	size_t max = strlen(str1);
	if (max < strlen(str2)){
		max = strlen(str2);
	}
	for (size_t i = 0; i < max; i++){
		if (str1[i] != str2[i] && str1[i] > str2[i]){
			return 1;
		}
		if (str1[i] != str2[i] && str1[i] < str2[i]){
			return -1;
		}
	}
	return 0;
}

// Acelasi principiu ca si mai sus, doar ca nu mai am max, am lenght-ul dat
//"len"
int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	for (size_t i = 0; i < len; i++){
		if (str1[i] != str2[i] && str1[i] > str2[i]){
			return 1;
		}
		if (str1[i] != str2[i] && str1[i] < str2[i]){
			return -1;
		}
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

// Parcurg sirul dat si cand gasesc elementul cerut returnez sirul dat in
//antetul functiei plus adresa respectiva unde se afla acesta(i), rezultand
//un sir cu primul element fiind acela cautat
char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (size_t i = 0; i < strlen(str); i++){
		if (str[i] == c){
			return (char *) str + i;
		}
	}
	return NULL;
}

// Acelasi principiu, doar ca incep cautarea de la coada spre inceput.
char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int len = (int) strlen(str) - 1;
	for (int i = len; i >= 0; i--){
		if (str[i] == c){
			return (char *) str + i;
		}
	}
	return NULL;
}

// In aceasta functie parcurg sirul haystack si daca am gasit ca primul
//element al sirului needle sa fie egal cu elementul curent, pornesc o
//alta cautare de la pozitia curenta plus lungimea lui needle. Daca in
//aceasta cautare gasesc 2 elemente diferite, imi setez unfound pe 1
//si dau break, astfel operatia neavand succes. In schimb, daca unfound
//este egal cu 0, inseamna ca am gasit unde se afla needle si returnez
//adresa lui haystack plus pozitia de la care am inceput cautarea(i).
char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	for (size_t i = 0; i < strlen(haystack); i++){
		if (haystack[i] == needle[0]){
			int unfound = 0;
			int needle_counter = 0;
			for (size_t j = i; j < i + strlen(needle); j++){
				if (haystack[j] != needle[needle_counter]){
					unfound = 1;
					break;
				}
				needle_counter++;
			}
			if (unfound == 0){
				return (char *) haystack + i;
			}
		}
	}
	return NULL;
}

// Exact acelasi principiu ca si mai sus, doar ca incep cautarea de la
//coada sirului haystack.
char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int len = (int) strlen(haystack) - 1;
	for (int i = len; i >= 0; i--){
		if (haystack[i] == needle[0]){
			int unfound = 0;
			int needle_counter = 0;
			for (size_t j = i; j < i + strlen(needle); j++){
				if (haystack[j] != needle[needle_counter]){
					unfound = 1;
					break;
				}
				needle_counter++;
			}
			if (unfound == 0){
				return (char *) haystack + i;
			}
		}
	}
	return NULL;
}

// In aceasta functie imi iau 2 siruri ca variabile, pentru a face cast
//la cei doi void pointeri, dupa care copiez elementele din sursa in
//destinatie. La sfarsit, fac din nou cast din char * in void * si il
//returnez.
void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *) destination;
	char *src = (char *) source;
	for (size_t i = 0; i < num; i++){
		dest[i] = src[i];
	}
	destination = (void *)dest;
	return destination;
}

// In aceasta functie verific daca pointer-ul destination se afla la o
//adresa mai mica decat source si daca suma acestuia plus parametrul num
//depasesc adresa pointer-ului source si daca da, copiez elementele de la
//inceput spre sfarsit din source in dest. Daca aceasta conditie nu este
//indeplinita, copiez elemntele in ordine inversa.
void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *) destination;
	char *src = (char *) source;
	if (dest < src && dest + num > src){
		for (int i = 0; i < (int) num; i++){
			dest[i] = src[i];
		}
	} else{
		for (int i = num; i >= 0; i--){
			dest[i] = src[i];
		}
	}
	destination = (void *) dest;
	return destination;
}

// In aceasta functie parcurg "num" elemente de la inceput spre sfarsit si
//daca elementul pointer-ului ptr1 este mai mare decat al lui ptr2 returnez 1
//si -1 in caz contrar. Daca nu s-a gasit element diferit, returnez 0.
int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *dest = (char *) ptr1;
	char *src = (char *) ptr2;
	for (size_t i = 0; i < num; i++){
		if (dest[i] > src[i]){
			return 1;
		}
		if (dest[i] < src[i]){
			return -1;
		}
	}
	return 0;
}

// Parcurg sirul source de la 0 la "num" si introduc elementul cerut "value"
//pe fiecare pozitie in parte.
void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *) source;
	for (int i = 0; i < (int) num; i++){
		src[i] = value;
	}
	source = (void *) src;
	return source;
}
