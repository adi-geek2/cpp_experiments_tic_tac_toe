//This module shall contain required classes to run game
#include <iostream>

using namespace std;

class Board
{
private:
    
public:
    // char mainBoard[16];
    Board();
    ~Board();
    char mainBoard2D[4][4]{0};
    char winner{'z'};
    bool winnerFound{false};
    void displayBoard();
    bool markCell(char, int, int);
    
    void checkWinner();
    void checkRow();
    void checkColumn();
    void checkDiagonal();
    void checkMainDiagonal();
    void checkOtherDiagonal();
    bool convert1DTo2D();
};

Board::Board()
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            mainBoard2D[i][j] = '_';
        }
    }
}

Board::~Board()
{
}

void Board::displayBoard()
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            cout<<mainBoard2D[i][j]<<"\t";
        }
        cout << endl;
    }     
    cout << endl;
}

bool Board::markCell(char player, int markedRow, int markedColumn){
    //Return true if placement was succesfull, false if cell is taken
    bool isPlacementSuccessfull;
    int cell, developerRow, developerColumn = -100;
    developerRow = markedRow - 1;
    developerColumn = markedColumn - 1;
    if (mainBoard2D[developerRow][developerColumn] == 'x' || mainBoard2D[developerRow][developerColumn] == 'o')
    {
        isPlacementSuccessfull = false;
        cout << "cell not empty, enter again" << endl;
    }
    else
    {
        mainBoard2D[developerRow][developerColumn] = player;
        isPlacementSuccessfull = true;
    }
    return isPlacementSuccessfull;
}

void Board::checkWinner(){
    checkRow();
    checkColumn();
    checkDiagonal();

    if (winnerFound == true)
    {
        cout << "Winner found" << endl;
    }
}

void Board::checkRow(){
    int countX, countO = 0;    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            if (mainBoard2D[i][j] == 'x' || mainBoard2D[i][j] == 'X' )
            {
                countX++;
            }
            if (mainBoard2D[i][j] == 'o' || mainBoard2D[i][j] == 'O' )
            {
                countO++;
            }
        }
        if (countX == 4 || countO == 4)
        {
            if (countX == 4)
            {
                winner = 'x';
            }
            if (countO == 4)
            {
                winner = 'o';
            }
            winnerFound = true;    
            break; 
        }
        countX = 0;
        countO = 0;
    }   
}

void Board::checkColumn(){
int countX, countO = 0;    
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++)
        {
            if (mainBoard2D[i][j] == 'x' || mainBoard2D[i][j] == 'X' )
            {
                countX++;
            }
            if (mainBoard2D[i][j] == 'o' || mainBoard2D[i][j] == 'O' )
            {
                countO++;
            }
        }
        if (countX == 4 || countO == 4)
        {
            if (countX == 4)
            {
                winner = 'x';
            }
            if (countO == 4)
            {
                winner = 'o';
            }
            winnerFound = true;    
            break; 
        }
        countX = 0;
        countO = 0;
    }
}

void Board::checkDiagonal(){
    checkMainDiagonal();
    checkOtherDiagonal();
}

void Board::checkMainDiagonal(){
//Check diagonal for winner
int countX, countO = 0;    
    for (size_t i = 0; i < 4; i++)
    {
        if (mainBoard2D[i][i] == 'x' || mainBoard2D[i][i] == 'X' )
        {
            countX++;
        }
        if (mainBoard2D[i][i] == 'o' || mainBoard2D[i][i] == 'O' )
        {
            countO++;
        }
    }
    if (countX == 4 || countO == 4)
    {
        if (countX == 4)
        {
            winner = 'x';
        }
        if (countO == 4)
        {
            winner = 'o';
        }
        winnerFound = true; 
    }
}

void Board::checkOtherDiagonal(){
//Check diagonal for winner
int countX, countO = 0;    
    for (size_t i = 0; i < 4; i++)
    {
        if (mainBoard2D[i][4-i] == 'x' || mainBoard2D[i][4-i] == 'X' )
        {
            countX++;
        }
        if (mainBoard2D[i][4-i] == 'o' || mainBoard2D[i][4-i] == 'O' )
        {
            countO++;
        }
    }
    if (countX == 4 || countO == 4)
    {
        if (countX == 4)
        {
            winner = 'x';
        }
        if (countO == 4)
        {
            winner = 'o';
        }
        winnerFound = true; 
    }
}