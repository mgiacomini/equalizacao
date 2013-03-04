/*
 * comment.c
 *
 *  Created on: Feb 27, 2013
 *      Author: mgiacomini
 */


int is_comment(char *buffer) {
	if (*buffer == '#')
		return 1;

	return 0;
}
