/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** get killed
*/

#include "../include/lem.h"

int look_around(int t_nb)
{
	int cnt = 0;

	if (team.pos_y - 1 >= 0 &&
		board->map[team.pos_y - 1][team.pos_x] == t_nb)
		cnt++;
	if (team.pos_y + 1 < SIZE_Y &&
		board->map[team.pos_y + 1][team.pos_x] == t_nb)
		cnt++;
	if (team.pos_x - 1 >= 0 &&
		board->map[team.pos_y][team.pos_x - 1] == t_nb)
		cnt++;
	if (team.pos_x + 1 < SIZE_X &&
		board->map[team.pos_y][team.pos_x + 1] == t_nb)
		cnt++;
	return ((cnt >= 2) ? 1 : 0);
}

int	get_killed(void)
{
	int k = 0;

	if (team.pos_y - 1 >= 0 &&
		board->map[team.pos_y - 1][team.pos_x] != 0)
		k = look_around(board->map[team.pos_y - 1][team.pos_x]);
	if (team.pos_y + 1 < SIZE_Y &&
		board->map[team.pos_y + 1][team.pos_x] != 0)
		k = look_around(board->map[team.pos_y + 1][team.pos_x]);
	if (team.pos_x - 1 >= 0 &&
		board->map[team.pos_y][team.pos_x - 1] != 0)
		k = look_around(board->map[team.pos_y][team.pos_x - 1]);
	if (team.pos_x + 1 < SIZE_X &&
		board->map[team.pos_y][team.pos_x + 1] != 0)
		k = look_around(board->map[team.pos_y][team.pos_x + 1]);
	board->map[team.pos_y][team.pos_x] =
	(k > 0) ? 0 : board->map[team.pos_y][team.pos_x];
	return (k);
}
