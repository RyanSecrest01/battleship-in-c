#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

/*
Ryan Secrest
CPTS 121
PA6 Battleship
11/8/20
Notes:
	after the first round of exchanges, you will be able to see the enemy board for testing purposes
	to disable, lines 345 and 432 printboard function needs to be removed. 
Known Issues: 
	-player accuracy log is incorrect
	-checking for enemy ship overlap doesn't work, creates impossible win scenario
*/

#define MAX_ROWS 10
#define MAX_COLS 10

void welcome_screen();

void init_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols);
void print_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols);

int select_who_starts_first();

void manually_place_ships_on_board();

void place_ships_on_board();

void randomly_place_ships_on_board();

char check_shot(char board[MAX_ROWS][MAX_COLS], int row, int column);

int is_winner(char board[MAX_ROWS][MAX_COLS], char board_AI[MAX_ROWS][MAX_COLS], int hits);

void update_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols);

void output_current_move();

int check_if_sunk_ship();

void output_stats();

void game_sequence1();

void game_sequence2();

void output_stats(FILE* battleship, int number, int row, int column, char outcome, int hits, int misses, int shots, int check);