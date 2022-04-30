#include "header.h"

int main(void) 
{
	srand((unsigned int)time(NULL));

	char board[MAX_ROWS][MAX_COLS] = { {'\0'} };
	char board_AI[MAX_ROWS][MAX_COLS] = { {'\0'} };

	init_board(board, MAX_ROWS, MAX_COLS);
	init_board(board_AI, MAX_ROWS, MAX_COLS);
	randomly_place_ships_on_board(board_AI, MAX_ROWS, MAX_COLS);

	welcome_screen();
	
	printf("\nWe still have some time before the battle. Would you like to assemble the fleet yourself or let me take care of it?" 
		"                                         (Type 1 for automatic or 2 for manual)\n");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		randomly_place_ships_on_board(board, MAX_ROWS, MAX_COLS);
		print_board(board, MAX_ROWS, MAX_COLS);
	}
	else
	{
		 manually_place_ships_on_board(board, MAX_ROWS, MAX_COLS);
	}

	int turn;
	turn = select_who_starts_first();
	
	if (turn == 1)
	{
		game_sequence1(board, board_AI, MAX_ROWS, MAX_COLS);
	}
	else
	{
		game_sequence2(board, board_AI, MAX_ROWS, MAX_COLS);
	}


	return 0;




	


}