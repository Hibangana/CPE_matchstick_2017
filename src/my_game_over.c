/*
** EPITECH PROJECT, 2018
** my_game_over
** File description:
** my_matchstick
*/

#include "my.h"

void my_game_over(int nb)
{
	if (nb == 1)
		my_putstr("I lost...snif... but I-ll get you next time!!\n");
	if (nb == 2)
		my_putstr("You lost, too bad...\n");
}
