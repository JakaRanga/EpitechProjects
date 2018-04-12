/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** creates philo
*/

#include "../inc/philo.h"

int	*chops;

int	check_chops(int idx)
{
	if (chops[idx] == 1 && chops[(idx + 1) % params.nb_philo] == 1)
		return (2);
	else if (chops[idx] == 1)
		return (1);
	return (-1);
}

void	*threads_loop(void *p)
{
	g_philo	*ph = (g_philo*)p;

	sleep(1);
	ph->state = 0;
	while (ph->eat < params.nb_max_eat) {
		if (ph->state == 0 && check_chops(ph->id) >= 1) {
			think_action(ph);
			ph->state = 2;
		}
		if (ph->state == 2 && check_chops(ph->id) == 2) {
			eat_action(ph);
			ph->eat++;
			ph->state = 1;
		}
		if (ph->state == 1) {
			rest_action();
			ph->state = 0;
		}
	}
	pthread_exit(NULL);
}

void	*create_thread(g_philo *ph)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, threads_loop, (void*)ph) == -1)
		return (NULL);
	return ((void*)thread);
}

int	create_philo()
{
	if ((chops = calloc(params.nb_philo, sizeof(int))) == NULL)
		return (84);
	if ((philo = malloc(sizeof(struct s_philo) * params.nb_philo + 1)) == NULL)
		return (84);
	int_memset(chops);
	for (int i = 0; i < params.nb_philo; i++) {
		philo[i].id = i;
		philo[i].timer = 1;
		philo[i].eat = 0;
		philo[i].state = 0;
		philo[i].thread = (pthread_t)create_thread(&philo[i]);
		if ((philo[i].mutex = malloc(sizeof(pthread_mutex_t))) == NULL)
			return (84);
		pthread_mutex_init(philo[i].mutex, NULL);
	}
	for (int i = 0; i < params.nb_philo; i++)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
