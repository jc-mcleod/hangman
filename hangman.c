#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char word[20];
char letter;
int wordSize;
int guessCorrect;
char lineHint[20];
int win = 0;
int wrongGuesses = 0;
int playerLost = 0;

void drawHangman()
{
    switch (wrongGuesses)
    {
        case 0:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 1:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 2:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "   |   |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 3:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|   |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 4:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 5:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "  /    |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 6:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "  / \\  |\n"
                 "       |\n"
                 " =========\n");
            sleep(1);
            system("clear");
            puts("\n"
            " __     ______  _    _   _      ____   _____ ______ \n"
            " \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n"
            "  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n"
            "   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n"
            "    | | | |__| | |__| | | |___| |__| |____) | |____ \n"
            "    |_|  \\____/ \\____/  |______\\____/|_____/|______|\n"
            "                                                    \n\n");
            printf("The correct word was: '%s'.\n\n", word);
            playerLost = 1;
            break;
    }
}

int winScreen()
{
    system("clear");
    puts("\n"
"__     ______  _    _  __          _______ _   _ \n"
"\\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |\n"
" \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |\n"
"  \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |\n"
"   | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |\n"
"   |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|\n"
"                                                  \n\n");
printf("The word was: '%s'.\n\n", word);
}

int checker(char guess)
{
    for (int i = 0; i <= wordSize && win == 0; i++)
    {
        letter = tolower(word[i]); //the letter which will be compared with the user's guess
       
        if (strcmp(lineHint, word) == 0)
        {
            system("clear");
            printf("\n\nYou guessed the word!\n\n");
            winScreen();
            win = 1;
            return 0;     
        }

        else if (letter == guess)
        {
            int guessedLetterIndex = i;
            lineHint[guessedLetterIndex] = guess;
            
            if (guessCorrect == 0 && win == 0)
            {
                system("clear");
                if (win != 1)
                {
                    printf("You guessed a correct letter!");
                }
                guessCorrect = 1;
            }
        }
    }

    if (guessCorrect == 0) //condition to only print if the player has guessed an incorrect character
    {
        system("clear");
        printf("You guessed wrong!");
        wrongGuesses++;
    }
}

void initBlankLine()
{
    char underscore = '_';
    char space = ' ';

    for (int i = 0; i < wordSize; i++)
    {
        if (word[i] != ' ')
        {
            strncat(lineHint, &underscore, 1);
        }
        else
        {
            strncat(lineHint, &space, 1); //hints at where spaces are in harder game modes
        }
    }
}

int chooseDifficulty()
{
    system("clear");
    printf("Welcome to Hangman!\n\nPress 'Enter' to start.\n\n");

    int difficulty = 0;
    char dummy;
    while ((dummy = getchar()) != '\n' && dummy != EOF) { } //clears input buffer
    
    system("clear");
    printf("Please pick a difficulty level:\n\n");
    printf("1 - Easy (single word, 5 characters or under)\n");
    printf("2 - Medium (single word, 10 characters or under)\n");
    printf("3 - Hard (two words, 10 characters or under)\n\n");
    printf("Difficulty number: ");

    scanf("%1d", &difficulty);

    if (difficulty == 1 || difficulty == 2 || difficulty == 3)
    {
        return difficulty;
    }
    else
    {
        system("clear");
        return chooseDifficulty();
    }
}

int chooseTheme()
{
    system("clear");
    printf("Now it's time to choose a theme:\n\n");
    
    int theme = 0;
    char dummy;
    while ((dummy = getchar()) != '\n' && dummy != EOF) { } //clears input buffer

    printf("1 - Animals\n");
    printf("2 - Food\n");
    printf("3 - Computing\n\n");
    printf("Theme number: ");
    scanf(" %1d", &theme);

    if (theme == 1 || theme == 2 || theme == 3)
    {
        return theme;
    }
    else
    {
        system("clear");
        return chooseTheme();
    }

    //dummy = getchar();
    //while ((dummy = getchar()) != '\n' && dummy != EOF) { } //clears input buffer

    return theme;
}

int assignWordlist(int difficulty, int theme)
{
    int arraySize = 5;
    srand(time(NULL));
    int rNum = (rand() % arraySize); //limits random index values to those within each wordlist
    
    switch(theme)
    {
        case 1:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"frog", "snake", "mouse", "bird", "zebra"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"chimpanzee", "rhinoceros", "crocodile", "alligator", "butterfly"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"tiger shark", "gentoo penguin", "red squirrel", "hammerhead shark", "arctic fox"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
        break;

        case 2:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"apple", "bacon", "beans", "curry", "pizza"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"chocolate", "blackberry", "asparagus", "cornflakes", "cheesecake"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"kidney beans", "peanut butter", "iceberg lettuce", "mandarin orange", "french fries"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
        break;

        case 3:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"blog", "cyber", "linux", "print", "mouse"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"bandwidth", "algorithm", "hypertext", "mainframe", "resolution"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"search engine", "virtual machine", "domain name", "hard drive", "social media"};
                strcpy(word, wordlist[rNum]);   
                wordSize = strlen(word); 
            }
        break;
    }    
    return 0;
}

void startGame()
{
    int difficulty = chooseDifficulty();
    int theme = chooseTheme();
    assignWordlist(difficulty, theme);
    getchar();
    initBlankLine();
    system("clear");
    drawHangman();
    
    for (int i = 0; win != 1 && playerLost != 1;  i++)
    {   
        char guess;
        guessCorrect = 0;
        printf("Completed Guesses: %d\n\n", i);
        printf("%s", lineHint);
        printf("\n\nGuess a letter: ");
        scanf(" %c", &guess);

        if (checker(guess) == 0)
        {
            return;
        }
        drawHangman();
        printf("\n\n");
    }
}

int main()
{
    startGame();
    return 0;
}