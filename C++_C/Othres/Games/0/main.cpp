#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

    printf("\033[?25l");
    fflush(stdout);

    char frameBuffer[40][20];
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 40; x++)
            frameBuffer[x][y] = ' ';

    int carac_x = 0;
    int carac_y = 0;
    int Xdirection = 0;
    int Ydirection = 0;
    int corner = 0;

    while (0 == 0) {
        printf("\033[H");


        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                if (y == 0) {
                    frameBuffer[x][y] = '_';
                }
                else if (y == 19) {
                    frameBuffer[x][y] = 'T';
                }
                else {
                    frameBuffer[x][y] = ' ';
                }
                if (x == 39) {
                    frameBuffer[x][y] = '|';
                }
                else if (x == 0) {
                    frameBuffer[x][y] = '|';
                }
            }
        }

        if (carac_x > 37) {
            Xdirection = 0;
        }
        if (carac_x < 2) {
            Xdirection = 1;
        }
        if (carac_y > 17) {
            Ydirection = 0;
        }
        if (carac_y < 2) {
            Ydirection = 1;
        }
        if (Xdirection == 0) {
            carac_x--;
        }
        if (Xdirection == 1) {
            carac_x++;
        }
        if (Ydirection == 0) {
            carac_y--;
        }
        if (Ydirection == 1) {
            carac_y++;
        }

        if (carac_x == 37 && carac_y == 18) {
            corner++;
        }
        if (carac_x == 2 && carac_y == 2) {
            corner++;
        }
        if (carac_x == 37 && carac_y == 2) {
            corner++;
        }
        if (carac_x == 2 && carac_y == 37) {
            corner++;
        }

        frameBuffer[carac_x][carac_y] = '@';
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                printf("%c", frameBuffer[x][y]);
            }

            if (y == 0) {
                printf("        Bateu no canto %d vezes", corner);
            }
            printf("%c", '\n');
        }
        _sleep(40);
    }
	
	return 0;
}