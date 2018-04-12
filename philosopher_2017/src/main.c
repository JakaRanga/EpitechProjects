/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** main
*/

#include "../inc/philo.h"

t_params	params;
g_philo		*philo;

void	global_cleanup()
{
	free(chops);
	for (int i = 0; i != params.nb_philo; i++)
		free(philo[i].mutex);
	free(philo);
}

int	flags(char **av)
{
	int	fp = 0;
	int	fe = 0;
	int	err = 0;

	for (int i = 1; av[i]; i++) {
		if (fp == 0 && strcmp(av[i], "-p") == 0 && err == 0) {
			err = save_philo_params(0, is_num(av[i + 1]));
			fp++;
		}
		else if (fe == 0 && strcmp(av[i], "-e") == 0 && err == 0) {
			err = save_philo_params(1, is_num(av[i + 1]));
			fe++;
		}
	}
	if (fp == 1 && fe == 1 && err == 0)
		return (0);
	return (84);
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 5)
		return (84);
	if (ac == 2 && strcmp(av[1], "--help") == 0)
		return (help(), 0);
	if (flags(av) == 84)
		return (84);
	RCFStartup(ac, av);
	if (create_philo() == 84)
	    return (84);
	RCFCleanup();
	global_cleanup();
	return (0);
}
