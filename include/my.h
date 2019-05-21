/*
** EPITECH PROJECT, 2018
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
#define MY_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define env_error "Error: env is NULL\n"
#define usage_one "USAGE : \n\t./matchstick [Number of lines >1 , <100]"
#define usage_two " [Number of matches removable per turn]\n"
#define line_error "Error: Line numbers should be between 1 and 100\n"
#define matches_error "Error: Matches number should be positive\n"
#define positive_error "Error: invalid input (positive number expected)\n"
#define line_out_range "Error: this line is out of range\n"
#define matches_low "Error: you have to remove at least one match\n"
#define matches_max_one "Error: you cannot remove more than "
#define matches_max_two " matches per turn\n"
#define matches_on_line "Error: not enough matches on this line\n"

typedef struct values {
	char **str;
	char *string;

	int line_pos;
	int m_count;

	int user;
	int line;
	int matches;
	int max_line;
	int max_colum;
	int max_matches;
	int check;
} val;

char *get_next_line(int);
char *my_itoa(int);
int my_error(int, char **, char **);
int my_matches_on_line_check(val *);
int my_strlen(char *);
int my_line_error_check(val *);
int my_matches_error_check(val *);
int my_pipe_counting(val *, int, int, int);
int my_matchgame(val *);
int my_arg_check(char *);
int my_getnbr(char *);
void my_game_over(int);
void my_putstr(char *);
void my_bot_play(val *);
void my_rm_pipe(val *, int);
void my_matchstick(val *);
void my_string(val *);
#endif
