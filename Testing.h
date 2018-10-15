#include <stdio.h>
//#include <stdlib.h>
#include <time.h> //srand(time(NULL))
#define EGG 254 //número 6
#define SNAKE 178 //número 1,2,3,4
#define SNAKE_HEAD 219 //cabeça da cobra
#define BORDER '#' //número 5
#define BLANK ' ' //número 0
#define MAP_WIDTH 80
#define MAP_HEIGHT 20
#define START_POINT 7
#define START_LENGTH 4
#define DELAY_TIME 30000000 //número de ciclos de delay
struct coordenada {
	int x;
	int y;
};
typedef struct coordenada coord;
int interface[MAP_HEIGHT][MAP_WIDTH], //mapa 30/20
length, //comprimento da cobra
maxlength, //comprimento mínimo da cobra
score;
coord egg,
snakeStartPos, //cabeça
snakeEndPos; //final da cauda
void newInterface(); //inicializa a interface
void newEgg(); //adiciona um novo ovo na tela aleatoriamente
void newEndPosition(); //move o final da cobra
int moveUp(); //ao clicar na seta
int moveDown();	//
int moveRight();	//
int moveLeft(); //
int keepDirection(); //move mantendo direção
int verifyHeadUp(); //verifica se é o final da cauda
int verifyHeadDown();	//
int verifyHeadRight(); //
int verifyHeadLeft();	//
void moveHeadUp(); //move a cabeça da cobra
void moveHeadDown();	//
void moveHeadRight();	//
void moveHeadLeft();	//
void showInterface(); //printa
int main(void) {
	int i;
	char input = 0;
	newInterface();
	do {
		system("cls");
		showInterface();
		for (i = 0; i<DELAY_TIME; i++); //Delay
		if (kbhit())
		{
			input = getch();
			switch (input)
			{
			case 'H':
				if (moveUp() == -1) input = 27;
				break;
			case 'P':
				if (moveDown() == -1) input = 27;
				break;
			case 'M':
				if (moveRight() == -1) input = 27;
				break;
			case 'K':
				if (moveLeft() == -1) input = 27;
				break;
			}
		}
		else if (keepDirection() == -1) input = 27;
	} while (input != 27 && length<maxlength);
	printf("\n\n\tGAME OVER!\n");
	if (length == maxlength)printf("\tCongratulations!! You've scored the maximum possible score!!\n");
	//sleep(2);
	getchar();
	getchar();
	return 0;
}
void newInterface() {
	int i, j;
	for (i = 0; i<MAP_HEIGHT; i++)
		for (j = 0; j<MAP_WIDTH; j++)
			if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1)
				interface[i][j] = 5; //BORDER
			else interface[i][j] = 0; //BLANK
			snakeStartPos.x = START_POINT;
			snakeStartPos.y = START_POINT;
			snakeEndPos.x = START_POINT;
			snakeEndPos.y = START_POINT - START_LENGTH + 1;
			maxlength = (MAP_WIDTH - 2)*(MAP_HEIGHT - 2);
			score = 0;
			length = START_LENGTH;
			for (i = 0; i<START_LENGTH; i++)
				interface[START_POINT][START_POINT - i] = 3; //inserção da cobra na interface direcionada para a direita
			newEgg();
			return;
}
void newEgg() {
	if (length<maxlength) {
		srand(time(NULL));
		while (1) {
			egg.x = rand() % (MAP_HEIGHT - 2) + 1;
			egg.y = rand() % (MAP_WIDTH - 2) + 1;
			if (interface[egg.x][egg.y] == 0) { //blank=0
				interface[egg.x][egg.y] = 6; //egg=6
				break;
			}
		}
	}
}
void newEndPosition() {
	switch (interface[snakeEndPos.x][snakeEndPos.y]) {
	case 1: interface[--(snakeEndPos.x) + 1][snakeEndPos.y] = 0;	// blank
		break;
	case 2: interface[++(snakeEndPos.x) - 1][snakeEndPos.y] = 0;	// blank
		break;
	case 3: interface[snakeEndPos.x][++(snakeEndPos.y) - 1] = 0; // blank
		break;
	case 4: interface[snakeEndPos.x][--(snakeEndPos.y) + 1] = 0; // blank
		break;
	}
}
int moveUp() {
	switch (interface[snakeStartPos.x - 1][snakeStartPos.y]) {
	case 0: newEndPosition();
		moveHeadUp();
		return 0;
	case 3:
	case 4: return verifyHeadUp();
	case 2: return keepDirection();
	case 5: return -1;
	case 6: moveHeadUp();
		score += ++length;
		newEgg();
		return 1;
	}
}
int moveDown() {
	switch (interface[snakeStartPos.x + 1][snakeStartPos.y]) {
	case 0: newEndPosition();
		moveHeadDown();
		return 0;
	case 1: return keepDirection();
	case 2:
	case 3:
	case 4: return verifyHeadDown();
	case 5: return -1;
	case 6: moveHeadDown();
		score += ++length;
		newEgg();
		return 1;
	}
}
int moveRight() {
	switch (interface[snakeStartPos.x][snakeStartPos.y + 1]) {
	case 0: newEndPosition();
		moveHeadRight();
		return 0;
	case 2:
	case 3: return verifyHeadRight();
	case 4: return keepDirection();
	case 5: return -1;
	case 6: moveHeadRight();
		score += ++length;
		newEgg();
		return 1;
	}
}
int moveLeft() {
	switch (interface[snakeStartPos.x][snakeStartPos.y - 1]) {
	case 0: newEndPosition();
		moveHeadLeft();
		return 0;
	case 1:
	case 2:
	case 4: return verifyHeadLeft();
	case 3: return keepDirection();
	case 5: return -1;
	case 6: moveHeadLeft();
		score += ++length;
		newEgg();
		return 1;
	}
}
int keepDirection() {
	switch (interface[snakeStartPos.x][snakeStartPos.y]) {
	case 1: return moveUp();
	case 2:	return moveDown();
	case 3:	return moveRight();
	case 4: return moveLeft();
	}
}
int verifyHeadUp() {
	if (snakeEndPos.x == snakeStartPos.x - 1 && snakeEndPos.y == snakeStartPos.y) {
		newEndPosition();
		moveHeadUp();
		return 0;
	}
	else return -1;
}
int verifyHeadDown() {
	if (snakeEndPos.x == snakeStartPos.x + 1 && snakeEndPos.y == snakeStartPos.y) {
		newEndPosition();
		moveHeadDown();
		return 0;
	}
	else return -1;
}
int verifyHeadRight() {
	if (snakeEndPos.x == snakeStartPos.x&&snakeEndPos.y == snakeStartPos.y + 1) {
		newEndPosition();
		moveHeadRight();
		return 0;
	}
	else return -1;
}
int verifyHeadLeft() {
	if (snakeEndPos.x == snakeStartPos.x&&snakeEndPos.y == snakeStartPos.y - 1) {
		newEndPosition();
		moveHeadLeft();
		return 0;
	}
	else return -1;
}
void moveHeadUp() {
	interface[snakeStartPos.x--][snakeStartPos.y] = 1;
	interface[snakeStartPos.x][snakeStartPos.y] = 1;
}
void moveHeadDown() {
	interface[snakeStartPos.x++][snakeStartPos.y] = 2;
	interface[snakeStartPos.x][snakeStartPos.y] = 2;
}
void moveHeadRight() {
	interface[snakeStartPos.x][snakeStartPos.y++] = 3;
	interface[snakeStartPos.x][snakeStartPos.y] = 3;
}
void moveHeadLeft() {
	interface[snakeStartPos.x][snakeStartPos.y--] = 4;
	interface[snakeStartPos.x][snakeStartPos.y] = 4;
}
void showInterface() {
	int i, j;
	printf("\n\tScore: %d\n\t", score);
	for (i = 0; i<MAP_HEIGHT; i++) {
		for (j = 0; j<MAP_WIDTH; j++)
			switch (interface[i][j]) {
			case 0:	printf(" ");
				break;
			case 1:
			case 2:
			case 3:
			case 4:  printf("o");
					else printf("*", SNAKE);
					break;
			case 5: printf("#");
				break;
			case 6: printf("F");
				break;
			}
		printf("\n\t");
	}
	return;
}
