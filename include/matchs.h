/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** .h
*/

#ifndef HPOINT
#define HPOINT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char *str);
int my_strlen(char const *str);

typedef struct s_Entities_Match
{
	char **board;
	int game_line;
	int game_match;
	int player_line;
	int player_match;
	int board_match;
	int row;
	int whos_turn;
	int ai_match;
}Entities_Match;

int malloc_one(char **av, Entities_Match **elem);
void    my_putchar(char c);
int     my_putstr(char const *str);
int my_strlen(char const *str);

/*BOARD*/
void star_border(Entities_Match **e);
int filling_space(Entities_Match **e, int j, int i, int k);
int filling_sticks(Entities_Match **e, int j, int i);
void create_board(Entities_Match **e);
void change_board(Entities_Match **e);
void display_board(Entities_Match **e);

/*GAME EXEC*/
int game_exec(int ac, char **av, Entities_Match **e);
void game_ex_two(void);
int ais_turn(Entities_Match **e);
int verif_line(Entities_Match **e);
void verif_line_put(int line);
int verif_match(int ac, char **av, Entities_Match **e);
int error_two(int ac, char **av, Entities_Match **e);
int verif_all(int ac, char **av, Entities_Match **e);

#endif
