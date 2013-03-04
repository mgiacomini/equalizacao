/*
 * header_type.c
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */

#include <stdio.h>
#include <stdlib.h>
#include "comment.h"
#include "max_values.h"

void get_image_type(FILE *file, char header[]) {
	char tmp[MAX];
	do {
		fscanf(file, "%s", header);
		fgets(tmp, MAX, file);
	} while (is_comment(tmp) && (strcmp(header, "P2") || strcmp(header, "P5")));
}

void get_matrix_size(FILE *file, int *width, int *height) {
	char tmp[MAX];
	do {
		fscanf(file, "%d %d", width, height);
		fgets(tmp, MAX, file);
	} while (is_comment(tmp));
}

void get_grayscale(FILE *file, int *grayscale) {
	char tmp[MAX];
	do {
		fscanf(file, "%d", grayscale);
		fgets(tmp, MAX, file);
	} while (is_comment(tmp));
}
