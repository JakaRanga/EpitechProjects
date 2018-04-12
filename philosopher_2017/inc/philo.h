/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** dot h file
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "extern.h"

typedef struct	s_params
{
	int	nb_philo;
	int	nb_max_eat;
}		t_params;

typedef struct		s_philo
{
	pthread_t	thread;
	pthread_mutex_t	*mutex;
	int		state;
	int		id;
	int		timer;
	int		eat;
}			g_philo;

extern t_params	params;
extern g_philo	*philo;
extern int	*chops;

void	eat_action(g_philo*);
void	rest_action();
void	think_action(g_philo*);
int	save_philo_params(int, char*);
int	create_philo();
int	*int_memset(int*);
char	*is_num(char*);
void	help();

#endif /* !PHILO_H_ */
