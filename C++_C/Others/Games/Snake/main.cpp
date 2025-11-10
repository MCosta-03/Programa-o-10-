#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
int kbhit(void) {
    return _kbhit();
}
int getch(void) {
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
    tcgetattr(STDIN_FILENO, &oldt); // salva configurações atuais
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // desabilita modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura configurações
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
void sleep(int time_m) {
    usleep(time_m * 1000);
}
#endif
int main() {
    printf("\033[?25l");
    fflush(stdout);

    int snake_pos_x = 10;
    int snake_pos_y = 10;
    int snake_direction = 0;
    int snake_size = 1;
    int snake_body_count_x = 0;
    int snake_body_count_y = 0;

    int snake_area[38][18] = { 0 };

    int snake_body_pos_x[10] = { 0 };
    int snake_body_pos_y[10] = { 0 };

    char frameBuffer[40][20];
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 40; x++)
            frameBuffer[x][y] = ' ';
    for (int y = 0; y < 18; y++)
        for (int x = 0; x < 38; x++)
            snake_area[x][y] = ' ';
    while (0 == 0) {
        sleep(200);
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
                    frameBuffer[x][y] = 'M';
                }
                else if (x == 0) {
                    frameBuffer[x][y] = 'M';
                }

            }
        }
        if (kbhit()) {
            int key = getch();
            switch (key) {
            case 97:
                snake_direction = 1;
                break;
            case 100:
                snake_direction = 2;
                break;
            case 115:
                snake_direction = 3;
                break;
            case 119:
                snake_direction = 4;
                break;
            }
        }
        /*Draw snake*/
        //for(int y = snake_pos_y; y < snake_pos_y; y++)
        if (snake_pos_x == 38 - snake_size || snake_pos_y == 18 - snake_size) {
            //snake_direction = 0;
        }
        switch (snake_direction) {
        case 1:
            snake_pos_x--;
            snake_area[snake_pos_x][snake_pos_y] = '#';
            //frameBuffer[snake_pos_x][snake_pos_y] = '#';
            break;
        case 2:
            snake_pos_x++;
            snake_area[snake_pos_x][snake_pos_y] = '#';
            //frameBuffer[snake_pos_x][snake_pos_y] = '#';
            break;
        case 3:
            snake_pos_y++;
            snake_area[snake_pos_x][snake_pos_y] = '#';
            //frameBuffer[snake_pos_x][snake_pos_y] = '#';
            break;
        case 4:
            snake_pos_y--;
            snake_area[snake_pos_x][snake_pos_y] = '#';
            //frameBuffer[snake_pos_x][snake_pos_y] = '#';
            break;
        }

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                if (x > 1 && y > 1 && x < 38 && y < 18) {
                    frameBuffer[x][y] = snake_area[x-1][y-1];
                }
                printf("%c", frameBuffer[x][y]);
            }
            printf("%c", '\n');
        }
        snake_size++;
    }
    return 0;
}

/*#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
int kbhit(void) {
    return _kbhit();
}
int getch(void) {
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
    tcgetattr(STDIN_FILENO, &oldt); // salva configurações atuais
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // desabilita modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura configurações
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
void sleep(int time_m) {
    usleep(time_m * 1000);
}
#endif
int main() {
    printf("\033[?25l");
    fflush(stdout);

    int snake_pos_x = 10;
    int snake_pos_y = 10;
    int snake_direction = 0;
    int snake_size = 3;
    int snake_body_count = 0;

    int snake_body_pos_x[10] = { 0 };
    int snake_body_pos_y[10] = { 0 };

    char frameBuffer[40][20];
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 40; x++)
            frameBuffer[x][y] = ' ';
    while (0 == 0) {
        sleep(200);
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
                    frameBuffer[x][y] = 'M';
                }
                else if (x == 0) {
                    frameBuffer[x][y] = 'M';
                }
            }
        }
        if (kbhit()) {
            int key = getch();
            switch (key) {
            case 97:
                snake_direction = 1;
                break;
            case 100:
                snake_direction = 2;
                break;
            case 115:
                snake_direction = 3;
                break;
            case 119:
                snake_direction = 4;
                break;
            }
        }
        /*Draw snake*/
        //for(int y = snake_pos_y; y < snake_pos_y; y++)
        if (snake_pos_x == 38 - snake_size || snake_pos_y == 18 - snake_size) {
            //snake_direction = 0;
        }
        switch (snake_direction) {
        case 1:
            snake_pos_x--;
            frameBuffer[snake_pos_x][snake_pos_y] = '#';
            for (int i = 0; i < snake_size; i++) {
                if (snake_body_pos_y[i] != 0)
                    snake_body_pos_x[i]--;
                if (snake_body_pos_y[i] > 0)
                    snake_body_pos_y[i]--;
            }
            break;
        case 2:
            snake_pos_x++;
            frameBuffer[snake_pos_x][snake_pos_y] = '#';
            for (int i = 0; i < snake_size; i++) {
                if (snake_body_pos_y[i] != 0)
                    snake_body_pos_x[i]++;
                if (snake_body_pos_y[i] > 0)
                    snake_body_pos_y[i]--;
            }
            break;
        case 3:
            snake_pos_y++;
            frameBuffer[snake_pos_x][snake_pos_y] = '#';
            for (int i = 0; i < snake_size; i++) {
                if (snake_body_pos_y[i] < snake_size)
                    snake_body_pos_y[i] = i;
                if (snake_body_pos_x[i] > 0)
                    snake_body_pos_x[i]--;
            }
            break;
        case 4:
            snake_pos_y--;
            frameBuffer[snake_pos_x][snake_pos_y] = '#';

            for (int i = 0; i < snake_size; i++) {
                if (snake_body_pos_y[i] < snake_size)
                    snake_body_pos_y[i] = i;
                if (snake_body_pos_x[i] > 0)
                    snake_body_pos_x[i]--;
            }
            break;
        }

        for(int i = 0; i < snake_size; i++)
            frameBuffer[snake_pos_x - snake_body_pos_x[i]][snake_pos_y - snake_body_pos_y[i]] = '#';

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                printf("%c", frameBuffer[x][y]);
            }
            printf("%c", '\n');
        }
    }
    return 0;
}*/
