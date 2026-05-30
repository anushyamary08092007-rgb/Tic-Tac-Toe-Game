#include <iostream>
using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;

        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return true;

    return false;
}

bool boardFull()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
        }
    }
    return true;
}

void makeMove(int choice)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==choice+'0')
            {
                board[i][j]=currentPlayer;
                return;
            }
        }
    }
}

int main()
{
    int choice;

    while(true)
    {
        displayBoard();

        cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        makeMove(choice);

        if(checkWin())
        {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << " Wins!\n";
            break;
        }

        if(boardFull())
        {
            displayBoard();
            cout << "\nMatch Draw!\n";
            break;
        }

        currentPlayer = (currentPlayer=='X') ? 'O' : 'X';
    }

    return 0;
}