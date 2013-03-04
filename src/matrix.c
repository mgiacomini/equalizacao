/*
 * matrix.c
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */
#include <stdio.h>
#include <stdlib.h>
#include "mallocc.h"

void *read_matrix_elements(FILE *file, int width, int height) {
	int i, r, c = 0;
	int **array;

	// aloca a memória para a cópia dos elementos do arquivo para a array
	array = (int **) (mallocc(sizeof(int *) * height));
	for (i = 0; i < height; i++) {
		array[i] = (int *) (mallocc(sizeof(int) * width));
	}

	fscanf(file, "%d", &i);
	while (!feof(file) && r < height) {

		array[r][c] = i;

		if (c == width) {
			c = 0;
			r++;
		}
		fscanf(file, "%d", &i);

		c++;
	}

	return array;
}
