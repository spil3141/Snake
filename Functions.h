
#define MAX_X 25
#define MAX_Y 70
#define BORDER 178
#define EMPTY 0 
#define HEAD 2
#define BODY 5
#define FOOD 4
#define RIGHT 'M'
#define LEFT 'K'
#define UP 'H'
#define DOWN 'P'
//////////////////////////////////  variables
int i, j;
int Interface[MAX_X][MAX_Y];
int SNAKE_LEN = 0;
int SCORE = 0;
int SPEED = 190;
int LEVEL = 1;

////////////////////////////////// Structure 
struct COORD {
	int x;
	int y;
	int direction;
}head, food;
struct TAIL {
	int x;
	int y;
	struct TAIL*next;
}*new_tail, *SNAKE_TAIL, *temp;  // SNAKE _TAIL is a buff storing all the location of snake head in a stack data structure 



								 /////////////////////////////////////// Functions /////////////////////////////////////////////////////////

void Insert(int first, int second)
{
	if (SNAKE_TAIL == NULL)
	{
		new_tail = (struct TAIL*) malloc(sizeof(struct TAIL));
		new_tail->x = first;
		new_tail->y = second;
		new_tail->next = NULL;
		SNAKE_TAIL = new_tail;
	}
	else {
		new_tail = (struct TAIL*) malloc(sizeof(struct TAIL));
		new_tail->x = first;
		new_tail->y = second;
		new_tail->next = SNAKE_TAIL;
		SNAKE_TAIL = new_tail;

	}

}

///////////////////////////////////////      1       ////////////////////////////////////////////////////////
void Interface_declaration()
{
	for (i = 0; i < MAX_X; i++)
	{
		for (j = 0; j < MAX_Y; j++)
		{
			if (j == 0 || j == MAX_Y - 1)
				Interface[i][j] = BORDER;
			else if (i == 0 || i == MAX_X - 1)
				Interface[i][j] = BORDER;
			else
				Interface[i][j] = EMPTY;
		}
	}
}
///////////////////////////////////////      2       ////////////////////////////////////////////////////////
void Interface_display()
{
	printf("\n");
	for (i = 0; i < MAX_X; i++)
	{
		printf("\t");
		for (j = 0; j < MAX_Y; j++)
		{
			switch (Interface[i][j])
			{
			case BORDER:
				//printf("%c",BORDER);
				printf("#");
				//printf("5");
				break;
			case EMPTY:
				printf(" ");
				break;
			case HEAD:
				//printf("%c",HEAD);
				printf("#");
				break;
			case FOOD:
				printf("$");
				break;
			case BODY:
				//printf("%c", BODY);
				printf("*");
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
}
///////////////////////////////////////      End      ////////////////////////////////////////////////////////
void _FOOD_GENERATOR()
{
	srand(time(NULL));

	while (1)
	{
		food.y = rand() % 68;
		food.x = rand() % 23;
		if (LEVEL == 2)
		{
			if (food.x == 6 && food.x == 17 || food.x == 7 && food.x == 17 || food.x == 8 && food.x == 17 || food.x == 9 && food.x == 17 || food.x == 10 && food.x == 17 || food.x == 11 && food.x == 17 || food.x == 12 && food.x == 17 || food.x == 13 && food.x == 17 || food.x == 14 && food.x == 17 || food.x == 15 && food.x == 17 || food.x == 16 && food.y == 17 || food.x == 17 && food.y == 17 || food.x == 18 && food.y == 17
				|| food.x == 6 && food.y == 52 || food.x == 7 && food.y == 52 || food.x == 8 && food.y == 52 || food.x == 9 && food.y == 52 || food.x == 10 && food.y == 52 || food.x == 11 && food.y == 52 || food.x == 12 && food.y == 52 || food.x == 13 && food.y == 52 || food.x == 14 && food.y == 52 || food.x == 15 && food.y == 52 || food.x == 16 && food.y == 52 || food.x == 17 && food.y == 52 || food.x == 18 && food.y == 52)
			{
				continue;
			}
		}
		if (food.x > 0 && food.y > 0) // Only allow the placement of food during the first loop 
		{
			Interface[food.x][food.y] = FOOD; // food position
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MOVE_ONE_BLOCK()
{
	switch (head.direction)
	{
	case RIGHT:
		Insert(head.x, head.y);
		Interface[head.x][head.y] = BODY;
		Interface[head.x][(head.y) += 1] = HEAD;
		break;
	case UP:
		Insert(head.x, head.y);
		Interface[head.x][head.y] = BODY;
		Interface[(head.x) -= 1][head.y] = HEAD;
		break;
	case DOWN:
		Insert(head.x, head.y);
		Interface[head.x][head.y] = BODY;
		Interface[(head.x) += 1][head.y] = HEAD;
		break;
	case LEFT:
		Insert(head.x, head.y);
		Interface[head.x][head.y] = BODY;
		Interface[head.x][(head.y) -= 1] = HEAD;
		break;
	}
}
///////////////////////////////////////      End      ////////////////////////////////////////////////////////
void FIND_FOOD()
{
	if (food.x == head.x && food.y == head.y)
	{
		SNAKE_LEN++;
		SCORE++;
		SPEED -= 15;
		if (SPEED <= 1)
		{
			SPEED = 1;
		}
		_FOOD_GENERATOR();
	}
}
///////////////////////////////////////      End      ////////////////////////////////////////////////////////


///////////////////////////////////////      End      ////////////////////////////////////////////////////////
void display()
{
	temp = SNAKE_TAIL;
	while (temp != NULL)
	{
		printf("\nx: %d Y: %d\n", temp->x, temp->y);
		temp = temp->next;
	}
	//system("pause");

}



