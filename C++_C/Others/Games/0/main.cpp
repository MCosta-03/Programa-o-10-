#include <stdlib.h>
#include <stdio.h>

const char Corner_frames[4][5][5] = {
    '*', '*', '*', '*', ' ',
    '*', '*', '*', ' ', ' ',
    '*', '*', ' ', ' ', ' ',
    '*', '*', ' ', ' ', ' ',
    '*', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', '*',
    ' ', ' ', ' ', '*', '*',
    ' ', ' ', '*', '*', '*',
    ' ', '*', '*', '*', '*',
    '*', '*', '*', '*', '*',
    '*', ' ', ' ', ' ', ' ',
    '*', '*', ' ', ' ', ' ',
    '*', '*', '*', ' ', ' ',
    '*', '*', '*', '*', ' ',
    '*', '*', '*', '*', '*',//----------------
    ' ', '*', '*', '*', '*',
    ' ', ' ', '*', '*', '*',
    ' ', ' ', ' ', '*', '*',
    ' ', ' ', ' ', ' ', '*'
};

const char Bar[5] = {
    '=', '=', '=', '=', '='
};

int main() {
    printf("\033[?25l");
    fflush(stdout);

    char frameBuffer[40][20];
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 40; x++)
            frameBuffer[x][y] = ' ';

    int carac_x = 40 / 2;
    int carac_y = 20 / 2;
    int Xdirection = 0;
    int Ydirection = 0;
    int corner = 0;
    int show_corner = 0;
    int show_corner_type_pos = 0;
    int bar_pos;

    while (0 == 0) {
        _sleep(20);
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

        for (int x = 0; x < 5; x++) {
            frameBuffer[x+1][2] = Bar[x];
        }

        if()

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

        if (carac_x == 38 && carac_y == 18) {
            corner++;
            show_corner = 1;
            show_corner_type_pos = 1;
        }
        if (carac_x == 1 && carac_y == 1) {
            corner++;
            show_corner = 1;
            show_corner_type_pos = 2;
        }
        if (carac_x == 38 && carac_y == 1) {
            corner++;
            show_corner = 1;
            show_corner_type_pos = 3;
        }
        if (carac_x == 1 && carac_y == 38) {
            corner++;
            show_corner = 1;
            show_corner_type_pos = 4;
        }

        if (show_corner > 0) {
            show_corner++;
            switch (show_corner_type_pos) {
            case 1:
                for (int Y = 0; Y < 5; Y++) {
                    for (int X = 0; X < 5 + 1; X++) {
                        frameBuffer[X + (40 - 7)][Y + (20 - 6)] = Corner_frames[1][Y][X];
                    }
                }
                break;
            case 2:
                for (int Y = 0; Y < 5; Y++) {
                    for (int X = 0; X < 5 + 1; X++) {
                        frameBuffer[X + 1][Y + 1] = Corner_frames[0][X][Y];
                    }
                }
                break;
            case 3:
                for (int Y = 0; Y < 5; Y++) {
                    for (int X = 0; X < 5 + 1; X++) {
                        frameBuffer[X + (40 - 7)][Y + 1] = Corner_frames[3][X][Y];
                    }
                }
                break;
            case 4:
                for (int Y = 0; Y < 5; Y++) {
                    for (int X = 0; X < 5 + 1; X++) {
                        frameBuffer[X + 1][Y + (20 - 6)] = Corner_frames[2][X][Y];
                    }
                }
                break;
            }
        }
        if (show_corner > 10) {
            show_corner = 0;
        }
        frameBuffer[carac_x][carac_y] = 'O';

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                printf("%c", frameBuffer[x][y]);
            }

            if (y == 0) {
                printf("    Bateu no canto %d vezes", corner);
            }
            if (y == 2) {
                printf("    [A] para andar para a esquerda", corner);
            }
            if (y == 3) {
                printf("    [D] para andar para a direita.", corner);
            }
            printf("%c", '\n');
        }
    }
    return 0;
}
