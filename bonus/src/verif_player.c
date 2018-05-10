/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** verifplayer
*/

#include "matchs.h"
#include "get_next_line.h"

int verif_all(int ac, char **av, Entities_Match **e)
{
	if (verif_line(e) == 3)
		return (3);
	if (verif_match(ac, av, e) == 3)
		return (3);
	return (0);
}

int verif_line(Entities_Match **e)
{
	char *buf = malloc(sizeof(char) * 1000);

	my_putstr("Line: ");
	(*e)->player_line = 0;
	(*e)->player_match = 0;
	buf = get_next_line(0);
	if (buf == NULL)
		return (3);
	(*e)->player_line = my_getnbr(buf);
	while ((*e)->player_line > (*e)->game_line || (*e)->player_line < 1) {
		verif_line_put((*e)->player_line);
		buf = get_next_line(0);
		if (buf == NULL)
			return (3);
		(*e)->player_line = my_getnbr(buf);
	}
	free(buf);
	return (0);
}

int verif_enough_match(Entities_Match **e)
{
	int i = 0;

	(*e)->board_match = 0;
	while ((*e)->board[(*e)->player_line][i] != '\0') {
		if ((*e)->board[(*e)->player_line][i] == '|')
			(*e)->board_match += 1;
		i += 1;
	}
	return (0);
}

int errors_one(int ac, char **av, Entities_Match **e)
{
	error_two(ac, av, e);
	if ((*e)->player_match > (*e)->game_match) {
		my_putstr("Error: you cannot remove more than ");
		my_putchar((*e)->game_match + 48);
		my_putstr(" matches per turn\n");
		if (verif_all(ac, av, e) == 3)
			return (3);
	}
	if ((*e)->player_match > (*e)->board_match) {
		my_putstr("Error: not enough matches on this line\n");
		if (verif_all(ac, av, e) == 3)
			return (3);
	}
	return (0);
}
/*
		my_putstr("Error: you cannot remove more than ");
		my_putchar((*e)->board_match + 48);
		my_putstr(" match(es) on this line\n");
		verif_line(e);
		verif_match(ac, av, e);
	}
	return (0);
}*/

int verif_match(int ac, char **av, Entities_Match **e)
{
	char *buf = malloc(sizeof(char) * 1000);

	my_putstr("Matches: ");
	buf = get_next_line(0);
	if (buf == NULL)
		return (3);
	(*e)->player_match = my_getnbr(buf);
	verif_enough_match(e);
	errors_one(ac, av, e);
	free(buf);
	return (0);
}