/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** prepare board
*/

#include "../include/lem.h"

void prt_the_char(int c)
{
	if (c != 0)
		printf("%i", c);
	else
		putchar('.');
}

void print_board(void)
{
	printf("Game Board :\n");
	for (int i = 0; i != SIZE_Y; i++) {
		for (int j = 0; j != SIZE_X; j++)
			prt_the_char(board->map[i][j]);
		putchar('\n');
	}
}

void prepare_board(void)
{
	for (int i = 0; i < SIZE_Y; i++)
		for (int j = 0; j < SIZE_X; j++)
			board->map[i][j] = 0;
}
