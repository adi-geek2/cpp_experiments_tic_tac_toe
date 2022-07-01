#include <iostream>
using namespace std;

string getUserName(string playerSymbol){
    string name;
    cout<<"Player "<<playerSymbol<<" Enter your name"<<endl;
    cin >> name;
    return name;
}
