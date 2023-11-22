#include <stdio.h>
void printboard();
char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkWin();
void system();

int main()
{
    int player = 1, input, status = -1;
    printboard();

    while (status = -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("Please Enter Number For player %d \n", player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("Invalid Parameter\n");
        }
        board[input] = mark;

        printboard();

        int result = checkWin();
        if (result == 1)
        {
            printf("Player %d is Winner\n", player);
            return;
        }
        else if (result == 0)
        {
            printf("Draw\n");
            return;
        }
        player++;
    }
}
void printboard()
{
    system("cls");
    printf("\n\n");
    printf("===Tic--Tac--Toe--Game===\n");
    printf("    |       |  \n");
    printf(" %c  |  %c    | %c \n", board[1], board[2], board[3]);
    printf("____|_______|___\n");
    printf("    |       |  \n");
    printf(" %c  |  %c    | %c \n", board[4], board[5], board[6]);
    printf("____|_______|___\n");
    printf(" %c  |  %c    | %C \n", board[7], board[8], board[9]);
    printf("    |       |  \n");
}
int checkWin()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }
    if (count == 9)
    {
        return 0;
    }
    return -1;
}