#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()

// print the current play board
void printBoard(int *board)
{
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

void getComputerMove(int *, int *);

int main(void)
{
    // instializing the board with empty cells
    int board[9] = {0};
    printBoard(board);

    int p = 1;
    while (1)
    {
        int move;
        if (1 == p)
        {
	    printf("\nEnter your move: ");
            int result = scanf("%d", &move);
	    if (result != 1 || move < 1 || move > 9)
	    {
	        printf("Invalid Input!\n");
	        continue;
            }   
	    if (board[move - 1])
	    {
                printf("Square is not available!\n");
	        continue;
	    }
	}
        else
        {
            printf("\nThe computer's move: ");
            getComputerMove(board, &move);
        }
        board[move - 1] = p;
        printBoard(board); 

	if (isWin(board, p))
	{
	    printf("\n%s Won!", (1 == p? "The Player" : "The computer"));
	    return 0;
	}
	else if (isFull(board))
	{
	    printf("\nGame Over!");
	    return 0;
	}
	p = (1 == p? 2 : 1);
    }
    return 0;
}

void getComputerMove(int *board, int *move)
{
    srand(time(NULL));
    do
    { 
        *move = (rand() % 9) + 1; // to get value between 1 and 9
    } while(board[*move - 1]); 
}