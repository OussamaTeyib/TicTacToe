#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// print the current play board
void printBoard(int *board)
{
    system("cls");
    for (int i = 0; i < 9; i++)
    {
        // Add newline and indent every 3 cells
	if (!(i % 3))
	    printf("\n\t\t\t\t");
	if (!board[i])
	    printf("- "); // empty cells
	else if (board[i] == 1)
	    printf("x ");
	else
	    printf("o ");
     }
     printf("\n");
}

// Initializing the board with empty cells
void initBoard(int *board)
{
    for (int i = 0; i < 9; i++)
        board[i] = 0;
}

// check if the board is full
int isFull(int *board)
{
    for (int i = 0; i < 9; i++)
        if (!board[i])
	    return 0;
    return 1;
}

// check if a player has won
int isWin(int *board, int p)
{
    // Defining all possible winning situations
    int situations[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int win;
    for (int i = 0; i < 8; i++)
    {
        win = 1;
	for (int j = 0; j < 3; j++)
        {
	    if (board[situations[i][j]] != p)
	    {
                win = 0;
                break;
            }
        }
        if (win)
            break;
    }
    return win;
}

int GetPlayerMove(int *board)
{
    int move, isValid;
    do
    {
        printf(">>> ");
        isValid = 1;
        fflush(stdin);
        int result = scanf("%d", &move);
        if (result != 1 || move < 1 || move > 9)
        {
	    printf("Invalid Input!\n");
            isValid = 0;
        }   
        else if (board[move - 1])
        {
            printf("Square is not available!\n");
	    isValid = 0;
        }
    } while (!isValid);

    return move;
}

int GetComputerMove(int *board)
{
    int move;
    srand(time(NULL));
    do
    { 
        move = rand() % 9 + 1; // to get a number between 1 and 9
    } while(board[move - 1]); // do while the square isn't available
    return move;
}

int GetAIMove(int *board)
{
   // TBD
   return 0;
}

void DisplayMainMenu()
{
    system("cls");
    printf("Welcome to TicTacToe (XO) Game\n");
    printf("Choose a playing mode:\n");
    printf("	1. Player vs Player\n");
    printf("	2. Player vs Computer\n");
    printf("	0. Exit\n");
}

int GetChoice()
{
    int choice;
    printf("Enter your choice\n");
    do
    {
        printf(">>> ");
        fflush(stdin);
        scanf("%d", &choice);
        if (choice < 0 || choice > 2)
            printf("Invalid choice!\n");
    } while (choice < 0 || choice > 2);

    return choice;
}

int main(void)
{
    int board[9];
    while (1)
    {
        DisplayMainMenu();
        int again, choice = GetChoice();
        switch (choice)
        {
            case 1: // PvsP
            {
                initBoard(board);
                int p = 1; 

                printBoard(board);
                while (1)
                {
                    printf("Player %d, Enter your move\n", p);
                    int move = GetPlayerMove(board);
                    board[move - 1] = p;
                    printBoard(board);

	            if (isWin(board, p))
	            {
	                printf("\nPlayer %d Won!", p);
	                break;
                    }
	            else if (isFull(board))
	            {
	                printf("\nGame Over!");
	                break;
                    }
                   
	            p = (1 == p? 2 : 1);
                }
	    }
            break;

            case 2: // PvsC
            {
                initBoard(board);

                int firstP;
                printf("\nDo you want to play the first? (1/0)\n");
                printf(">>> ");
                fflush(stdin);
                scanf("%d", &firstP);
                int p = firstP? 1: 2;

                printBoard(board);
                while (1)
                {
                    int move;
                    if (1 == p)
                    {
                        printf("Enter your move\n");
                        move = GetPlayerMove(board);
                    } 
                    else
                        move = GetComputerMove(board);

                    board[move - 1] = p;
                    printBoard(board);

	            if (isWin(board, p))
	            {
	                printf("\n%s Won!", (1 == p? "You": "The Computer"));
	                break;
                    }
	            else if (isFull(board))
	            {
	                printf("\nGame Over!");
	                break;
                    }
                   
	            p = (1 == p? 2 : 1);
                }
            }

            case 0: // Exit
                again = 0;
        }
        
        if (choice)
        {
            printf("\n\nPlay again? (1/0)\n");
            printf(">>> ");
            fflush(stdin);
            scanf("%d", &again);
        }

        if (!again)
            return EXIT_SUCCESS;
    }
}