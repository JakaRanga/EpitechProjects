/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** sem incr decr
*/

#include "../include/lem.h"

void sem_decr(void)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = -1;
	semop(team.semid, &sops, 1);
}

void sem_incr(void)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = 1;
	semop(team.semid, &sops, 1);
}
