/*
 * image.h
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#ifndef IMAGE_H_
#define IMAGE_H_

void *write_image_header(FILE *file, char header_type[], int width, int height, int grayscale);

void *write_image_body(FILE *file, int width, int height, int **body);

#endif /* IMAGE_H_ */
