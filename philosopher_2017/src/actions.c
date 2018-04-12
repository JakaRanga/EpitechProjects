/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** actions
*/

#include "../inc/philo.h"

void	eat_action(g_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	lphilo_take_chopstick(ph->mutex);
	lphilo_take_chopstick(philo[(ph->id + 1) % params.nb_philo].mutex);
	chops[ph->id] = 0;
	chops[(ph->id + 1) % params.nb_philo] = 0;
	lphilo_eat();
	usleep(2000);
	chops[ph->id] = 1;
	chops[(ph->id + 1) % params.nb_philo] = 1;
	lphilo_release_chopstick(ph->mutex);
	lphilo_release_chopstick(philo[(ph->id + 1) % params.nb_philo].mutex);
	pthread_mutex_unlock(ph->mutex);
}

void	rest_action()
{
	lphilo_sleep();
}

void	think_action(g_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	lphilo_take_chopstick(ph->mutex);
	chops[ph->id] = 0;
	lphilo_think();
	usleep(2000);
	chops[ph->id] = 1;
	lphilo_release_chopstick(ph->mutex);
	pthread_mutex_unlock(ph->mutex);
}
