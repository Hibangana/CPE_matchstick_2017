/*
** EPITECH PROJECT, 2017
** main
** File description:
** 101pong
*/

int my_getnbr_sign(char const *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		if (str[i] == '-')
			count = count + 1;
		i++;
	}
	if ((count % 2) == 1)
		return (-1);
	return (1);
}

int nb_over_interger(long nb)
{
	if (nb > 2147483647 || nb < -2147483647)
		return (0);
	else
		return (1);
}

int my_getnbr(char const *str)
{
	int i = 0;
	long nb = 0;
	int a = my_getnbr_sign(str);

	while (str[i] != '\0') {
		if (str[i] <= '9' && str[i] >= '0') {
			nb = nb * 10;
			nb = nb + str[i] - 48;
		}
		if (str[i + 1] > '9' || str[i + 1] < '0') {
			if (nb_over_interger(nb) == 0)
				return (0);
			return (nb*a);
		}
		i++;
	}
	if (nb_over_interger(nb) == 0)
		return(0);
	nb = nb * a;
	return (nb);
}
