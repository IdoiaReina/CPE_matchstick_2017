/*
** EPITECH PROJECT, 2018
** i know its bad
** File description:
** but i need it
*/

#include "matchs.h"

void game_ex_two(void)
{
	my_putstr("I lost... snif... but I'll get you next time!!\n");
}

void verif_line_put(int line)
{
	if (line < 1) {
		my_putstr("Error: invalid input (positive number expected)\n");
		my_putstr("Line: ");
	}
	else
		my_putstr("Error: this line is out of range\nLine: ");
}

int error_two(int ac, char **av, Entities_Match **e)
{
	if ((*e)->player_match == 0){
		my_putstr("Error: you have to remove at least one match\n");
		if (verif_all(ac, av, e) == 3)
			return (3);
	}
	if ((*e)->player_match < 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		if (verif_all(ac, av, e) == 3)
			return (3);
	}
	if ((*e)->board_match == 0) {
		my_putstr("Error: this line is empty\n");
		if (verif_all(ac, av, e) == 3)
			return (3);
	}
	return (0);
}