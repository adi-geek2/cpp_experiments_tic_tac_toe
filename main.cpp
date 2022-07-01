#include <iostream>
#include <string>

using namespace std;

#include "mainClasses.cpp"
#include "mainFunctions.cpp"

int main(){
    Board gameBoard;

    string userNameX{"adi"};
    string userNameO{"micha"};
    int numOfTurns, markedRow, markedColumn = 0;
    bool isMarkingSuccessfull;

    userNameX = getUserName("X");
    userNameO = getUserName("O");

    while(numOfTurns <  8){
        //Player X plays
        cout<<"Player "<< userNameX << " Turn" <<endl;
        while (true)
        {
            cout<<"Enter row to be marked"<<endl;
            cin >> markedRow;
            cout<<"Enter column to be marked"<<endl;
            cin >> markedColumn;
            isMarkingSuccessfull = gameBoard.markCell('x', markedRow, markedColumn);
            if (isMarkingSuccessfull)
            {
                break;
            }
        }   
        gameBoard.displayBoard();
        //Check for win player x
        gameBoard.checkWinner();
        if (gameBoard.winner == 'z')
        {
            cout << "play continues" << endl;
        }
        else if (gameBoard.winner == 'x')
        {
            cout << "Winner is " << userNameX << endl;
            break;
        }
        //PlayerO plays
        cout<<"Player "<< userNameO << " Turn" <<endl;
         while (true)
        {   
            cout<<"Enter row to be marked"<<endl;
            cin >> markedRow;
            cout<<"Enter column to be marked"<<endl;
            cin >> markedColumn;
            isMarkingSuccessfull = gameBoard.markCell('o', markedRow, markedColumn);
            if (isMarkingSuccessfull)
            {
                break;
            }    
        }
        gameBoard.displayBoard();
        //Check for win player O
        gameBoard.checkWinner();
        if (gameBoard.winner == 'z')
        {
            cout << "play continues" << endl;
        }
        else if (gameBoard.winner == 'o')
        {
            cout << "Winner is " << userNameO << endl;
            break;
        }              
        ++numOfTurns;
    }
    return 0;
}