#include "header.h"

void init_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		for (int col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	printf("    0   1   2   3   4   5   6   7   8   9\n");
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		printf("%d ", row_index);
		for (int col_index = 0; col_index < cols; ++col_index)
		{
			printf("| %c ", board[row_index][col_index]);
		}
		printf("|\n");
	}
}

void welcome_screen()
{
	printf("                                           Welcome to the game of battleship!");
	printf("\nRules: ");
	printf("\n                                        Battleship is a two player Navy game." 
		"\n                            The objective of the game is to sink all ships in your enemy's fleet."
		"\n                                     The Player to sink his/her enemy's fleet first wins." 
		"\n                            Both players' fleets consist of 5 ships that are hidden from the enemy."
		"\n                        Each ship may be differentiated by its 'size' (besides the Cruiser and Submarine)" 
		"\n                                      or number of cells it expands on the game board."
		"\n                    The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells," 
		"\n                                             and the Destroyer has 2 cells.\n");

	printf("\n                                                  Hit Enter to START\n");

	while (getchar() != '\n');
}

int select_who_starts_first()
{
	

	int num = (rand() % (2 - 1 + 1)) + 1;

	printf("\n                                                Player%d will go first\n\n\n", num);

	return num;
}

void manually_place_ships_on_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	print_board(board, MAX_ROWS, MAX_COLS);

	char choice = '\0';
	int length;
	char type = '\0';
	printf("\nFirst, you will place the carrier. Do you want it veritical or horizontal? (v or h)\n");
	scanf(" %c", &choice);

	length = 5;
	type = 'c';
	place_ships_on_board(board, MAX_ROWS, MAX_COLS, choice, length, type);
	print_board(board, MAX_ROWS, MAX_COLS);

	//

	printf("\nSecond, you will place the battleship. Do you want it veritical or horizontal? (v or h)\n");
	scanf(" %c", &choice);

	length = 4;
	type = 'b';
	place_ships_on_board(board, MAX_ROWS, MAX_COLS, choice, length, type);
	print_board(board, MAX_ROWS, MAX_COLS);

	//

	printf("\nThird, you will place the cruiser. Do you want it veritical or horizontal? (v or h)\n");
	scanf(" %c", &choice);

	length = 3;
	type = 'r';
	place_ships_on_board(board, MAX_ROWS, MAX_COLS, choice, length, type);
	print_board(board, MAX_ROWS, MAX_COLS);

	//

	printf("\nFourth, you will place the submarine. Do you want it veritical or horizontal? (v or h)\n");
	scanf(" %c", &choice);

	length = 3;
	type = 's';
	place_ships_on_board(board, MAX_ROWS, MAX_COLS, choice, length, type);
	print_board(board, MAX_ROWS, MAX_COLS);

	//

	printf("\nLast, you will place the destroyer. Do you want it veritical or horizontal? (v or h)\n");
	scanf(" %c", &choice);

	length = 2;
	type = 'd';
	place_ships_on_board(board, MAX_ROWS, MAX_COLS, choice, length, type);
	print_board(board, MAX_ROWS, MAX_COLS);
}

void randomly_place_ships_on_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols, char choice)
{
	int direction, x, y, length;
	char type;

	direction = (rand() % (2 - 1 + 1)) + 1;
	x = (rand() % (1 - 0 + 1)) + 0;
	y = (rand() % (1 - 0 + 1)) + 0;

	length = 5;
	type = 'c';
	
	if (direction == 1)
	{
		for (int i = 0; i < length; i++)
		{
			board[x + i][y] = type;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			board[x][y + i] = type;
		}
	}

	//

	direction = (rand() % (2 - 1 + 1)) + 1;
	x = (rand() % (5 - 4 + 1)) + 4;
	y = (rand() % (2 - 0 + 1)) + 0;

	length = 4;
	type = 'b';

	if (direction == 1)
	{
		for (int i = 0; i < length; i++)
		{
			board[x + i][y] = type;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			board[x][y + i] = type;
		}
	}

	//

	direction = (rand() % (2 - 1 + 1)) + 1;
	x = (rand() % (2 - 0 + 1)) + 0;
	y = (rand() % (6 - 5 + 1)) + 5;

	length = 3;
	type = 'r';

	if (direction == 1)
	{
		for (int i = 0; i < length; i++)
		{
			board[x + i][y] = type;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			board[x][y + i] = type;
		}
	}

	//

	direction = (rand() % (2 - 1 + 1)) + 1;
	x = (rand() % (7 - 6 + 1)) + 6;
	y = (rand() % (7 - 6 + 1)) + 6;

	length = 3;
	type = 's';

	if (direction == 1)
	{
		for (int i = 0; i < length; i++)
		{
			board[x + i][y] = type;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			board[x][y + i] = type;
		}
	}

	//

	direction = (rand() % (2 - 1 + 1)) + 1;
	x = (rand() % (8 - 7 + 1)) + 7;
	y = (rand() % (8 - 7 + 1)) + 7;

	length = 2;
	type = 'd';

	if (direction == 1)
	{
		for (int i = 0; i < length; i++)
		{
			board[x + i][y] = type;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			board[x][y + i] = type;
		}
	}
}

