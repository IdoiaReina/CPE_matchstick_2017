/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main
*/

#include "matchs.h"

void display_board(Entities_Match **e)
{
	int j = 0;

	while (j < (*e)->game_line + 2) {
		my_putstr((*e)->board[j]);
		my_putchar('\n');
		j += 1;
	}
	my_putstr("\n");
}

void put_wrong_arg(void)
{
	my_putstr("Missing Argument(s):\nUSAGE:\n\t./matchstick [Board Size]");
	my_putstr(" [Number of Removable Match(es)]\n");
}

int main(int ac, char **av)
{
	Entities_Match *e;
	int who_won = 0;

	if (ac < 3) {
		put_wrong_arg();
		return (84);
	}
	malloc_one(av, &e);
	if (e->game_line < 2 || e->game_line > 99) {
		my_putstr("Wrong Size : Must be between 2 and 99.\n");
		return (84);
	}
	create_board(&e);
	display_board(&e);
	while (who_won != 2 && who_won != 1) {
		who_won = game_exec(ac, av, &e);
		if (who_won == 3)
			return (0);
	}
	return (who_won);
}
