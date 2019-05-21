/*
** EPITECH PROJECT, 2018
** my_string
** File description:
** my_matchstick
*/

#include "my.h"

int my_matches_on_line_check(val *val)
{
	int count = 0;
	int i = 0;

	while (i < val->max_colum - 1) {
		if (val->str[val->line_pos][i] == '|')
			count++;
		i++;
	}
	if (count >= my_getnbr(val->string))
		return (1);
	return (0);
}

void my_game_line_check(val *val)
{
	write(1, "Line: ", 6);
	val->string = get_next_line(0);
	if (val->string == NULL) {
		val->check = 2;
		return;
	}
	val->line_pos = my_getnbr(val->string);
	if (my_line_error_check(val) == 1)
		return;
	val->check = 1;
}

void my_game_matches_check(val *val)
{
	write(1, "Matches: ", 9);
	val->string = get_next_line(0);
	if (val->string == NULL) {
		val->check = 2;
		return;
	}
	val->m_count = my_getnbr(val->string);
	if (my_matches_error_check(val) == 1)
		return;
	val->check = 1;
}

void my_string(val *val)
{
	write(1, "\nYour turn:\n", 12);
	val->check = 0;
	while (val->check != 2) {
		while (val->check == 0)
			my_game_line_check(val);
		if (val->check == 2)
			return;
		val->check = 0;
		if (val->check != 1)
			my_game_matches_check(val);
		if (val->check == 2)
			return;
		if (val->check != 0) {
			write(1, "Player removed ", 15);
			my_putstr(my_itoa(val->m_count));
			write(1, " match(es) from line ", 21);
			my_putstr(my_itoa(val->line_pos));
			write(1, "\n", 1);
			val->check = 2;
		}
	}
}
