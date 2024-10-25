/*We will define our headers here*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*We will define a 2D array (Matrix) for our board*/

char board[3][3];

/*We will define an integer to decide the mode of the game*/

int mode;
int MODE;

/*We will define the character variables for the symbols for Player 1 and Player 2*/

char PLAYER1SYMBOL;
char PLAYER2SYMBOL;

/*We will define a character array for the players' name*/

char name1[20];
char name2[20];

/*We will define the players' scores*/

int player1score = 0;
int player2score = 0;

int state = 1;

/*We will define our functions here, explanation for the respective functions are given at their usage*/

void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
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

    /*We will ask the players if they want to play in 1Player mode or 2Player mode*/

    printf("Do you want to play in 1Player mode or 2Player mode (1/2): ");
    scanf("%d", &mode);

    const int MODE = mode;

    /*We will get player 1's name and symbol*/

    printf("Enter Player 1 name: ");
    scanf("%s", name1);

    printf("Enter Player 1 symbol: ");
    scanf("%s", &PLAYER1SYMBOL);

    /*We will define the player's symbol to a constant character*/
    /*Since this is being defined in a function it is a local constant, so we will have to define it in every other function where it is used*/

    const char PLAYER1 = PLAYER1SYMBOL;

    /*We will get player 2's name and symbol*/

    printf("Enter Player 2 name: ");
    scanf("%s", name2);

    printf("Enter Player 2 symbol: ");
    scanf("%s", &PLAYER2SYMBOL);

    /*We will define the computer's symbol to a constant character*/
    /*Since this is being defined in a function it is a local constant, so we will have to define it in every other function where it is used*/

    const char PLAYER2 = PLAYER2SYMBOL;

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

            /*We will get player 1's move*/

            player1Move();

            /*We will check the winner*/

            winner = checkWinner();

            /*We will check if the winner is not a space or if there are no free spaces*/

            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            else if(state == 0)
            {
                break;
            }

            /*We will get player 2's move*/

            player2Move();

            /*We will check the winner*/

            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            else if(state == 0)
            {
                break;
            }

        }

        /*We will print the board and the winner*/

        printBoard();
        printWinner(winner);

        /*We will print the score*/

        printf("Score:\n %s: %d %s: %d\n", name1, player1score, name2, player2score);

        /*We will ask the players if they want to play again*/

        printf("Do you want to play again? (Y/N): ");

        /*We will get the response*/
        /*Here we will get a buffer response to avoid errors or bugs*/

        scanf("%c");
        scanf("%c", &response);

        /*We will convert the response to uppercase*/

        response = toupper(response);

    } while (response == 'Y' && state != 0);

    printf("Thanks for playing!\n");

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

/*The player1Move function will be used to get player 1's move*/

void player1Move()
{
    /*We will define x & y integers to derermine the location of player 1's move*/

    int x;
    int y;

    /*We will define player 1's symbol to a constant character from before*/

    const char PLAYER1 = PLAYER1SYMBOL;

    /*We will use a do-while loop to get the player's move*/

    printf("%s'S TURN!\n", name1);

    do
    {
        printf("To end the game enter row/coloumn number as 0\n");
        
        printf("Enter the row number %s: ", name1);
        scanf("%d", &x);
        x--;

        printf("Enter the column number %s: ", name1);
        scanf("%d", &y);
        y--;

        /*We will check if the board is not a space*/

        if(x == -1 || y == -1)
        {
            exit(1);
        }

        else if(board[x][y] != ' ')
        {
            printf("Invalid move.\n");
        }

        else
        {
            board[x][y] = PLAYER1;
            break;
        }
    }while(board[x][y] != ' ');

    printBoard();
}

/*The player2Move function will be used to get player 2's move*/

void player2Move()
{
    /*We will define x & y integers to derermine the location of player 2's move*/

    srand(time(0));
    int x;
    int y;

    /*We will define player 2's symbol to a constant character from before*/

    const char PLAYER2 = PLAYER2SYMBOL;

    /*We will define the mode of the game from before*/

    const int MODE = mode;

    printf("%s'S TURN!\n", name2);

    /*We will use an if-else statement to check the mode of the game*/

    if(MODE == 1)
    {
        computerMove();
    }
    else if(MODE == 2)
    {
        do
        {
            printf("To end the game enter row/coloumn number as 0\n");
            
            printf("Enter the row number %s: ", name2);
            scanf("%d", &x);
            x--;

            printf("Enter the column number %s: ", name2);
            scanf("%d", &y);
            y--;

            if(x == -1 || y == -1)
            {
                exit(1);
                break;
            }

            else if(board[x][y] != ' ')
            {
                printf("Invalid move.\n");
            }

            else
            {
                board[x][y] = PLAYER2;
                break;
            }
        }while(board[x][y] != ' ');
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
    /*We will define the player's symbol to a constant character from before*/

    const char PLAYER1 = PLAYER1SYMBOL;
    const char PLAYER2 = PLAYER2SYMBOL;

    printf("\nGAME OVER!\n\n");

    /*We will check the winner and print the respective winner*/

    if(winner == PLAYER1)
    {
        printBoard();
        printf("%s wins!\n", name1);
        player1score++;
    }
    else if(winner == PLAYER2)
    {
        printBoard();
        printf("%s wins!\n", name2);
        player2score++;
    }
    else
    {
        printBoard();
        printf("IT'S A TIE!\n");
    }
}

void computerMove()
{
    /*We will define the computer's symbol to a constant character from before*/

    const char PLAYER1 = PLAYER1SYMBOL;
    const char PLAYER2 = PLAYER2SYMBOL;

    /*We will define x & y integers to derermine the location of the computer's move*/

    int x;
    int y;

    if(checkFreeSpaces() != 0)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = PLAYER2;
                    if(checkWinner() == PLAYER2)
                    {
                        x = i;
                        y = j;
                    }
                    else if(checkWinner() != PLAYER2)
                    {
                        board[i][j] = PLAYER1;
                        if(checkWinner() == PLAYER1)
                        {
                            x = i;
                            y = j;
                        }
                        else if(board[1][1] == ' ')
                        {
                            x = 1;
                            y = 1;
                        }
                        else if(board[0][0] == ' ')
                        {
                            x = 0;
                            y = 0;
                        }
                        else if(board[2][2] == ' ')
                        {
                            x = 2;
                            y = 2;
                        }
                        else if(board[0][2] == ' ')
                        {
                            x = 0;
                            y = 2;
                        }
                        else if(board[2][0] == ' ')
                        {
                            x = 2;
                            y = 0;
                        }
                        else if(board[0][1] == ' ')
                        {   
                            x = 0;
                            y = 1;
                        }
                        else if(board[1][0] == ' ')
                        {
                            x = 1;
                            y = 0;
                        }
                        else if(board[1][2] == ' ')
                        {
                            x = 1;
                            y = 2;
                        }
                        else if(board[2][1] == ' ')
                        {
                            x = 2;
                            y = 1;
                        }
                    }
                    board[i][j] = ' ';
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        state = 0;
    }
    board[x][y] = PLAYER2;
}