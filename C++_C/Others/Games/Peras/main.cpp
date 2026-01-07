#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <conio.h>
int kbhit() {
	return _kbhit();
}
int getch() {
	return _getch();
}
void sleep(int time_m) {
	_sleep(time_m);
}
#else
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
int kbhit(void) {
	struct termios oldt, newt;
	int ch;
	int oldf;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}
int getch(void) {
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
#endif

char frameBuffer[40][20] = { ' ' };
int points = 0;
int things_n = 0;

void Say_PointsAndCommands(int line) {
	const char* commands[4] = {
		"   [A] -> Andar para a esquerda.",
		"   [S] -> Andar para baixo.",
		"   [D] -> Andar para a direita.",
		"   [W] -> Andar para cima."
	};

	if (line == 4)		printf("  Tens %d pontos.", points);
	else if (line == 5)	printf("  Existe %d peras.", things_n);
	else if (line < 5)	printf(commands[line]);
}
void UpdateFrameBuffer() {
	things_n = 0;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 40; x++) {
			if (y == 0)			frameBuffer[x][y] = '=';
			else if (y == 19)	frameBuffer[x][y] = '=';
			else if (x == 0)	frameBuffer[x][y] = '|';
			else if (x == 39)	frameBuffer[x][y] = '|';
			else if (frameBuffer[x][y] == 'o') things_n++;
			else				frameBuffer[x][y] = ' ';
		}
	}
}
void SpawnThings() {
	srand(time(0));
	int Spawn = rand() % 5;
	if (Spawn == 2) {
		int temp_x = (rand() % 39 - 1) + 1;
		int temp_y = (rand() % 19 - 1) + 1;
		frameBuffer[temp_x][temp_y] = 'o';
	}
}
int main() {
	int sprite_x = 40 / 2;
	int sprite_y = 20 / 2;
	printf("\033[?25l");
	fflush(stdout);
	while (0 == 0) {
		printf("\033[H");
		SpawnThings();
		if (kbhit()) {
			int key = getch();
			switch (key) {
			case 97:
				if (sprite_x > 1)
					sprite_x--;
				break;
			case 100:
				if (sprite_x < 39 - 1)
					sprite_x++;
				break;
			case 115:
				if (sprite_y < 19 - 1)
					sprite_y++;
				break;
			case 119:
				if (sprite_y > 1)
					sprite_y--;
				break;
			}
		}
		frameBuffer[sprite_x][sprite_y] = '@';
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 40; x++) {
				printf("%c", frameBuffer[x][y]);

				if (y == 1 && x == 39)		Say_PointsAndCommands(0);
				else if (y == 2 && x == 39) Say_PointsAndCommands(1);
				else if (y == 3 && x == 39) Say_PointsAndCommands(2);
				else if (y == 4 && x == 39) Say_PointsAndCommands(3);
				else if (y == 5 && x == 39) Say_PointsAndCommands(4);
				else if (y == 6 && x == 39) Say_PointsAndCommands(5);
			}
			printf("\n");
		}
		UpdateFrameBuffer();
		_sleep(20);
	}
	return 0;
}