void place_ships_on_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols, char choice, int length, char type)
{

	if (choice == 'v')
	{
		int row, column;
		printf("\nEnter the coordinate of where you want the top of the ship to be. (row column)\n");
		scanf("%d %d", &row, &column);

		for (int i = 0; i < length; i++)
		{
			board[row + i][column] = type;
		}
	}
	else
	{
		int row, column;
		printf("\nEnter the coordinate of where you want the left of the ship to be. (row column)\n");
		scanf("%d %d", &row, &column);

		for (int i = 0; i < length; i++)
		{
			board[row][column + i] = type;
		}
	}
}

void game_sequence1(char board[MAX_ROWS][MAX_COLS], char board_AI[MAX_ROWS][MAX_COLS])
{
	FILE* battleship = NULL; // initializing output file

	battleship = fopen("battleship.log", "w"); // opening/creating the output file and allowing us to edit it

	int row, column, player, check = 1, hits = 0, misses = 0, shots = 0;
	char outcome = '\0';

	player = 1;
	printf("\nCommander! The battle has started! We snuck up on the enemy and can attack first! \nOur radars are jammed so you'll have to guess coordinates for now!\n");
	scanf("%d %d", &row, &column);

	outcome = check_shot(board_AI, row, column);

	switch (outcome)
	{
	case 'h':
		hits = hits + 1;
		shots = shots + 1;
		break;

	case 'm':
		misses = misses + 1;
		shots = shots + 1;
		break;

	default:
		break;
	}

	output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);

	printf("\nThe enemy is returning fire!\n");

	player = 2;
	row = (rand() % (9 - 0 + 1)) + 0;
	column = (rand() % (9 - 0 + 1)) + 0;

	outcome = check_shot(board, row, column); // checking enemy fire
	output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);
	print_board(board, MAX_ROWS, MAX_COLS);

	while (check == 1)
	{
		player = 1;
		scanf("%d %d", &row, &column);

		outcome = check_shot(board_AI, row, column);

		switch (outcome)
		{
		case 'h':
			hits = hits + 1;
			shots = shots + 1;
			break;

		case 'm':
			misses = misses + 1;
			shots = shots + 1;
			break;

		default:
			break;
		}

		output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);

		player = 2;
		row = (rand() % (9 - 0 + 1)) + 0;
		column = (rand() % (9 - 0 + 1)) + 0;

		outcome = check_shot(board, row, column); // checking enemy fire
		output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);
		print_board(board, MAX_ROWS, MAX_COLS);

		check = is_winner(board, board_AI, hits);

		// 

		printf("\nEnemy Board: (for testing purposes and speeding up the game)\n");
		print_board(board_AI, MAX_ROWS, MAX_COLS);
	}
	output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);
}

