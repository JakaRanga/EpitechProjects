/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** team players
*/

#include "../include/lem.h"

int is_another_team(void)
{
	static int p = 0;
	int	ret = 0;

	if (p == 0) {
		printf("Waiting for enemies...\n");
		p++;
	}
	for (int i = 0; i < SIZE_Y; i++)
		for (int j = 0; j < SIZE_X; j++)
			ret += (board->map[i][j] != 0 &&
			board->map[i][j] != params.team_nb)
			? 1 : 0;
	return (ret);
}

int can_move(int x, int y)
{
	if (board->map[y][x] == 0)
		return (0);
	else
		return (1);
}

int enough_space(void)
{
	int place = 0;

	for (int i = 0; i != SIZE_Y; i++)
		for (int j = 0; j != SIZE_X; j++)
			place += (board->map[i][j] == 0) ? 1 : 0;
	if (place == 0)
		return (84);
	return (0);
}

int my_rand(int max)
{
	return (((float)rand() / RAND_MAX) * (max + 1));
}

int place_player(void)
{
	int pos_x = my_rand(SIZE_X - 1);
	int pos_y = my_rand(SIZE_Y - 1);

	if (enough_space() != 0)
		return (84);
	while (board->map[pos_x][pos_y] != 0) {
		pos_x = my_rand(SIZE_X - 1);
		pos_y = my_rand(SIZE_Y - 1);
	}
	board->map[pos_y][pos_x] = params.team_nb;
	team.pos_x = pos_x;
	team.pos_y = pos_y;
	return (0);
}
