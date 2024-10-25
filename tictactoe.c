/*We will define our headers here*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*We will define a 2D array (Matrix) for our board*/

char board[3][3];

/*We will define the character variables for the player and the computer symbols*/

char PLAYERSYMBOL;
char COMPUTERSYMBOL;

/*We will define a character array for the player's name*/

char name[20];

/*We will define the player and computer scores*/

int playerscore = 0;
int computerscore = 0;

/*We will define our functions here, explanation for the respective functions are given at their usage*/

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

/*We will define our main function here*/

int main()
{

    /*We will define the variable to check the winner and the response*/

    char winner = ' ';
    char response;

    printf("Welcome to Tic Tac Toe!\n");

    /*We will get the player's name and symbol*/

    printf("Enter Player name: ");
    scanf("%s", name);

    printf("Enter Player symbol: ");
    scanf("%s", &PLAYERSYMBOL);

    /*We will define the player's symbol to a constant character*/
    /*Since this is being defined in a function it is a local constant, so we will have to define it in every other function where it is used*/

    const char PLAYER = PLAYERSYMBOL;

    /*We will get the computer's symbol*/

    printf("Enter Computer symbol: ");
    scanf("%s", &COMPUTERSYMBOL);

    /*We will define the computer's symbol to a constant character*/
    /*Since this is being defined in a function it is a local constant, so we will have to define it in every other function where it is used*/

    const char COMPUTER = COMPUTERSYMBOL;

    /*We will initiate the game with a do-while loop*/

    do
    {
        /*We will reset the values of winner and response*/

        winner = ' ';
        response = ' ';

        /*We will reset the board*/

        resetBoard();

        /*We will initiate a while loop to check the winner and the free spaces*/

        while(winner == ' ' && checkFreeSpaces() != 0)
        {
            /*We will print the board*/

            printBoard();

            /*We will get the player's move*/

            playerMove();

            /*We will check the winner*/

            winner = checkWinner();

            /*We will check if the winner is not a space or if there are no free spaces*/

            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            /*We will get the computer's move*/

            computerMove();

            /*We will check the winner*/

            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

        }

        /*We will print the board and the winner*/

        printBoard();
        printWinner(winner);

        /*We will print the score*/

        printf("Score:\n %s: %d Computer: %d\n", name, playerscore, computerscore);

        /*We will ask the player if they want to play again*/

        printf("Do you want to play again? (Y/N): ");

        /*We will get the response*/
        /*Here we will get a buffer response to avoid errors or bugs*/

        scanf("%c");
        scanf("%c", &response);

        /*We will convert the response to uppercase*/

        response = toupper(response);

    } while (response == 'Y');

    printf("Thanks for playing %s!\n", name);

    /*We will return 0 to end the program*/

    return 0;
}

/*The resetBoard function will be used to reset the board*/

void resetBoard()
{
    /*We will use a nested for loop to reset the board*/

    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            /*We will reset the board by setting it to space*/

            board[i][j] = ' ';
        }
    }
}

/*The printBoard function will be used to print the board*/

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
}

/*The checkFreeSpaces function will be used to check for free spaces*/

int checkFreeSpaces()
{
    /*We will define a variable to check the free spaces*/

    int freeSpaces = 9;

    /*We will use a nested for loop to check the free spaces*/

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            /*We will check if the board is not a space*/

            if(board[i][j] != ' ')
            {
                /*We will decrement the free spaces if the board is not a space*/

                freeSpaces--;
            }
        }
    }

    /*We will return the free spaces*/

    return freeSpaces;
}

/*The playerMove function will be used to get the player's move*/

void playerMove()
{
    /*We will define x & y integers to derermine the location of the player's move*/

    int x;
    int y;

    /*We will define the player's symbol to a constant character from before*/

    const char PLAYER = PLAYERSYMBOL;

    /*We will use a do-while loop to get the player's move*/

    do
    {
        printf("Enter the row number: ");
        scanf("%d", &x);
        x--;

        printf("Enter the column number: ");
        scanf("%d", &y);
        y--;

        /*We will check if the board is not a space*/

        if(board[x][y] != ' ')
        {
            printf("Invalid move.\n");
        }

        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}

/*The computerMove function will be used to get the computer's move*/

void computerMove()
{
    /*We will define the computer's symbol to a constant character from before*/

    const char COMPUTER = COMPUTERSYMBOL;

    /*We will define x & y integers to derermine the location of the computer's move*/
    /*We will use the rand() function to generate random numbers for the computer's moves*/

    srand(time(0));
    int x;
    int y;

    /*We will check if there are free spaces*/

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

/*The checkWinner function will be used to check the winner*/

char checkWinner()
{
    /*We will use a for loop to check for the winner*/

    /*First we will check horizontally*/

    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    /*Then we will check vertically*/

    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    /*Then we will check first diagonal*/

    for(int i = 0; i < 3; i++)
    {
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            return board[0][0];
        }
    }

    /*Then we will check second diagonal*/

    for(int i = 0; i < 3; i++)
    {
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            return board[0][2];
        }
    }

    return ' ';
}

/*The printWinner function will be used to print the winner*/

void printWinner(char winner)
{
    /*We will define the player and computer symbols to constant characters from before*/

    const char PLAYER = PLAYERSYMBOL;
    const char COMPUTER = COMPUTERSYMBOL;

    printf("\nGAME OVER!\n\n");

    /*We will check the winner and print the respective winner*/

    if(winner == PLAYER)
    {
        printBoard();
        printf("%s wins!\n", name);
        playerscore++;
    }
    else if(winner == COMPUTER)
    {
        printBoard();
        printf("Computer wins!\n");
        computerscore++;
    }
    else
    {
        printBoard();
        printf("IT'S A TIE!\n");
    }
}