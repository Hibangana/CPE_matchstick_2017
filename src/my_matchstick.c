/*
** EPITECH PROJECT, 2018
** my_matchstick
** File description:
** my_matchstick
*/

#include "my.h"

char *my_star_fill(val *val, int i)
{
	int k = 0;

	while (k < val->max_colum) {
		val->str[i][k] = '*';
		k++;
	}
	val->str[i][k] = '\0';
	return (val->str[i]);
}

char *my_pipe_fill(val *val, int i)
{
	int k = 1;

	val->str[i][0] = '*';
	val->str[i][val->max_colum - 1] = '*';
	while (k < val->max_colum - 1) {
		if (k >= (val->max_colum - 1) / 2 - (i - 1)
		&& k <= (val->max_colum - 1) / 2 + (i - 1))
			val->str[i][k] = '|';
		else
			val->str[i][k] = ' ';
		k++;
	}
	val->str[i][k + 1] = '\0';
	return (val->str[i]);
}

void my_board_filling(val *val)
{
	int i = 0;

	val->str = malloc(sizeof(char *) * (val->max_line + 1));
	val->str[val->max_line] = NULL;
	for (i = 0; i < val->max_line; i++) {
		val->str[i] = malloc(sizeof(char) * (val->max_colum + 1));
		if (i == 0 || i == val->max_line - 1)
			val->str[i] = my_star_fill(val, i);
		else
			val->str[i] = my_pipe_fill(val, i);
	}
}

void my_matchstick(val *val)
{
	val->max_line = val->line + 2;
	val->max_colum = 2 * (val->line - 1) + 3;
	val->max_matches = val->line * 2;
	my_board_filling(val);
}
