//
//  main.cpp
//  Virtual_Inheritance
//
//  Created by Sciencethebird on 2018/11/9.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
using namespace std;

class Base{
private:
    int a;
public:
    void print(){cout << "base" << endl;}
};
class Derived: virtual Base {
    void print(){cout << "D1" << endl;}
};
class Both: virtual Base, Derived{
    void print(){cout << "Both" << endl;}
};
int main(int argc, const char * argv[]) {
    return 0;
}
