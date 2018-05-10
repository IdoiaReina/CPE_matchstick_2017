/*
** EPITECH PROJECT, 2018
** matchsticks
** File description:
** ai
*/

#include "matchs.h"

int matches_left_line(Entities_Match **e, int j, int i)
{
	if ((*e)->board[j][i] == '|') {
		(*e)->ai_match += 1;
	}
	i += 1;
	return (i);
}

int matches_left(Entities_Match **e)
{
	int j = 1;
	int i = 0;

	while (j < (*e)->game_line + 2) {
		i = 0;
		while ((*e)->board[j][i] != '\0') {
			i = matches_left_line(e, j, i);
		}
		j += 1;
	}
	return (1);
}

int can_ai_take_line(Entities_Match **e, int matches, int j)
{
	int i = 0;
	int maybe = 0;

	while ((*e)->board[j][i] != '\0') {
		if ((*e)->board[j][i] == '|') {
			maybe += 1;
		}
		else
			maybe = 0;
		if (maybe == matches)
			return (maybe);
		i += 1;
	}
	return (0);
}

int can_ai_take(Entities_Match **e, int matches)
{
	int j = 1;
	int maybe = 0;

	while (j < (*e)->game_line + 2) {
		maybe = can_ai_take_line(e, matches, j);
		if (maybe == matches)
			return (j);
		j += 1;
	}
	return (0);
}

int ais_turn(Entities_Match **e)
{
	int need_to_take = 0;
	int line = 0;

	matches_left(e);
	need_to_take = (*e)->ai_match % ((*e)->game_match + 1) - 1;
	if ((*e)->ai_match <= ((*e)->game_match +1) * 2) {
		need_to_take = (*e)->ai_match - ((*e)->game_match + 2);
	}
	if (need_to_take < 1)
		need_to_take = 1;
	line = can_ai_take(e, need_to_take);
	if (line == 0) {
		need_to_take = 1;
		line = can_ai_take(e, need_to_take);
	}
	(*e)->player_line = line;
	(*e)->player_match = need_to_take;
	return (0);
}
