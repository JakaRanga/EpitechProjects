/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** shm
*/

#include "../include/lem.h"

t_board	*board;
t_team	team;

int init_msg(void)
{
	team.msgid = msgget(team.key, SHM_R | SHM_W);
	if (team.msgid == -1)
		team.msgid = msgget(team.key, IPC_CREAT | SHM_R | SHM_W);
	player_loop();
	if (msgctl(team.msgid, IPC_RMID, NULL) == -1)
		return (84);
	return (0);
}

int init_sem(void)
{
	team.semid = semget(team.key, 1, SHM_R | SHM_W);
	if (team.semid == -1) {
		team.semid = semget(team.key, 1, IPC_CREAT | SHM_R | SHM_W);
		semctl(team.semid, 0, SETVAL, 1);
	} else {
		team.semid = semget(team.key, 1, SHM_R | SHM_W);
		semctl(team.semid, 0, SETVAL, 1);
	}
	if (init_msg() != 0)
		return (84);
	if (semctl(team.semid, 0, IPC_RMID) == -1)
		return (84);
	return (0);
}

int init_shm(void)
{
	int shm_id;

	if ((team.key = ftok(params.path, 1)) == -1)
		return (84);
	printf("Ftok Key : %i\n", team.key);
	shm_id = shmget(team.key, sizeof(struct s_board), SHM_R | SHM_W);
	if (shm_id == -1) {
		team.isfirst = 1;
		if ((shm_id = shmget(team.key, sizeof(struct s_board),
			IPC_CREAT | SHM_R | SHM_W)) == -1)
			return (84);
		board = (t_board *) shmat(shm_id, NULL, SHM_R | SHM_W);
		prepare_board();
	} else
		board = (t_board *) shmat(shm_id, NULL, SHM_R | SHM_W);
	if (init_sem() == 84)
		return (84);
	if (shmctl(shm_id, IPC_RMID, NULL) == -1)
		return (84);
	return (0);
}
