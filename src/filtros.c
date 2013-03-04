/*
 * filtros.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#include <stdio.h>
#include <stdlib.h>
#include "mallocc.h"
#include "quicksort.h"

void *media(int height, int width, int mask_size, int mask_weight, int **img, int **output) {
	int i, sum, w, j, z, x, y;

	// aplica a média no elemento mediano da matriz, conforme o tamanho da mascara
	for (i = 0; i <= (height - mask_size); i++) {
		for (j = 0; j <= (width - mask_size); j++) {
			sum = 0;
			x = j + (mask_size / 2); // coluna
			y = i + (mask_size / 2); // linha

			for (w = 0; w < mask_size; w++) {
				for (z = 0; z < mask_size; z++) {
					sum = sum + img[i + w][j + z];
				}
			}

			output[y][x] = sum / mask_weight;

		}
	}

	return output;
}


void *mediana(int height, int width, int mask_size, int **img, int **output) {
	int i, w, j, z, x, y, k;
	int *mediana;

	// aloca memória para mediana
	mediana = (int)(mallocc(sizeof(int)*mask_size*mask_size));

	// aplica a média no elemento mediano da matriz, conforme o tamanho da mascara
	for (i = 0; i <= (height - mask_size); i++) {
		for (j = 0; j <= (width - mask_size); j++) {
			x = j + (mask_size/2); // coluna
			y = i + (mask_size/ 2); // linha

			k = 0;
			for (w = 0; w < mask_size; w++) {
				for (z = 0; z < mask_size; z++) {
					mediana[k] = img[i + w][j + z];
					k++;
				}
			}

			quicksort(mediana, 0, mask_size-1);

			output[y][x] = mediana[mask_size/2];

		}
	}

	free(mediana);

	return output;
}
