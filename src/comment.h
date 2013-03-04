/*
 * comment.h
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */

#ifndef COMMENT_H_
#define COMMENT_H_

/**
 * Verifica se a linha é um comentário
 * Retorna verdadeiro se a linha começar com #
 *
 * exemplo: if( is_comment( fgets(file, 2) != 0 ) ...
 */
int is_comment(char *buffer);

#endif /* COMMENT_H_ */
