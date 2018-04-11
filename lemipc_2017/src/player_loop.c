/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** player loop
*/

#include "../include/lem.h"

int team_left(void)
{
	int team = 1;

	for (int i = 0; i != SIZE_Y; i++)
		for (int j = 0; j != SIZE_X; j++)
			team += (board->map[i][j] != 0 &&
			board->map[i][j] != params.team_nb) ? 1 : 0;
	return (team);
}

void keep_fightin(int isfirst)
{
	if (isfirst == 1) {
		send_msg("Keep fighting bois!");
		printf("Keep fighting bois!\n");
	} else
		receive_msg();
}

int win(void)
{
	if (team.isfirst == 1)
		print_board();
	printf("Team number %i wins!\n", params.team_nb);
	return (0);
}

int player_loop(void)
{
	int cnt = 0;

	if (place_player() == 84)
		return (84);
	print_board();
	if (team.isfirst == 1 || is_another_team() == 0)
		while (is_another_team() == 0);
	while (team_left() > 1 && cnt >= 0) {
		sem_decr();
		moves();
		if (get_killed() == 1)
			return (printf("You got killed...\n"), 0);
		sem_incr();
		if (team.isfirst == 1)
			print_board();
		keep_fightin(team.isfirst);
		usleep(10000);
		cnt++;
	}
	return (win());
}
