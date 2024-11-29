#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include<unistd.h>
#define MAX_WORD_LENGTH 15

// Maze Game
char maze[16][16] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, //0
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'}, //1
    {'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'}, //2
    {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'}, //3
    {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'}, //4
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'}, //5
    {'.', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'}, //6
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'}, //7
    {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#'}, //8
    {'#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '#', '.', '#'}, //9
    {'#', '.', '#', '.', '.', '.', '#', '.', '#', '.', '.', '#', '.', '#', '.', '#'}, //10
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '.', '#', '.', '#', '.', '#'}, //11
    {'#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'}, //12
    {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#'}, //13
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'}, //14
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '!', '#', '#'} //15
    // ... (your maze layout)
};



void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_maze2() {
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    gotoxy(40, 7);
    printf("PRESS 'i' TO READ INSTRUCTIONS");
    gotoxy(40, 8);
    printf("PRESS 'm' TO EXIT");
}

void instructions() {
    printf("\n\n\t\t\tINSTRUCTIONS : \n\n\n\t\t\tHELP THE SNAIL TO GET ACROSS THE MAZE");
    printf("\n\t\tUSE 'w' 'a' 's' 'd' TO MOVE\n\t\t\tPRESS 'm' TO EXIT\n\t\t\tGOOD LUCK..!!");
    getch();
    system("cls");
}

void playMazeGame() {
    char a, b;
    int x, y;
    x = 1;
    y = 6;

    printf("\n\n\n\n\n\n\n\n\t\t ______________");
    printf("\n\t\t|**WELCOME TO THE MAZE GAME**|");
    sleep(1);
	system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 3");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 2");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tYOUR GAME STARTS IN ..... 1");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t**LET'S GO**");
    sleep(1);
    system("cls");
    b = 'i';

    while (b != 'm') {
        if (x == 1 && y == 6) {
            system("cls");
            print_maze2();
            gotoxy(x * 2, y);
            printf("@");

        while(1){
                if (kbhit()) {
                    a = getch();

                    int newX = x, newY = y;
                    switch (a) {
                        case 'a': newX--; break;//left arrow
                        case  'd':newX++; break;//right arrow
                        case 's': newY++; break;//down arrow
                        case 'w': newY--; break;//up arrow
                        case 'i':
                            system("cls");
                            instructions();
                            continue;
                        case 'm':
                            b = 'm';
                            break;
                    }
						if(b=='m'){
							break;
						}
                    if (maze[newY][newX] != '#') {
                        x = newX;
                        y = newY;
                    }

                    system("cls");
                    print_maze2();
                    gotoxy(x * 2, y);
                    printf("0");

                    if (x == 13 && y == 15) {
                        system("cls");
                        printf("\n\n\t\t\t    CONGRATULATIONS.. YOU WIN!!\n\n\t\t\t  PRESS 'm' TO QUIT THE GAME");
                        scanf(" %c", &b);
                        if (!(b == 'm')) {
                            system("cls");
                            printf("\n\n\n\t\t\t\t WE HOPE TO SEE YOU AGAIN....!!");
                            getch();
                        }
                        break;
                    }
                }
        	}
        }
    }
}

