#include <iostream>
using namespace std;

const int row = 3, col = 3;

char input;
int flag = 0;

// declaring 2x2 array i.e cells for tic tac toe
char position[row][col]{{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
char token = 'X';
int counter = 0;
string player1;
string player2;

int players()
{

    cout << "Please enter name for player 1" << endl;
    getline(cin, player1);
    cout << "Please enter name for player 2" << endl;
    getline(cin, player2);
    cout << endl;
    cout << "X is assigned to " << player1 << endl;
    cout << "O is assigned to " << player2 << endl;
    cout << endl;

    return 0;
}
void ui()
{

    // Actual layout of the game

    cout << "            |            |            \n";
    cout << "     " << position[0][0] << "      |     " << position[0][1] << "      |     " << position[0][2] << "      \n";
    cout << "____________|____________|____________\n";
    cout << "            |            |            \n";
    cout << "     " << position[1][0] << "      |     " << position[1][1] << "      |     " << position[1][2] << "      \n";
    cout << "____________|____________|____________\n";
    cout << "            |            |            \n";
    cout << "     " << position[2][0] << "      |     " << position[2][1] << "      |     " << position[2][2] << "      \n";
    cout << "            |            |            \n";
}
int moves()
{
    cin >> input;

    // Check if the user's input is a valid position on the game board
    if (input < '1' || input > '9')
    {
        // Input is not a valid position, display an error message
        cout << "Invalid move!\n";
        return 0;
    }

    flag = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (position[i][j] == input)
            {
                // Position is available, make the move and set flag to 1 to break out of the loop
                position[i][j] = token;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    if (flag == 1)
    {
        // Position is available, switch to the other player's turn
        if (token == 'X')
        {
            token = 'O';
        }
        else
        {
            token = 'X';
        }
        // This keeps count of moves made, it will be used to check draw
        counter++;
    }

    return 0;
}
void NewPage()
{

    // This is just to make the matrix of tic tac toe appear at the same position after playing the move
    if (flag == 0)
    {
        // Position is not available, display an error message
        cout << "\nInvalid move!\n";
    }
    if (token == 'X')
    {
        cout << player1 << " it is your turn";
    }
    else
    {
        cout << player2 << " it is your turn";
    }
    if (flag == 0)
    {
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
    else
    {
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
}

int checkwin()
{
    // Checking for row wins
    for (int i = 0; i < row; i++)
    {
        if (position[i][0] == position[i][1] && position[i][1] == position[i][2])
        {
            return 1;
        }
    }
    // Checking for column wins
    for (int i = 0; i < col; i++)
    {
        if (position[0][i] == position[1][i] && position[1][i] == position[2][i])
        {
            return 1;
        }
    }
    // Checking for diagonal 1 win
    if (position[0][0] == position[1][1] && position[1][1] == position[2][2])
    {
        return 1;
    }
    // Checking for diagonal 2 win
    if (position[0][2] == position[1][1] && position[1][1] == position[2][0])
    {
        return 1;
    }
    // If all 9 moves are made it's a draw, so return 2
    if (counter == 9)
    {
        return 2;
    }
    // Return 0 is used to continue the game
    else
    {
        return 0;
    }
}
int main()
{
    

    printf("\n-------------------------------------------------------------------\n\n");
    printf("\t\t\t Tic-Tac-Toe\n");
    printf("\n-------------------------------------------------------------------\n\n");

    players();
    ui();
    moves();

    while (checkwin() == 0)
    {
        ui();
        NewPage();
        moves();
        NewPage();
    }
    ui();
    cout << "\n";
    if (checkwin() == 2)
    {
        cout << "The game ends in a Draw";
    }
    else
    {
        if (token == 'O')
        {
            cout << "Congrats!! " << player1 << " you won!";
        }
        else
        {
            cout << "Congrats!! " << player2 << " you won!";
        }
    }
    // Same function as New page, but did not recall the function as result text should be above the spaces
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    system("PAUSE");
}