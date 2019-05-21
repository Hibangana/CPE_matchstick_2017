/*
** EPITECH PROJECT, 2018
** my_error
** File description:
** my_matchstick
*/

#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int my_arg_check(char *str)
{
	int i = 0;

	if (my_strlen(str) == 0)
		return (84);
	while (str[i] != '\0') {
		if (str[i] > '9' || str[i] < '0')
			return (84);
		i++;
	}
	return (0);
}

int my_error(int ac, char **av, char **env)
{
	if (env[0] == NULL) {
		my_putstr(env_error);
		return (84);
	}
	if (ac != 3) {
		my_putstr(usage_one);
		my_putstr(usage_two);
		return (84);
	}
	if (my_getnbr(av[1]) > 100 || my_getnbr(av[1]) < 2) {
		my_putstr(line_error);
		return (84);
	}
	if (my_getnbr(av[2]) < 0) {
		my_putstr(matches_error);
		return (84);
	}
	return (0);
}
