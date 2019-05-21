/*
** EPITECH PROJECT, 2018
** my_bot_play.c
** File description:
** my_matchstick
*/

#include "my.h"

int my_bot_line(val *val)
{
	int k = rand() % 1000;

	while (k < 1 || k > val->line)
		k = rand() % 1000;
	return (k);
}

int my_bot_matches(val *val)
{
	int k = rand() % 100000;

	while (k < 1 || k > val->matches)
		k = rand() % 10000;
	return (k);
}

int my_bot_check(int line, int matches, val *val)
{
	int count = 0;
	int i = 0;

	while (i < val->max_colum - 1) {
		if (val->str[line][i] == '|')
			count++;
		i++;
	}
	if (count >= matches)
		return (1);
	return (0);
}

void my_bot_play(val *val)
{
	int line = 0;
	int matches = 0;

	line = my_bot_line(val);
	matches = my_bot_matches(val);
	while (my_bot_check(line, matches, val) == 0) {
		line = my_bot_line(val);
		matches = my_bot_matches(val);
	}
	my_putstr("\nAI's turn...\nAI removed ");
	my_putstr(my_itoa(matches));
	my_putstr(" match(es) from line ");
	my_putstr(my_itoa(line));
	my_putstr("\n");
	val->line_pos = line;
	val->m_count = matches;
}
