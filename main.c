#include <stdio.h>

char playerType;

int board[3][3] = {{0,2,0},
                   {0,1,2},
                   {0,1,0}};

void printBoard() {

    printf("\n\n");
    printf("\n-------------\n");
    for (int row = 0; row < 3; row++)
    {

        printf("|");
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == 0)
            {
                printf("   ");
            }
            else if (board[row][col] == 1)
            {
                printf(" X ");
            }
            else
            {
                printf(" O ");
            }
            printf("|");
        }
        printf("\n-------------\n");
        
    }
    
}

void startGame() {
    printBoard();
}

void getPlayerType() {
    scanf("%s", &playerType);
    if (playerType == 'X' || playerType == 'x')
    {
        printf("\nDu spielst mit X!");
    }
    else if (playerType == 'O' || playerType == 'o')
    {
        printf("\nDu spielst mit O!");
    }  
}

void printStartText() {
    printf("-----TIC TAC TOE-----\n");
    printf("X: Play with X\n");
    printf("O: Play with O\n");
    printf("Enter your player choice: ");
}

int main() {
    printStartText();
    getPlayerType();
    startGame();
    return 0;
}

