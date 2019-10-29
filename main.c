#include <stdio.h>
#include <stdbool.h>

bool isFirstTime = true;

char player1Type;
char player2Type;

int currentPlayer = 0;
int playerStarted = 0;

int score[] = {0, 0};

char nextChoice[2];

int board[3][3] = {{0,0,0},
                   {0,0,0},
                   {0,0,0}};

const char rowTitles[] = {'A', 'B', 'C'};
const char colTitles[] = {'1', '2', '3'};

/* prints the board to the console*/
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

/* scans in a move of a player and saves it in a charArray with length 2*/
void readInPlayerMove() {
    if (currentPlayer == 0) {
        printf("\nPlayer1 enter your next field (e.g. A1): ");
    } else {
        printf("\nPlayer2 enter your next field (e.g. A1): ");
    }
    scanf("%s", &nextChoice);
}

/* converts the user-entered row-letter into the corresponding int-position */
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

/* converts the user-entered column-number into the corresponding int-position */
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

/* checks if the game has a winner */
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

    //check diagonal topleft-bottomright
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] != 0 && board[1][1] != 0 && board[2][2] != 0)
        {
            return true;
        }
    }   


    //check diagonal topright-bottom-left
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] != 0 && board[1][1] != 0 && board[2][0] != 0)
        {
            return true;
        }
    } 

    return false;
    
}

/* executes the entered move and changes the currentPlayer */
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

/* checks whether the user entered a valid row letter */
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

/* checks whether the user entered a valid column number */
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

/* checks whether the user entered move is already occupied*/
bool checkPlayerOnBoard() {
    int row = getRowFromUserInput();
    int col = getColFromUserInput();

    if (board[row][col] == 0)
    {
        return true;
    }
    return false;
}

/* main-method that checks whether a user entered move is valid or not*/
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

/*congratulation-message to the winner is printed*/
void printWinner() {
    if (currentPlayer == 0)
    {
        //Winner Player 2
        score[1]++;
        printf("\n----- PLAYER 2 HAS WON THE GAME -----\n");
    } else
    {
        //Winner Player 1
        score[0]++;
        printf("\n----- PLAYER 1 HAS WON THE GAME -----\n");
    }
}

void resetBoard() {
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
           board[row][col] = 0;
        }
    }

    if (playerStarted == 0)
    {
        playerStarted = 1;
        currentPlayer = playerStarted;
    } else
    {
        playerStarted = 0;
        currentPlayer = playerStarted;
    }
}

void printScoreBoard() {
    printf("\n-----------------------\n");
    printf("| Player 1 | Player 2 |\n");
    printf("-----------------------\n");
    printf("|     %d    |     %d    |\n", score[0], score[1]);
    printf("-----------------------\n\n");
}

/*handles the start of the game and it also handles the game running*/
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
    printScoreBoard();
}

/*scans in the playerType (X or O) for the player1 and sets it correspndingly
  for the second player*/
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

/* prints a welcome message */
void printStartText() {
    printf("-----TIC TAC TOE-----\n");
    printf("X/x: Play with X\n");
    printf("O/o: Play with O\n");
    printf("Player1 enter your player choice: ");
}

bool askForPlayAgain() {
    char yesNo;
    printf("Nochmal spielen? (y/N): ");
    scanf("%s", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        resetBoard();
        return true;
    }
    return false;
}

int main() {
    do
    {
        if (isFirstTime)
        {
            printStartText();
            getPlayerType();
            isFirstTime = false;
        }
        startGame();  
    } while (askForPlayAgain());

    return 0;
}

