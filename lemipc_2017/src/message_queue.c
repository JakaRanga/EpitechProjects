/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** msg q
*/

#include "../include/lem.h"

void send_msg(char *m)
{
	t_msgq msg;

	msg.mtype = 1;
	sprintf(msg.mtext, "%s", m);
	msgsnd(team.msgid, &msg, sizeof(msg.mtext), 0);
}

void receive_msg(void)
{
	static int i = 0;
	static char *m;
	t_msgq msg;

	if (i == 0) {
		msgrcv(team.msgid, &msg, sizeof(msg.mtext), 1, 0);
		m = strdup(msg.mtext);
	}
	printf("%s\n", m);
	i++;
}
