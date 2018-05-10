/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** malloc_free
*/

#include "matchs.h"

int malloc_one(char **av, Entities_Match **elem)
{
	int lines = 0;

	(*elem) = (Entities_Match *)malloc(sizeof(Entities_Match));
	if (elem == NULL)
		return (1);
	(*elem)->game_line = my_getnbr(av[1]);
	(*elem)->game_match = my_getnbr(av[2]);
	lines = (*elem)->game_line;
	(*elem)->board = malloc(sizeof(char *) * lines * lines * 3);
	(*elem)->row = 1;
	(*elem)->player_match = 0;
	(*elem)->player_line = 0;
	(*elem)->board_match = 0;
	(*elem)->whos_turn = 1;
	(*elem)->ai_match = 0;
	return (0);
}
