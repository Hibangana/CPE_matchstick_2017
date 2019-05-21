/*
** EPITECH PROJECT, 2018
** my_rm_pipe
** File description:
** my_matchstick
*/

#include "my.h"

void my_rm_pipe(val *val, int user)
{
	int i = 0;

	while (val->str[val->line_pos][i])
		i++;
	while (val->m_count != 0) {
		if (val->str[val->line_pos][i] == '|') {
			val->str[val->line_pos][i] = ' ';
			val->m_count--;
		}
		i--;
	}
	if (user == 1)
		val->user = 1;
	if (user == 2)
		val->user = 2;
}
