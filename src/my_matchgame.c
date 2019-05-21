/*
** EPITECH PROJECT, 2018
** my_matchgame
** File description:
** my_matchstick
*/

#include "my.h"

void my_print_board(val *val)
{
	for (int i = 0; val->str[i] != NULL; i++) {
		write(1, val->str[i], val->max_colum);
		write(1, "\n", 1);
	}
}

int my_pipe_counting(val *val, int i, int k, int count)
{
	if (val->str[i][k] == '|')
		count++;
	return (count);
}

int game_is_over(val *val)
{
	int count = 0;

	for (int i = 0; val->str[i] != NULL; i++) {
		for (int k = 0; val->str[i][k] != '\0'; k++)
			count = my_pipe_counting(val, i, k, count);
	}
	if (count == 0)
		return (1);
	return (0);
}

int my_matchgame(val *val)
{
	my_print_board(val);
	while (1) {
		my_string(val);
		if (val->string == NULL)
			return (0);
		my_rm_pipe(val, 2);
		my_print_board(val);
		if (game_is_over(val) == 1) {
			my_game_over(2);
			return (val->user);
		}
		my_bot_play(val);
		my_rm_pipe(val, 1);
		my_print_board(val);
		if (game_is_over(val) == 1) {
			my_game_over(1);
			return (val->user);
		}
	}
	return (0);
}
