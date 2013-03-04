/*
 * filtros.h
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#ifndef FILTROS_H_
#define FILTROS_H_

void *media(int height, int width, int mask_size, int mask_weight, int **img, int **output);

void *mediana(int height, int width, int mask_size, int **img, int **output);

#endif /* FILTROS_H_ */
