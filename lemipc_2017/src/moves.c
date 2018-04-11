/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** moves
*/

#include "../include/lem.h"

void move_up(void)
{
	if (team.pos_y - 1 >= 0) {
		if (can_move(team.pos_x, team.pos_y - 1) == 0) {
			board->map[team.pos_y][team.pos_x] = 0;
			team.pos_y -= 1;
			board->map[team.pos_y][team.pos_x] = params.team_nb;
		} else
			moves();
	} else
		moves();
}

void move_right(void)
{
	if (team.pos_x + 1 < SIZE_X) {
		if (can_move(team.pos_x + 1, team.pos_y) == 0) {
			board->map[team.pos_y][team.pos_x] = 0;
			team.pos_x += 1;
			board->map[team.pos_y][team.pos_x] = params.team_nb;
		} else
			moves();
	} else
		moves();
}

void move_down(void)
{
	if (team.pos_y + 1 < SIZE_Y) {
		if (can_move(team.pos_x, team.pos_y + 1) == 0) {
			board->map[team.pos_y][team.pos_x] = 0;
			team.pos_y += 1;
			board->map[team.pos_y][team.pos_x] = params.team_nb;
		} else
			moves();
	} else
		moves();
}

void move_left(void)
{
	if (team.pos_x - 1 >= 0) {
		if (can_move(team.pos_x - 1, team.pos_y) == 0) {
			board->map[team.pos_y][team.pos_x] = 0;
			team.pos_x -= 1;
			board->map[team.pos_y][team.pos_x] = params.team_nb;
		} else
			moves();
	} else
		moves();
}

void moves(void)
{
	int m = my_rand(3);

	switch (m) {
	case 0:
		move_up();
		return;
	case 1:
		move_right();
		return;
	case 2:
		move_down();
		return;
	case 3:
		move_left();
		return;
	}
}
