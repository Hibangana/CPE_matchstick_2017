/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** my_runner
*/

#include "my.h"

char *my_itoa(int value)
{
	char *str;
	int nb = value;
	int i = 0;
	int k = 0;

	while (value > 0) {
		value = value / 10;
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	i = i - 1;
	while (nb > 0) {
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
		k++;
	}
	str[k] = '\0';
	return (str);
}
