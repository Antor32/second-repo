#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initBoard(void) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(void) {
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n\n");
}

int checkWin(void) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int isDraw(void) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int move;
    char current = 'X';
    initBoard();

    printf("Tic Tac Toe\n");
    printf("Player X goes first. Enter numbers 1-9 for positions:\n");
    printf("1|2|3\n4|5|6\n7|8|9\n");

    while (1) {
        printBoard();
        printf("Player %c, enter your move: ", current);
        if (scanf("%d", &move) != 1) {
            printf("Invalid input. Please enter a number from 1 to 9.\n");
            while (getchar() != '\n');
            continue;
        }
        if (move < 1 || move > 9) {
            printf("Move must be between 1 and 9.\n");
            continue;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] != ' ') {
            printf("That position is already taken. Try again.\n");
            continue;
        }
        board[row][col] = current;
        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", current);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("The game is a draw.\n");
            break;
        }
        current = (current == 'X') ? 'O' : 'X';
    }

    return 0;
}
