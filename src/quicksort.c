/*
 * quicksort.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#include "particiona.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort e devolve v */

int quicksort(int v[], int a, int b) {
	int m;
	if (a < b) {
		m = particiona(v, a, b, v[b]);
		quicksort(v, a, m - 1);
		quicksort(v, m + 1, b);
	}

	return v;
}
