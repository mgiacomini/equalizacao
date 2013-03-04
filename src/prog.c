/*
 * prog.c
 *
 *  Created on: Mar 1, 2013
 *      Author: mgiacomini
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comment.h"
#include "header.h"
#include "max_values.h"
#include "matrix.h"
#include "mask.h"
#include "filtros.h"
#include "image.h"
#include "mallocc.h"

void main(int argc, char **argv) {

	FILE *file, *fout, *mask_file; // arquivos de entrada e saída

	char line[MAX], header_type[MAX]; // strings

	int matrix_width, matrix_height, grayscale, weight, soma, mask_size; // colunas, linhas, escala de cinza, weight da máscara, soma dos elementos

	int i, j, w, z, x, y; // contadores e auxiliares

	int **array, **output, **mask; // matriz da imagem original, matriz da imagem de saída, matriz da mascara

	int c, r = 0; // colunas, linhas

	// verifica se os argumentos foram passados corretamente
	if (argc != 5 && argc != 4) {
		printf(
				"Os argumentos foram passados incorretamente. Por favor, consulte a documentação.");
		exit(EXIT_FAILURE);
	} else {
		if (!(file = fopen(argv[1], "r"))) {
			printf("Não foi possível abrir a imagem.");
			exit(EXIT_FAILURE);
		}

		if (!(fout = fopen(argv[argc - 1], "w+"))) {
			printf("Não foi possível abrir a imagem.");
			exit(EXIT_FAILURE);
		}
	}

	// se for utilizado o filtro de média, abre a imagem
	if (argc == 4) {
		if (!(mask_file = fopen(argv[2], "r"))) {
			printf("Não foi possível abrir a máscara.");
			exit(EXIT_FAILURE);
		}
	}

	// tipo da imagem: P5 ou P2
	get_image_type(file, &header_type);

	// tamanho da matrix: col lin
	get_matrix_size(file, &matrix_width, &matrix_height);

	// maior valor da escala de cinza
	get_grayscale(file, &grayscale);

	// verifica se o nível de cinza é o permitido
	if (grayscale > MAX_GRAYSCALE) {
		printf("O valor da escala de cinza é maior do que o permitido.");
		exit(EXIT_FAILURE);
	}

	// escreve o cabeçalho da imagem no arquivo
	write_image_header(fout, header_type, matrix_width, matrix_height,
			grayscale);

	// aloca memória para a imagem de saída
	output = (int **) (mallocc(sizeof(int *) * matrix_height));
	for (i = 0; i < matrix_height; i++) {
		output[i] = (int *) (mallocc(sizeof(int) * matrix_width));
	}

	// copia o corpo da imagem para a matriz
	array = read_matrix_elements(file, matrix_width, matrix_height);
	output = read_matrix_elements(file, matrix_width, matrix_height);

	// filtro da média
	mask_size = get_mask_size(mask_file);
	if(argc == 4){
		// aloca memória para a imagem de saída
		mask = (int **) (mallocc(sizeof(int *) * mask_size));
		for (i = 0; i < mask_size; i++) {
			mask[i] = (int *) (mallocc(sizeof(int) * mask_size));
		}

		// passa os elementos do arquivo para uma array
		mask = read_matrix_elements(mask_file, mask_size, mask_size);

		// verifica se o tamanho da mascara está correto
		if ((mask_size % 2 == 0) || mask_size < 3) {
			printf("Tamanho da máscara incorreto.");
			exit(EXIT_FAILURE);
		}

		// calcula o weight da máscara
		for (i = 0; i < mask_size; i++) {
			for (j = 0; j < mask_size; j++) {
				weight = weight + mask[i][j];
			}
		}

		// aplica o filtro
		media( matrix_height, matrix_width, mask_size, weight, array, output );
	} else
		mediana(matrix_height, matrix_width, mask_size, array, output);

	// grava imagem
	write_image_body(fout, matrix_width, matrix_height, output);

	// libera a memória alocada
	free(array);
	free(output);

	// fecha o buffer dos arquivos
	fclose(file);
	fclose(fout);

	return;
}
