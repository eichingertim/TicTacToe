#include <stdio.h>
#include <stdbool.h>

char player1Type;
char player2Type;

int currentPlayer = 0;

char nextChoice[2];

int board[3][3] = {{0,0,0},
                   {0,0,0},
                   {0,0,0}};

const char rowTitles[] = {'A', 'B', 'C'};
const char colTitles[] = {'1', '2', '3'};

void printBoard() {
    printf("\n    %c   %c   %c", colTitles[0], colTitles[1], colTitles[2]);

    printf("\n  -------------\n");
    for (int row = 0; row < 3; row++)
    {
        printf("%c ", rowTitles[row]);
        printf("|");
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == 0)
            {
                printf("   ");
            }
            else if (board[row][col] == 1)
            {
                printf(" %c ", player1Type);
            }
            else
            {
                printf(" %c ", player2Type);
            }
            printf("|");
        }
        printf("\n  -------------\n");
    }
    
}

void readInPlayerMove() {
    if (currentPlayer == 0) {
        printf("\nPlayer1 enter your next field (e.g. A1): ");
    } else {
        printf("\nPlayer2 enter your next field (e.g. A1): ");
    }
    scanf("%s", &nextChoice);
}

int getRowFromUserInput() {
    for (int i = 0; i < 3; i++)
    {
        if (rowTitles[i] == nextChoice[0])
        {
            return i;
        }
        
    }
    return 0;
}

int getColFromUserInput() {
    for (int i = 0; i < 3; i++)
    {
        if (colTitles[i] == nextChoice[1])
        {
            return i;
        }
        
    }
    return 0;
}

bool checkForWinner() {

    //check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] != 0 && board[i][1] != 0 && board[i][2] != 0)
            {
                return true;
            }
        }
    }

    //check colums
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] != 0 && board[1][i] != 0 && board[2][i] != 0)
            {
                return true;
            }
        }
    }

    return false;
    
}

void executePlayerMove() {
    int row = getRowFromUserInput();
    int col = getColFromUserInput();
    
    if (currentPlayer == 0)
    {
        board[row][col] = 1;
        currentPlayer = 1;
    } else {
        board[row][col] = 2;
        currentPlayer = 0;
    }    
}

void printArray() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d, ", board[i][j]);
        }
        printf("\n");
    }
    
}

bool checkRowInput() {
    for (int i = 0; i < 3; i++)
    {
        if (nextChoice[0] == rowTitles[i])
        {
            return true;
        }
        
    }
    return false;
    
}

bool checkColInput() {
    for (int i = 0; i < 3; i++)
    {
        if (nextChoice[1] == colTitles[i])
        {
            return true;
        }
        
    }
    return false;
}

bool checkPlayerOnBoard() {
    int row = getRowFromUserInput();
    int col = getColFromUserInput();

    if (board[row][col] == 0)
    {
        return true;
    }
    return false;
}

bool inputValid() {
    if (checkRowInput() && checkColInput())
    {
        if (checkPlayerOnBoard())
        {
            return true;
        }
    }
    return false;
}

void printWinner() {
    if (currentPlayer == 0)
    {
        //Winner Player 2
        printf("\n----- PLAYER 2 HAS WON THE GAME -----\n");
    } else
    {
        //Winner Player 1
        printf("\n----- PLAYER 1 HAS WON THE GAME -----\n");
    }
}

void startGame() {
    printf("\n\n----Let's start the game-----\n");
    printBoard();
    while (!checkForWinner())
    {
        readInPlayerMove();
        while (!inputValid())
        {
            readInPlayerMove();
        }
        
        executePlayerMove();
        printBoard();
    }
    printWinner();
    
}

void getPlayerType() {

    scanf("%s", &player1Type);
    printf("-------------------");
    if (player1Type == 'X' || player1Type == 'x')
    {
        player1Type = 'X';
        player2Type = 'O';
        printf("\nPlayer 1 spielt mit X\nPlayer 2 spielt mit O");
    }
    else if (player1Type == 'O' || player1Type == 'o')
    {
        player1Type = 'O';
        player2Type = 'X';
        printf("\nPlayer 1 spielt mit O\nPlayer 2 spielt mit X");
    }  
    printf("\n-------------------");
}

void printStartText() {
    printf("-----TIC TAC TOE-----\n");
    printf("X/x: Play with X\n");
    printf("O/o: Play with O\n");
    printf("Player1 enter your player choice: ");
}

int main() {
    printStartText();
    getPlayerType();
    startGame();   
    return 0;
}

