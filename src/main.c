/*
** EPITECH PROJECT, 2018
** main
** File description:
** my_matchstick
*/

#include "my.h"

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
}

void my_struct_filling(char **av, val *val)
{
	val->line = my_getnbr(av[1]);
	val->matches = my_getnbr(av[2]);
}

int main(int ac, char **av, char **env)
{
	val val;

	if (my_error(ac, av, env) == 84)
		return (84);
	my_struct_filling(av, &val);
	my_matchstick(&val);
	return (my_matchgame(&val));
}
