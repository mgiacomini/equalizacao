/*
 * header_type.h
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */

#ifndef HEADER_TYPE_H_
#define HEADER_TYPE_H_

/**
 * Escreve o cabeçalho da imagem no arquivo
 */
void get_image_type(FILE *file, char header[]);

void get_matrix_size(FILE *file, int *width, int *height);

void get_grayscale(FILE *file, int *grayscale);

#endif /* HEADER_TYPE_H_ */
