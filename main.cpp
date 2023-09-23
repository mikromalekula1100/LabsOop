#include <iostream>
#include "line_editor.h"


using namespace std;

int main() {

    string text;
    int n;
    char old_value, new_value;

    cout<<"Введите строку"<<endl;
    cin>>text;

    cout<<"Введите параметр 'n'."<<endl;
    cin>>n;

    cout<<"Введите символ, который нужно заменить."<<endl;
    cin>>old_value;
    
    cout<<"Введите символ, на который нужно заменить."<<endl;
    cin>>new_value;

    cout<<replace(text, n, old_value, new_value)<<endl;
}