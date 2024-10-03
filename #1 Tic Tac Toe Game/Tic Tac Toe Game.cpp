#include <iostream>  // for (cin, cout)
#include <iomanip>   // for (setw, setfill, setpercision, left, right)
#include <string>

using namespace std;

const int Size = 3;
char board[Size][Size];
string Player1_Name;
string Player2_Name;
char currentPlayer; // Current player ('X' or 'O')

void getPlayerNames ()
{
    string Name1, Name2;

    cout << "Player1: Enter your name: ";
    getline(cin, Name1);
    Player1_Name = Name1;

    cout << "Player2: Enter your name: ";
    getline(cin, Name2);
    Player2_Name = Name2;

    cout << endl; 

    cout << Name1 << " is player 1 so he/she will play first " << endl;
    cout << Name2 << " is player 2 so he/she will play second" << endl;
}

void initializeBoard ()
{
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void buildBoardStructure ()
{
    cout << setw(2) << left << board[0][0] << " | " << setw(2) << board[0][1] << " | " << setw(2) << board[0][2] << endl;
    cout << setfill('-') << setw(2) << "" << "-|-" << setw(2) << "" << "-|-" << setw(2) << "" << endl;
    cout << setfill(' ') << setw(2) << board[1][0] << " | " << setw(2) << board[1][1] << " | " << setw(2) << board[1][2] << endl;
    cout << setfill('-') << setw(2) << "" << "-|-" << setw(2) << "" << "-|-" << setw(2) << "" << endl;
    cout << setfill(' ') << setw(2) << board[2][0] << " | " << setw(2) << board[2][1] << " | " << setw(2) << board[2][2] << endl;
}

bool checkWin()
{
    for (int i = 0; i < Size ; i++)
    {
        if ((currentPlayer == board[0][i] && currentPlayer == board[1][i] && currentPlayer == board[2][i]) ||
            (currentPlayer == board[i][0] && currentPlayer == board[i][1] && currentPlayer == board[i][2]))
        {
            return true;
        }
    }

    if ((currentPlayer == board[0][0] && currentPlayer == board[1][1] && currentPlayer == board[2][2]) ||
        (currentPlayer == board[0][2] && currentPlayer == board[1][1] && currentPlayer == board[2][0]))
    {
        return true;
    }

    return false;
}

bool checkDraw ()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // Found empty space, not a draw
            }
        }
    }
    return true; // No empty spaces, it's a darw
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
}

void PlayerMove()
{
    int row, col;
    while(true)
    {
        cout << "Enter row (1-3) and col (1-3) for " << ((currentPlayer == 'x') ? Player1_Name : Player2_Name) << ": ";
        cin >> row >> col;

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ')
        {
            board[row - 1][col - 1] = currentPlayer;
            break;
        }
        else 
        {
            cout << "Invalid move, try again." << endl;
        }
    }
}

int main ()
{
    getPlayerNames();
    cout << endl;
    
    initializeBoard();

    currentPlayer = 'x';

    while(true)
    {
        buildBoardStructure();
        PlayerMove();

        if (checkWin())
        {
            buildBoardStructure();
            cout << "Congratulations " << ((currentPlayer == 'x') ? Player1_Name : Player2_Name) << "! You win!" << endl;
            break;
        }

        if (checkDraw())
        {
            buildBoardStructure();
            cout << "it's Draw" << endl;
            break;
        }
        switchPlayer();
    }
}