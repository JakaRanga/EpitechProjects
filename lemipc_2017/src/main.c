/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** main
*/

#include "../include/lem.h"

t_params params;

int is_num(char *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (84);
	return (0);
}

int parse_cmd(int c, char **v)
{
	c++;
	if ((params.path = strdup(v[1])) == NULL)
		return (84);
	if (is_num(v[2]) == 84 || (params.team_nb = atoi(v[2])) <= 0)
		return (84);
	team.isfirst = 0;
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0)
		return (help(), 0);
	if (ac != 3)
		return (84);
	if (parse_cmd(ac, av) == 84)
		return (84);
	srand(time(NULL));
	if (init_shm() == 84)
		return (84);
	free(params.path);
	return (0);
}
