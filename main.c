#include <stdio.h>

char playerType;

void getPlayerType() {
    scanf("%s", &playerType);
    if (playerType == 'X');
    {
        printf("\nDu spielst mit X!");
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
    return 0;
}

