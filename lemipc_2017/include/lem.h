/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** .h
*/

#ifndef LEM_H_
# define LEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define SIZE_Y	5
#define SIZE_X  5

#define MAXLEN	128

typedef struct	s_msgq
{
	long	mtype;
	char	mtext[MAXLEN];
} t_msgq;

typedef struct	s_params
{
	int	team_nb;
	char	*path;
} t_params;

typedef struct	s_board
{
	int	map[SIZE_Y][SIZE_X];
} t_board;

typedef struct	s_team
{
	key_t		key;
	int		semid;
	int		msgid;
	int		isfirst;
	int		pos_x;
	int		pos_y;
} t_team;

extern t_board	*board;
extern t_team	team;
extern t_params	params;

void	help(void);
void	prepare_board(void);
void	print_board(void);
void	sem_decr(void);
void	sem_incr(void);
void	send_msg(char*);
void	receive_msg(void);
void	moves(void);
int	player_loop(void);
int	place_player(void);
int	init_shm(void);
int	is_another_team(void);
int	get_killed(void);
int	can_move(int, int);
int	my_rand(int);
int	find_the_nearest(void);

#endif /* !LEM_H_ */
