/*
** EPITECH PROJECT, 2018
** matchsticks
** File description:
** game_exec
*/

#include "matchs.h"

int maybe_win_line(Entities_Match **e, int j)
{
	int i = 0;

	while ((*e)->board[j][i] != '\0') {
		if ((*e)->board[j][i] == '|')
			return (2);
		i += 1;
	}
	return (0);
}

int maybe_win(Entities_Match **e)
{
	int j = 0;

	while (j < (*e)->game_line + 2) {
		if (maybe_win_line(e, j) == 2)
			return (0);
		j += 1;
	}
	return (1);
}

int players_turn(int ac, char **av, Entities_Match **e)
{
	my_putstr("Your turn:\n");
	if (verif_line(e) == 3)
		return (3);
	if (verif_match(ac, av, e) == 3)
		return (3);
	my_putstr("Player removed ");
	my_putchar((*e)->player_match + 48);
	my_putstr(" match(es) from line ");
	my_putchar((*e)->player_line + 48);
	my_putstr("\n");
	(*e)->whos_turn = 2;
	return (0);
}

int now_its_ai(Entities_Match **e)
{
	my_putstr("AI's turn...\n");
	ais_turn(e);
	my_putstr("AI removed ");
	my_putchar((*e)->player_match + 48);
	my_putstr(" match(es) from line ");
	my_putchar((*e)->player_line + 48);
	my_putstr("\n");
	(*e)->whos_turn = 1;
	return (0);
}

int game_exec(int ac, char **av, Entities_Match **e)
{
	if ((*e)->whos_turn == 1) {
		if (players_turn(ac, av, e) == 3)
			return (3);
	}
	else
		now_its_ai(e);
	change_board(e);
	display_board(e);
	if (maybe_win(e) == 1) {
		if ((*e)->whos_turn == 1) {
			game_ex_two();
			return (1);
		}
		else {
			my_putstr("You lost, too bad...\n");
			return (2);
		}
	}
	return (0);
}