void game_sequence2(char board[MAX_ROWS][MAX_COLS], char board_AI[MAX_ROWS][MAX_COLS])
{
	FILE* battleship = NULL; // initializing output file

	battleship = fopen("battleship.log", "w"); // opening/creating the output file and allowing us to edit it

	int row, column, player, check = 1, hits = 0, misses = 0, shots = 0;
	char outcome = '\0';

	player = 2;
	row = (rand() % (9 - 0 + 1)) + 0;
	column = (rand() % (9 - 0 + 1)) + 0;

	outcome = check_shot(board, row, column);

	output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);

	print_board(board, MAX_ROWS, MAX_COLS);
	
	printf("\nCommander! The enemy is firing at us! Check the board to see if we have been hit (*)," 
		"hopefully they missed (m). \nLet's get on the counterattack!" 
		"Our radars are jammed so you'll have to guess coordinates for now!\n");
	scanf("%d %d", &row, &column);

	outcome = check_shot(board_AI, row, column); // checking player fire

	switch (outcome)
	{
	case 'h':
		hits = hits + 1;
		shots = shots + 1;
		break;

	case 'm':
		misses = misses + 1;
		shots = shots + 1;
		break;

	default:
		break;
	}

	while (check == 1)
	{
		player = 2;
		row = (rand() % (9 - 0 + 1)) + 0;
		column = (rand() % (9 - 0 + 1)) + 0;

		outcome = check_shot(board, row, column); // checking enemy fire

		output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);

		print_board(board, MAX_ROWS, MAX_COLS);

		player = 1;
		scanf("%d %d", &row, &column);

		outcome = check_shot(board_AI, row, column); // checking player fire

		switch (outcome)
		{
		case 'h':
			hits = hits + 1;
			shots = shots + 1;
			break;

		case 'm':
			misses = misses + 1;
			shots = shots + 1;
			break;

		default:
			break;
		}

		output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);

		check = is_winner(board, board_AI, hits);

		//

		printf("\nEnemy Board: (for testing purposes and speeding up the game)\n");
		print_board(board_AI, MAX_ROWS, MAX_COLS);
	}
	output_stats(battleship, player, row, column, outcome, hits, misses, shots, check);
}

char check_shot(char board[MAX_ROWS][MAX_COLS], int row, int column)
{
	/*switch (board[row][column]) 
	{
	case '~':
		board[row][column] = 'm';
		break;

	case 'c':
	case 'b':
	case 'r':
	case 's':
	case 'd':
		board[row][column] = '*';
		break;

	default:
		break;
	}
	*/

	if (board[row][column] == 'c' || board[row][column] == 'b' || board[row][column] == 'r' || board[row][column] == 's' || board[row][column] == 'd')
	{
		board[row][column] = '*';
		
		printf("\nHIT\n");

		return 'h';
	}
	else if (board[row][column] == '~')
	{
		board[row][column] = 'm';

		printf("\nMISS\n");

		return 'm';
	}
	else 
	{
		return 'a';
	}
}

int is_winner(char board[MAX_ROWS][MAX_COLS], char board_AI[MAX_ROWS][MAX_COLS], int hits)
{
	/*for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (board[i][j] == 'c' || board[i][j] == 'b' || board[i][j] == 'r' || board[i][j] == 's' || board[i][j] == 'd')
			{
				check = check + 1;
			}
		}
	}
	*/
	if (hits == 17)
		return 0;
	else
		return 1;
}

void output_stats(FILE* battleship, int number, int row, int column, char outcome, int hits, int misses, int shots, int check)
{
	struct Players
	{
		int hits;
		int misses;
		int shots;
		double accuracy;
	};

	struct Players Player1;
	struct Players Player2;

	if (check == 1)
	{
		switch (outcome)
		{
		case 'h':
			fprintf(battleship, "Player%d: %d,%d \"hit\"\n", number, row, column);
			break;

		case 'm':
			fprintf(battleship, "Player%d: %d,%d \"miss\"\n", number, row, column);
			break;

		default:
			break;
		}
	}
	else
	{
		Player1.hits = hits;
		Player1.misses = misses;
		Player1.shots = shots;
		Player1.accuracy = hits / misses;

		Player2.hits = hits;
		Player2.misses = misses;
		Player2.shots = shots;
		Player2.accuracy = hits / misses;

		printf("\nPlayer1 wins!\n");

		fprintf(battleship, "\nPlayer1 wins, PLayer2 loses\n");
		fprintf(battleship, "*** PLayer1 Stats ***\n");
		fprintf(battleship, "Number Hits: %d\n", Player1.hits);
		fprintf(battleship, "Number Misses: %d\n", Player1.misses);
		fprintf(battleship, "Number Shots: %d\n", Player1.shots);
		fprintf(battleship, "Number Hit/Miss Ratio: %lf\n", Player1.accuracy);

		fprintf(battleship, "\n*** Player2 Stats ***\n");
		fprintf(battleship, "Number Hits: %d\n", Player2.hits);
		fprintf(battleship, "Number Misses: %d\n", Player2.misses);
		fprintf(battleship, "Number Shots: %d\n", Player2.shots);
		fprintf(battleship, "Number Hit/Miss Ratio: %lf\n", Player2.accuracy);

		fclose(battleship);
	}
}



