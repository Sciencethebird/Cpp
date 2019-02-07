#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string in;
    char str[100];
    fstream file("test1.txt", ios::out);
    cout << "input = " ;
    cin >> str;
    if(!file){
        cerr << "Oops\n";
        exit(1);
    }
    file  << str;
    file <<"\n";
    file.close();
    file.open("test1.txt", ios::out);
    file << "012";
    //cout << in;
    return 0;
}


