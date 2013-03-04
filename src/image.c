/*
 * image.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#include <stdio.h>
#include <stdlib.h>


void *write_image_header(FILE *file, char header_type[], int width, int height,
		int grayscale) {
	fprintf(file, "%s\n", header_type);
	fprintf(file, "%d %d\n", width, height);
	fprintf(file, "%d\n", grayscale);

	return file;
}

void *write_image_body(FILE *file, int width, int height, int **body) {
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (j == width)
				fprintf(file, "%d", body[i][j]);
			else
				fprintf(file, "%d ", body[i][j]);
		}
	}

	return file;
}
