#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

void scanBoard(char board[SIZE][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            while (scanf(" %c", &board[i][j]) != 1)
                while(getchar() != '\n');
        }
    }
}

bool isQueenCaptured(char board[SIZE][SIZE], int row, int col) {
    int i, j;
    
    for (i = 0; i < SIZE; i++)                      //COLUMN CHECK
    {
        if (i != col && board[row][i] == 'Q') 
        {
            return true;
        }
    }

    for (i = 0; i < SIZE; i++)                  //ROW CHECK
    {
        if (i != row && board[i][col] == 'Q') 
        {
            return true;
        }
    }
    
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) //DIAGONALLY LEFT TOP CORNER
    {
        if (board[i][j] == 'Q') 
        {
            return true;
        }
    }

    for (i = row + 1, j = col + 1; i < SIZE && j < SIZE; i++, j++) //DIAGONALLY RIGHT BOTTOM CORNER
    {
        if (board[i][j] == 'Q') 
        {
            return true;
        }
    }
    
    for (i = row - 1, j = col + 1; i >= 0 && j < SIZE; i--, j++) //DIAGONALLY RIGHT TOP CORNER
    {
        if (board[i][j] == 'Q') 
        {
            return true;
        }
    }
    for (i = row + 1, j = col - 1; i < SIZE && j >= 0; i++, j--) //DIAGONALLY LEFT BOTTOM CORNER
    {
        if (board[i][j] == 'Q') 
        {
            return true;
        }
    }
    return false;
}

int countSafeQueens(char board[SIZE][SIZE]) {
    int safeQueens = 0;

    for (int row = 0; row < SIZE; row++) 
    {
        for (int col = 0; col < SIZE; col++) 
        {
            if (board[row][col] == 'Q') 
            {
                if (!isQueenCaptured(board, row, col)) 
                {
                    safeQueens++;
                }
            }
        }
    }
    return safeQueens;
}

int main() 
{
    char board[SIZE][SIZE];
    scanBoard(board);

    int result = countSafeQueens(board);
    printf("%d\n", result);

    return 0;
}
