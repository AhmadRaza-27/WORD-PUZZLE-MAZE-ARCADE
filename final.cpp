#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#define MAX_WORD_LENGTH 15

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
void print_maze2(int x, int y) {
    // Calculate the starting position for printing the maze
    int consoleWidth = 80; // Assuming standard console width
    int consoleHeight = 25; // Assuming standard console height
    int mazeWidth = 16; // Width of the maze
    int mazeHeight = 16; // Height of the maze
    int startX = (consoleWidth - (mazeWidth * 2)) / 2 + 23; // Adjusted starting X position (+3 spaces)
    int startY = (consoleHeight - mazeHeight) / 2; // Calculate starting Y position

    // Set colors
    SetConsoleTextAttribute(hConsole, 14); // Yellow for maze
    // Print the maze
    int i, j;
    for (i = 0; i < mazeHeight; i++) {
        gotoxy(startX, startY + i); // Set cursor position
        for (j = 0; j < mazeWidth; j++) {
            if (maze[i][j] == '0') {
                SetConsoleTextAttribute(hConsole, 10); // Green for zero
                printf("%c ", maze[i][j]);
            } else if (maze[i][j] == '!') {
                SetConsoleTextAttribute(hConsole, 12); // Red for exclamation mark
                printf("%c ", maze[i][j]);
            } else {
                SetConsoleTextAttribute(hConsole, 14); // Yellow for maze
                printf("%c ", maze[i][j]);
            }
        }
    }

    // Print instructions
    SetConsoleTextAttribute(hConsole, 15); // White for instructions
    gotoxy(startX, startY + mazeHeight + 1);
    printf("PRESS 'i' TO READ INSTRUCTIONS");
    gotoxy(startX, startY + mazeHeight + 2);
    printf("PRESS 'm' TO EXIT");

    // Set cursor position for the zero character
    gotoxy(startX + (x * 2), startY + y);
    SetConsoleTextAttribute(hConsole, 10); // Green for zero
    printf("0");
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


printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|WELCOME TO THE MAZE GAME|");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYOUR GAME STARTS IN ..... 3");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYOUR GAME STARTS IN ..... 2");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYOUR GAME STARTS IN ..... 1");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLET'S GO");
    sleep(1);
    system("cls");

    b = 'i';

    while (b != 'm') {
        if (x == 1 && y == 6) {
            system("cls");
            print_maze2(x, y);

            while (1) {
                if (kbhit()) {
                    a = getch();

                    int newX = x, newY = y;
                    switch (a) {
                        case 'a': newX--; break; // left arrow
                        case 'd': newX++; break; // right arrow
                        case 's': newY++; break; // down arrow
                        case 'w': newY--; break; // up arrow
                        case 'i':
                            system("cls");
                            instructions();
                            break;
                        case 'e':
                            b = 'e';
                            break;
                    }
                    if (b == 'm') {
                        break;
                    }
                    if (maze[newY][newX] != '#') {
                        x = newX;
                        y = newY;
                    }

                    system("cls");
                    print_maze2(x, y);

                    if (x == 13 && y == 15) {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCONGRATULATIONS.. YOU WIN!!\n\t\t\t\t\t\t\tPRESS 'e' TO QUIT THE GAME");
                        scanf(" %c", &b);
                        if (!(b == 'm')) {
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWE HOPE TO SEE YOU AGAIN....!!");
                            getch();
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    playMazeGame();
    return 0;
}

