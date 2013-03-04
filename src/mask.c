/*
 * mask.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */
#include <stdlib.h>
#include <stdio.h>
#include "comment.h"
#include "max_values.h"
#include "mallocc.h"

int get_mask_size(FILE *file) {
	char tmp[MAX];
	int i;
	do {
		fscanf(file, "%d", &i);
		fgets(tmp, MAX, file);
	} while (is_comment(tmp));

	return i;
}
