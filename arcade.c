#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "maze.h"
#include "wordPuzzle.h"
#define MAX_WORD_LENGTH 300


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
