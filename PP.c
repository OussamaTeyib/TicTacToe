#include <stdio.h>

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

int main(void)
{
    // instializing the board with empty cells
    int board[9] = {0};

    int p = 1;
    while (1)
    {
        printBoard(board);
	int move;
	printf("\nPlayer %d, your move: ", p);
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
	board[move - 1] = p;
	if (isWin(board, p))
	{
	    printf("\nPlayer %d Won!", p);
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