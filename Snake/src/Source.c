
#include <stdio.h>
#include <conio.h> // getch()
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h> // For importing SLeep() 
#include "Functions.h"
////////////////////////////////  definitions

////////////////////////////////// prototypes
void Interface_declaration();
void Interface_display();
void _FOOD_GENERATOR();
void MOVE_ONE_BLOCK();
void FIND_FOOD();
void RESET();
void display();
int END_GAME()
{
	system("cls");
	printf("\t\t\tGAME OVER !!!!\n");
	system("pause");
	return 1;
}
//////////////////////////////// WORKING ON NOW /////////////////////////////////////////////////////////////////////////////////////////////////////
void NO_TOUCHING() // Comparing the location of the head to that of the body < need to find a way to compare the head coordinates to that of every node of the snake body . 
{
	//for (i = 0; i<SNAKE_LEN; i++)
	//{

	/*temp = SNAKE_TAIL;
	if (head.x == temp->x && head.y == temp->y)
	{
	END_GAME();
	}
	temp = temp->next;*/
	//}
}
//////////////////////////////// Levels/////////////////////////////////////////////////////////////////////////////////////////////////////

int LEVEL_IMPLEMENTATION()
{
	switch (SCORE)// Increases the level base on the Score 
	{
	case 10:
		LEVEL = 2;
		break;
	case 20:
		LEVEL = 3;
		break;
	}
	switch (LEVEL) // IMplement the new level background 
	{
	case 2:

		// Reset the snake and erase all remaining parts that might have been left behind 
		if (SCORE == 10) // only do this when the 10th food is eaten and it should be done once 
		{
			// Earase the last printed snake 
			while (SNAKE_TAIL != NULL)
			{
				Interface[SNAKE_TAIL->x][SNAKE_TAIL->y] = EMPTY;
				SNAKE_TAIL = SNAKE_TAIL->next;
			}
			SNAKE_LEN = 0;
			SPEED = 190;
			free(SNAKE_TAIL);
		}
		for (i = 6; i < 19; i++)
		{
			Interface[i][17] = BORDER;
		}
		for (i = 6; i < 19; i++)
		{
			Interface[i][52] = BORDER;
		}
		if (head.x == 6 && head.y == 17 || head.x == 7 && head.y == 17 || head.x == 8 && head.y == 17 || head.x == 9 && head.y == 17 || head.x == 10 && head.y == 17 || head.x == 11 && head.y == 17 || head.x == 12 && head.y == 17 || head.x == 13 && head.y == 17 || head.x == 14 && head.y == 17 || head.x == 15 && head.y == 17 || head.x == 16 && head.y == 17 || head.x == 17 && head.y == 17 || head.x == 18 && head.y == 17
			|| head.x == 6 && head.y == 52 || head.x == 7 && head.y == 52 || head.x == 8 && head.y == 52 || head.x == 9 && head.y == 52 || head.x == 10 && head.y == 52 || head.x == 11 && head.y == 52 || head.x == 12 && head.y == 52 || head.x == 13 && head.y == 52 || head.x == 14 && head.y == 52 || head.x == 15 && head.y == 52 || head.x == 16 && head.y == 52 || head.x == 17 && head.y == 52 || head.x == 18 && head.y == 52)
		{
			END_GAME();
			return 1;
		}
		break;
	case 3:     //////////////////////// LEVEL  3 /////////////////////////////
		system("cls");
		printf("\t\t\t");
		puts("LEVEL 3");
		if (SCORE == 20)
		{
			// Earase the last printed snake 
			while (SNAKE_TAIL != NULL)
			{
				Interface[SNAKE_TAIL->x][SNAKE_TAIL->y] = EMPTY;
				SNAKE_TAIL = SNAKE_TAIL->next;
			}
			SNAKE_LEN = 0;
			SPEED = 190;
			free(SNAKE_TAIL);
		}
		////////////////////Display /////////////
		// 1 # 
		for (i = 1; i < 10; i++)
		{
			Interface[i][17] = BORDER;
		}
		// 2 # 
		for (i = 17; i < 28; i++)
		{
			Interface[10][i] = BORDER;
		}
		// 3 # 
		for (i = 1; i < 10; i++)
		{
			Interface[i][52] = BORDER;
		}
		// 4 # 
		for (i = 42; i < 53; i++)
		{
			Interface[10][i] = BORDER;
		}
		// 5 # 
		for (i = 17; i < 53; i++)
		{
			Interface[14][i] = BORDER;
		}
		// 6 # 
		for (i = 14; i < 21; i++)
		{
			Interface[i][35] = BORDER;
		}
		//////////////////////// Interaction ///////////////////////////////////////////
		// 1 # : for (i = 1; i < 10; i++)
		if (head.x == 1 && head.y == 17 || head.x == 2 && head.y == 17 || head.x == 3 && head.y == 17 || head.x == 4 && head.y == 17 || head.x == 5 && head.y == 17 || head.x == 6 && head.y == 17 || head.x == 7 && head.y == 17 || head.x == 8 && head.y == 17 || head.x == 9 && head.y == 17 || head.x == 10 && head.y == 17
			// 2 #: for (i = 17; i < 28; i++)
			|| head.x == 10 && head.y == 17 || head.x == 10 && head.y == 18 || head.x == 10 && head.y == 19 || head.x == 10 && head.y == 20 || head.x == 10 && head.y == 21 || head.x == 10 && head.y == 22 || head.x == 10 && head.y == 23 || head.x == 10 && head.y == 24 || head.x == 10 && head.y == 25 || head.x == 10 && head.y == 26 || head.x == 10 && head.y == 27
			// 3 #: for (i = 1; i < 10; i++)
			|| head.x == 1 && head.y == 52 || head.x == 2 && head.y == 52 || head.x == 3 && head.y == 52 || head.x == 4 && head.y == 52 || head.x == 5 && head.y == 52 || head.x == 6 && head.y == 52 || head.x == 7 && head.y == 52 || head.x == 8 && head.y == 52 || head.x == 9 && head.y == 52 || head.x == 10 && head.y == 52
			// 4 #: for (i = 42; i < 53; i++)
			|| head.x == 10 && head.y == 42 || head.x == 10 && head.y == 43 || head.x == 10 && head.y == 44 || head.x == 10 && head.y == 45 || head.x == 10 && head.y == 46 || head.x == 10 && head.y == 47 || head.x == 10 && head.y == 48 || head.x == 10 && head.y == 49 || head.x == 10 && head.y == 50 || head.x == 10 && head.y == 51 || head.x == 10 && head.y == 52
			// 5 # :for (i = 17; i < 53; i++)
			|| head.x == 14 && head.y == 17 ||
			head.x == 14 && head.y == 18 ||
			head.x == 14 && head.y == 19 ||
			head.x == 14 && head.y == 20 ||
			head.x == 14 && head.y == 21 ||
			head.x == 14 && head.y == 22 ||
			head.x == 14 && head.y == 23 ||
			head.x == 14 && head.y == 24 ||
			head.x == 14 && head.y == 25 ||
			head.x == 14 && head.y == 26 ||
			head.x == 14 && head.y == 27 ||
			head.x == 14 && head.y == 28 ||
			head.x == 14 && head.y == 29 ||
			head.x == 14 && head.y == 30 ||
			head.x == 14 && head.y == 31 ||
			head.x == 14 && head.y == 32 ||
			head.x == 14 && head.y == 33 ||
			head.x == 14 && head.y == 34 ||
			head.x == 14 && head.y == 35 ||
			head.x == 14 && head.y == 36 ||
			head.x == 14 && head.y == 38 ||
			head.x == 14 && head.y == 39 ||
			head.x == 14 && head.y == 40 ||
			head.x == 14 && head.y == 41 ||
			head.x == 14 && head.y == 42 ||
			head.x == 14 && head.y == 43 ||
			head.x == 14 && head.y == 44 ||
			head.x == 14 && head.y == 45 ||
			head.x == 14 && head.y == 46 ||
			head.x == 14 && head.y == 47 ||
			head.x == 14 && head.y == 48 ||
			head.x == 14 && head.y == 49 ||
			head.x == 14 && head.y == 50 ||
			head.x == 14 && head.y == 51 ||
			head.x == 14 && head.y == 52 ||
			// 6 # for (i = 14; i < 21; i++)
			head.x == 14 && head.y == 35 ||
			head.x == 15 && head.y == 35 ||
			head.x == 16 && head.y == 35 ||
			head.x == 17 && head.y == 35 ||
			head.x == 18 && head.y == 35 ||
			head.x == 19 && head.y == 35 ||
			head.x == 20 && head.y == 35
			//head.x == 21 && head.y == 35 ||
			)
		{
			END_GAME();
			return 1;
		}
		break;
	}
	return 0;
}
//////////////////////////////// WORKING ON NOW /////////////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////// Main Function /////////////////////////////////////////////////////////
int main()
{

	//Declaration
	SNAKE_TAIL = NULL;
	Interface_declaration();
	head.x = 9; // Column
	head.y = 39; // ROW
	head.direction = RIGHT;
	Interface[head.x][head.y] = HEAD; // head position 
	_FOOD_GENERATOR();// Only first time food should be place

					  ////////////////////////////// GAME START ///////////////////////////////////////////////////////////////////////
	do {
		system("cls");
		printf("SCORE: %d SNAKE_LEN : %d Snake.x: %d Snake.y: %d\tLevel: %d\n", SCORE, SNAKE_LEN, head.x, head.y, LEVEL);
		Interface_display();
		fflush(stdout);
		Sleep(SPEED);

		if (_kbhit())
		{
			int Input;
			do {
				Input = _getch();
			} while (Input == 224);
			switch (Input)
			{
			case UP:
				if (head.direction == DOWN || Interface[head.x][head.y] == BODY)
				{
					continue;
				}
				head.direction = Input;
				break;
			case DOWN:
				if (head.direction == UP || Interface[head.x][head.y] == BODY)
				{
					continue;
				}
				head.direction = Input;
				break;
			case RIGHT:
				if (head.direction == LEFT || Interface[head.x][head.y] == BODY)
				{
					continue;
				}
				head.direction = Input;
				break;
			case LEFT:
				if (head.direction == RIGHT || Interface[head.x][head.y] == BODY)
				{
					continue;
				}
				head.direction = Input;
				break;
			}
		}

		/////////////////////////////////
		FIND_FOOD();
		NO_TOUCHING();
		if ((LEVEL_IMPLEMENTATION()) == 1)
			return 1;
		///////////////////////
		MOVE_ONE_BLOCK();
		RESET();
		
	} while (head.x >= 1 && head.x <(MAX_X - 1) && head.y >= 1 && head.y < (MAX_Y - 1));
	END_GAME();

	fflush(stdin);
	free(SNAKE_TAIL);
	return 0;
}


