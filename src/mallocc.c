/*
 * mallocc.c
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */
#include <stdio.h>
#include <stdlib.h>

void *mallocc(size_t nbytes) {
	void *ptr;
	ptr = malloc(nbytes);
	if (ptr == NULL ) {
		printf("Socorro! malloc devolveu NULL!\n");
		exit(EXIT_FAILURE);
	}
	return ptr;
}
