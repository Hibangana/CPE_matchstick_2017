/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define READ_SIZE (1)

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int k = 0;

	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0') {
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

int back_slash_n(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *my_realloc(char *str, char *buff, int alloc, int size)
{
	char *av;
	static char *memory;

	buff[size + 1] = '\0';
	av = malloc(sizeof(char) * (alloc + 1));
	str = my_strcat(str, buff);
	memory = str;
	av = my_strcat(av, memory);
	return (av);
}

char *get_next_line(int fd)
{
	static int alloc = 0;
	char buff[READ_SIZE + 1];
	char *str = malloc(sizeof(char) * (READ_SIZE + 1));
	int size = 0;
	int i = 0;

	if (fd < 0)
		return (NULL);
	while (back_slash_n(str) != 1) {
		size = read(fd, buff, READ_SIZE);
		if (buff[0] == '\0' || size == 0)
			return (NULL);
		alloc = alloc + size;
		str = my_realloc(str, buff, alloc, size);
	}
	if (back_slash_n(str) == 1) {
		for (i = 0; str[i] != '\n'; i++);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
