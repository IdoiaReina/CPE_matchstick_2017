/*
** EPITECH PROJECT, 2018
** matchsticks
** File description:
** board
*/

#include "matchs.h"

void star_border(Entities_Match **e)
{
	int row = 0;

	while (row != (*e)->game_line * 2 + 1) {
		(*e)->board[0][row] = '*';
		(*e)->board[(*e)->game_line + 1][row] = '*';
		row += 1;
	}
}

int filling_space(Entities_Match **e, int j, int i, int k)
{
	int ii = 0;

	while (ii < k) {
		(*e)->board[j][i] = ' ';
		ii += 1;
		i += 1;
	}
	return (i);
}

int filling_sticks(Entities_Match **e, int j, int i)
{
	int stick = 0;

	while (stick < (*e)->row) {
		(*e)->board[j][i] = '|';
		stick += 1;
		i += 1;
	}
	return (i);
}

void create_board(Entities_Match **e)
{
	int i = 1;
	int j = 1;
	int k = (*e)->game_line - 1;
	int line_malloc = (*e)->game_line * (*e)->game_line * 3;

	(*e)->row = 1;
	(*e)->board[0] = malloc (sizeof(char) * line_malloc);
	(*e)->board[(*e)->game_line + 1] = malloc (sizeof(char) * line_malloc);
	star_border(e);
	while (j < (*e)->game_line + 1) {
		(*e)->board[j] = malloc (sizeof(char) * line_malloc);
		(*e)->board[j][0] = '*';
		i = filling_space(e, j, i, k);
		i = filling_sticks(e, j, i);
		i = filling_space(e, j, i, k);
		(*e)->board[j][i] = '*';
		j += 1;
		i = 1;
		k -= 1;
		(*e)->row += 2;
	}
}

void change_board(Entities_Match **e)
{
	int i = 1;
	int line = (*e)->player_line;

	while ((*e)->board[line][i] != '|')
		i += 1;
	while ((*e)->board[line][i] != ' ' && (*e)->board[line][i] != '*')
		i += 1;
	i -= 1;
	while ((*e)->player_match != 0) {
		(*e)->board[(*e)->player_line][i] = ' ';
		(*e)->player_match -= 1;
		i -= 1;
	}
}
