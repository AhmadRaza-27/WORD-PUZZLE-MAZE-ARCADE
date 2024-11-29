#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<unistd.h>
#define MAX_WORD_LENGTH 300
#define MAX_ATTEMPTS 3

char words[][MAX_WORD_LENGTH + 1] = {"programming", "suicide", "algorithm","informationtechnology", "developer", "software"};

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


