/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** save philo datas
*/

#include "../inc/philo.h"

char	*is_num(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
	}
	return (str);
}

int	*int_memset(int *tab)
{
	for (int i = 0; i < params.nb_philo; i++)
		tab[i] = 1;
	return (tab);
}

int	save_philo_params(int mod, char *str)
{
	if (str == NULL)
		return (84);
	if (mod == 0) {
		if ((params.nb_philo = atoi(str)) < 0)
			return (84);
	}
	else if (mod == 1) {
		if ((params.nb_max_eat = atoi(str)) < 0)
			return (84);
	}
	return (0);
}
