/*
** EPITECH PROJECT, 2018
** my_line_error_check
** File description:
** my_matchstick
*/

#include "my.h"

void my_puterror_matches(val *val)
{
	write(1, matches_max_one, my_strlen(matches_max_one));
	my_putstr(my_itoa(val->matches));
	write(1, matches_max_two, my_strlen(matches_max_two));
}

int my_line_error_check(val *val)
{
	if (my_arg_check(val->string) == 84) {
		write(1, positive_error, my_strlen(positive_error));
		return (1);
	}
	if (val->line_pos == 0 || val->line_pos > val->line) {
		write(1, line_out_range, my_strlen(line_out_range));
		return (1);
	}
	return (0);
}

int my_matches_error_check(val *val)
{
	if (my_arg_check(val->string) == 84) {
		write(1, positive_error, my_strlen(positive_error));
		return (1);
	}
	if (val->m_count == 0) {
		write(1, matches_low, my_strlen(matches_low));
		return (1);
	}
	if (val->m_count > val->matches) {
		my_puterror_matches(val);
		return (1);
	}
	if (my_matches_on_line_check(val) == 0) {
		write(1, matches_on_line, 39);
		return (1);
	}
	return (0);
}
