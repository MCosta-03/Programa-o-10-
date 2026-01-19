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

int sleep_time_temp = 0;
int seconds = 0, minute = 0;
void count_time(int sleep_time) {
	sleep_time_temp += sleep_time;
	if (sleep_time_temp >= 600) {
		sleep_time_temp = 0;
		seconds++;
	}
	if (seconds == 60) {
		seconds = 0;
		minute++;
	}
}

char frameBuffer[40][20] = { ' ' };
int points = 0;
int things_n = 0, last_things_n = 0;
int sprite_x = 40 / 2;
int sprite_y = 20 / 2;

void Say_PointsAndCommands(int line) {
	const char* commands[4] = {
		"   [A] -> Andar para a esquerda.",
		"   [S] -> Andar para baixo.",
		"   [D] -> Andar para a direita.",
		"   [W] -> Andar para cima."
	};

	if (line == 4)		printf("  Tens %d pontos.", points);
	else if (line == 5)	printf("  Existe %d peras.", things_n);
	else if (line == 6)	printf("  Tempo: %d:%ds", minute, seconds);
	else if (line < 6)	printf(commands[line]);
}
void GivePoints() {
	if (things_n < last_things_n) points++;
}
int go_to_x = 0, go_to_y = 0;
void UpdateFrameBuffer() {
	last_things_n = things_n;
	things_n = 0;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 40; x++) {
			if (y == 0)			frameBuffer[x][y] = '=';
			else if (y == 19)	frameBuffer[x][y] = '=';
			else if (x == 0)	frameBuffer[x][y] = '|';
			else if (x == 39)	frameBuffer[x][y] = '|';
			else if (frameBuffer[x][y] == 'o') {
				things_n++;
				go_to_x = x;
				go_to_y = y;
			}
			else				frameBuffer[x][y] = ' ';
		}
	}
}
void SpawnThings() {
	srand(time(0));
	int Spawn = rand() % 3;
	if (Spawn == 2) {
		int temp_x = (rand() % 39 - 1) + 1;
		int temp_y = (rand() % 19 - 1) + 1;
		frameBuffer[temp_x][temp_y] = 'o';
	}
}

void PlayAlone() {
	if (things_n != 0) {
		if (go_to_x > sprite_x) sprite_x++;
		if (go_to_y > sprite_y) sprite_y++;
		if (go_to_x < sprite_x) sprite_x--;
		if (go_to_y < sprite_y) sprite_y--;
	}
}
int main() {
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
				else if (y == 7 && x == 39) Say_PointsAndCommands(6);
			}
			printf("\n");
		}
		GivePoints();
		UpdateFrameBuffer();
		PlayAlone();
		count_time(50);
		_sleep(50);
	}
	return 0;
}
