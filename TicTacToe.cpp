#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

void drawBoard()
{
    cout << " -------------" << endl;
    cout << " | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl;
    cout << " -------------" << endl;
}

void player1marker(int n)
{
    char c = 'X';
    int row = (n / 3);
    int column = (n % 3) - 1;
    board[row][column] = c;
}
void player2marker(int n)
{
    char c = 'O';
    int row = (n / 3);
    int column = (n % 3) - 1;
    board[row][column] = c;
}

void boardReset()
{
    int places = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = places;
            places++;
        }
    }
}

bool checkForWins()
{
    for (int i = 0; i <= 2; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }

    for (int j = 0; j <= 2; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;

    return false;
}

int main()
{
    cout << endl
         << "  TIC TAC TOE" << endl;

    // declaring variables
    string player1, player2;
    int player1mkr, player2mkr, player1turns = 0;
    bool continueGame = true;

    // Game Instructions

    // Taking in player information
    cout << " Enter name of Player 1:";
    cin >> player1;
    cout << " Enter name of Player 2:";
    cin >> player2;

    while (continueGame)
    {
        while (1)
        {
            drawBoard();

            // Checking for player2 wins

            if (checkForWins() == true)
            {
                cout << "  " << player2 << " WINS!!" << endl;
                break;
            }

            // Player 1 playing...

            cout << "  " << player1 << " enter the space you want to invade:";
            cin >> player1mkr;
            player1marker(player1mkr);
            player1turns++;
            drawBoard();

            // checking for player 1 wins

            if (checkForWins() == true)
            {
                cout << "  " << player1 << " WINS!!" << endl;
                break;
            }

            // After player 1 is done with 5 turns all the spaces on the board is occupied
            if (player1turns >= 5)
            {
                cout << " Its a DRAW!" << endl;
                break;
            }

            // player 2 playing...

            cout << "  " << player2 << " enter the space you want to invade:";
            cin >> player2mkr;
            player2marker(player2mkr);
            // drawBoard();
        }
        cout << " Do You Wish To Play Another Game?" << endl;
        cout << " Enter 1 for Yes and 0 for No" << endl;
        cin >> continueGame;
        if (continueGame)
        {
            player1turns = 0;
            boardReset();
        }
        else
        {
            break;
        }
    }

    return 0;
}