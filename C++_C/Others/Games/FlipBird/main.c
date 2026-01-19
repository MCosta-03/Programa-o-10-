#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
int sprite_x = 40 / 2;
int sprite_y = 20 / 2;
void Say_PointsAndCommands(int line) {
	const char* commands = "   [W] -> Pular";
	if (line == 0)   printf(commands);
	else if (line == 1) printf("  Tens %d pontos.", points);
	else printf("  Tempo: %d:%ds", minute, seconds);
}
void UpdateFrameBuffer() {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 40; x++) {
			if (y == 0)			frameBuffer[x][y] = '=';
			else if (y == 19)	frameBuffer[x][y] = '=';
			else if (x == 0)	frameBuffer[x][y] = '|';
			else if (x == 39)	frameBuffer[x][y] = '|';
			else				frameBuffer[x][y] = ' ';
		}
	}
}
int frames_passed = 0;
int frames_passed_fordown = 0;
void go_down() {
	frames_passed_fordown++;
	if (frames_passed_fordown > 1) {
		sprite_y++;
		frames_passed_fordown = 0;
	}
}
int coluns_x[2] = { 19, 38 };
int cut_line[2] = { 4 };
int line_break[2] = { 0 };
int is_first_colunm[2] = { 0 };
void draw_coluns(int line_n) {
	if (is_first_colunm[line_n] == 0) {
		srand(time(0));
		is_first_colunm[line_n] = 1;
		cut_line[line_n] = (rand() %  10) + 4;
	}
	for (int y = 1; y < 19; y++) {
		if (y != cut_line[line_n] && line_break[line_n] == 0) frameBuffer[coluns_x[line_n]][y] = 'U';
		else line_break[line_n]++;
		if (line_break[line_n] == 4) line_break[line_n] = 0;
	}
	frames_passed++;
	if (frames_passed > 0) {
		coluns_x[line_n]--;
		frames_passed = 0;
		line_break[line_n] = 0;
	}
	if (coluns_x[line_n] == 1) {
		is_first_colunm[line_n] = 0;
		coluns_x[line_n] = 38;
		srand(time(0));
		cut_line[line_n] = rand() % 8;
	}
}
int playGame = 1;
void SayTheMsg(const char* msg) {
	char op = ' ';

	int len = strlen(msg);
	printf("\033[H");
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < len + 5; x++) {
			if (y == 6) printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	printf("\033[H");
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < len + 4; x++) {
			if (y == 0)
				printf("-");
			else if (x == 0 && y != 3)
				printf("| ");
			else if (y == 1 && x == 3)
				printf(msg);
			else if (y == 2 && x < len+1)
				printf(".");
			else if (x == len + 2 && y != 3)
				printf(" |");
			else if (y == 3)
				printf("-");
		}
		printf("\n");
	}

	printf("Disponível: y/n\n");
	printf("Opção:");
	scanf("%c", &op);
	points = 0;

	if (op == 'y')  playGame = 1; 
	else exit(0);
}

void verify_colision() {
	if (frameBuffer[sprite_x + 1][sprite_y] == 'U') {
		playGame = 0;
		SayTheMsg("Perdeste! Jogar outra vez?");
	}
}

void AddPoints() {
	if (coluns_x[0] == sprite_x) points++;
	if (coluns_x[1] == sprite_x) points++;
}

int still_go_down = 0;
int main() {
	printf("\033[?25l");
	fflush(stdout);
	while (0 == 0) {
		printf("\033[H");
		if (playGame == 1) {
			if (kbhit()) {
				int key = getch();
				switch (key) {
				case 115:
					if (sprite_y < 19 - 1)
						sprite_y++;
					still_go_down = 0;
					break;
				case 119:
					if (sprite_y > 1)
						sprite_y--;
					still_go_down = 0;
					break;
				}
			}
			else {
				if (still_go_down == 1) go_down();
				else still_go_down = 1;
			}

			frameBuffer[sprite_x][sprite_y] = '@';
			for (int y = 0; y < 20; y++) {
				for (int x = 0; x < 40; x++) {
					printf("%c", frameBuffer[x][y]);
					if (y == 1 && x == 39)		Say_PointsAndCommands(0);
					else if (y == 2 && x == 39) Say_PointsAndCommands(1);
					else if (y == 3 && x == 39) Say_PointsAndCommands(2);
				}
				printf("\n");
			}
			UpdateFrameBuffer();
			draw_coluns(0);
			draw_coluns(1);
			AddPoints();
			count_time(50);
		}
		verify_colision();
		_sleep(50);
	}
	return 0;
}