///////////////////////////////////////      End      ////////////////////////////////////////////////////////
void RESET()
{
	switch (SNAKE_LEN)
	{
	case 0:
		Interface[SNAKE_TAIL->x][SNAKE_TAIL->y] = EMPTY;
		break;
	case 1:
		Interface[SNAKE_TAIL->next->x][SNAKE_TAIL->next->y] = EMPTY;
		break;
	case 2:
		Interface[SNAKE_TAIL->next->next->x][SNAKE_TAIL->next->next->y] = EMPTY;
		break;
	case 3:
		Interface[SNAKE_TAIL->next->next->next->x][SNAKE_TAIL->next->next->next->y] = EMPTY;
		break;
	case 4:
		Interface[SNAKE_TAIL->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->y] = EMPTY;
		break;
	case 5:
		Interface[SNAKE_TAIL->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->y] = EMPTY;
		break;
	case 6:
		Interface[SNAKE_TAIL->next->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->next->y] = EMPTY;
		break;
	case 7:
		Interface[SNAKE_TAIL->next->next->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->next->next->y] = EMPTY;
		break;
	case 8:
		Interface[SNAKE_TAIL->next->next->next->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->next->next->next->y] = EMPTY;
		break;
	case 9:
		Interface[SNAKE_TAIL->next->next->next->next->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->next->next->next->next->y] = EMPTY;
		break;
	case 10:
		Interface[SNAKE_TAIL->next->next->next->next->next->next->next->next->next->next->x][SNAKE_TAIL->next->next->next->next->next->next->next->next->next->next->y] = EMPTY;
		break;

	}
}
///////////////////////////////////////      End      ////////////////////////////////////////////////////////