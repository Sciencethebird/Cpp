#include<iostream>
#include<string>
using namespace std;

class Example{
public:
    Example(){
        cout << "Example constructor " << endl;
    }
    Example(int a){
        cout << "Example constructor,  " << a << endl;
    }
};

class birb{
public:
    birb(){
        cout << "birb constructor " << endl;
    }
    birb(int a){
        cout << "birb constructor,  " << a << endl;
    }
};

class Entity{
private:
    string m_Name;
    int x, y, z=5;
    Example m_example;  /// stupid way of initializing object, it will call two constructors
    birb dd;
public:
    Entity()
    :dd(9), x(222)   ///initialize variables / class by given value by initializer
    {
        m_Name = "Unknown";
        m_example = Example(8); /// stupid way
        y = 0;
        z = 0;
    }
    Entity(const string &Name){
        m_Name = Name;
    }
    int getx(){
        return x;
    }
};

int main(){

    Entity lol;
    cout << lol.getx() << endl;
    return 0;
}
