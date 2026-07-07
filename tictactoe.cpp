#include <iostream>
using namespace std;

// Array to store board positions
char board[3][3];

// Function to initialize the board
void initializeBoard()
{
    char position = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

// Function to display the board
void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << endl;

        if(i < 2)
            cout << "---|---|---" << endl;
    }

    cout << endl;
}

// Function to check winner
bool checkWinner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int j = 0; j < 3; j++)
    {
        if(board[0][j] == board[1][j] &&
           board[1][j] == board[2][j])
            return true;
    }

    // Main diagonal
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    // Other diagonal
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Function to make move
void playerMove(char symbol)
{
    int choice;

    while(true)
    {
        cout << "Player " << symbol << ", enter position (1-9): ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        if(choice < 1 || choice > 9)
        {
            cout << "Position must be between 1 and 9.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already occupied!\n";
            continue;
        }

        board[row][col] = symbol;
        break;
    }
}

// Rules
void showRules()
{
    cout << "\n========== RULES ==========\n";
    cout << "1. Player 1 uses X\n";
    cout << "2. Player 2 uses O\n";
    cout << "3. Enter numbers 1-9 to place your symbol.\n";
    cout << "4. First player to make three in a row wins.\n";
    cout << "===========================\n\n";
}

int main()
{
    int menuChoice;

    do
    {
        cout << "\n========== TIC TAC TOE ==========\n";
        cout << "1. Play Game\n";
        cout << "2. Rules\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        if(menuChoice == 1)
        {
            char playAgain;

            do
            {
                initializeBoard();

                char currentPlayer = 'X';

                while(true)
                {
                    displayBoard();

                    playerMove(currentPlayer);

                    displayBoard();

                    if(checkWinner())
                    {
                        cout << "Player " << currentPlayer << " Wins!\n";
                        break;
                    }

                    if(checkDraw())
                    {
                        cout << "Game Draw!\n";
                        break;
                    }

                    if(currentPlayer == 'X')
                        currentPlayer = 'O';
                    else
                        currentPlayer = 'X';
                }

                cout << "\nPlay Again? (Y/N): ";
                cin >> playAgain;

            } while(playAgain == 'Y' || playAgain == 'y');
        }

        else if(menuChoice == 2)
        {
            showRules();
        }

        else if(menuChoice == 3)
        {
            cout << "\nThank you for playing!\n";
        }

        else
        {
            cout << "Invalid Choice!\n";
        }

    } while(menuChoice != 3);

    return 0;
}