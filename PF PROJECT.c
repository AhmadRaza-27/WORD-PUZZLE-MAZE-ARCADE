#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include<unistd.h>
#define MAX_WORD_LENGTH 300
#define MAX_ATTEMPTS 3

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
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '@', '#', '#'} //15
    // ... (your maze layout)
};

void delay(int milliseconds) {
    Sleep(milliseconds);
}

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
    printf("\n\t\tUSE 'w' 'a' 's' 'd' TO MOVE\n\t\t\tGOOD LUCK..!!");
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
    sleep(2);
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
            printf("0");

        while(1){
                if (kbhit()) {
                    a = getch();

                    int newX = x, newY = y;
                    switch (a) {
                        case 'a': newX--; break;
                        case 'd': newX++; break;
                        case 's': newY++; break;
                        case 'w': newY--; break;
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



char words[][MAX_WORD_LENGTH + 1] = {"programming", "suicide", "algorithm","informationtechnology", "developer", "software","misssamia","misssadia"};

void shuffleLetters(char *word) {
    int i, j;
    int length = strlen(word);
    for (i = length - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

void playWordPuzzleGame() {
    srand(time(NULL));


   int i,j;
    int score = 0;
     printf("\n\n\n\n\n\n\n\n\t\t _________________");
    printf("\n\t\t|**WELCOME TO THE WORD PUZZLE GAME**|");
    sleep(2);
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
    printf("\n\n\n\n\n\n\n\n\n\t\t**LET'S GO**");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\tUnscramble the letters to form a meaningful word.");


    for ( i = 0; i < sizeof(words) / sizeof(words[0]); ++i) {
        int attempts = MAX_ATTEMPTS;

        char originalWord[MAX_WORD_LENGTH + 1];
        strcpy(originalWord, words[i]);

        char jumbledWord[MAX_WORD_LENGTH + 1];
        strcpy(jumbledWord, originalWord);
        shuffleLetters(jumbledWord);

        while (attempts > 0) {
            printf("\nJumbled Word: %s\n", jumbledWord);
            char guess[MAX_WORD_LENGTH + 1];

            printf("Your Guess: ");
            scanf("%s", guess);

            if (strcmp(guess, originalWord) == 0) {
                printf("Congratulations! You guessed the word correctly: %s\n", originalWord);
                score++;
                break;
            } else {
                printf("Incorrect guess. Try again! Attempts left: %d\n", attempts - 1);
                attempts--;
            }
        }
    }

    printf("\nGame Over!\n");
    printf("Your final score is: %d/%lu\n", score, sizeof(words) / sizeof(words[0]));
}




int main() {
	printf("\n\n\n\n\n\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    	printf("\n\t\t''''''''''''WELCOME TO OUR ARCADE''''''''''''''");
    	sleep(1);
    while (1) {
    	
        printf("\n\n\t\t\tOUR ARCADE HAVE TWO GAMES \n\t\t\t1.MAZE GAME\n\t\t\t2.WORD PUZZLE");
        sleep(1);
        printf("\n\t\t\tTO EXIT YOU CAN PRESS '0'");
        sleep(1);
        printf("\n\t\t\tWHICH GAME WOULD YOU LIKE TO PLAY: ");
        sleep(1);
        
        int choice;
        scanf("%d", &choice);
        sleep(1);
        system("cls");

        switch (choice) {
            case 1:
                playMazeGame();
                break;
            case 2:
                playWordPuzzleGame();
                break;
            case 0:
                printf("\n\n\n\n\n\n\t\t\tTHANKS FOR PLAYING");
                sleep(1);
                system("cls");
                break;
            default:
                printf("Invalid choice. Please enter 1 for the maze game or 2 for the word puzzle game.\n");
        }
        if(choice==0)
        {
        	printf("\n\n\n\n\n\n\t\t\t________");
        	printf("\n\t\t\tTHE END!");
        	printf("\n\t\t\t~~~~~~~~");
			break;
		}
    }

    return 0;
}
