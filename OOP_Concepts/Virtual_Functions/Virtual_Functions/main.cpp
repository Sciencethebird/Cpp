//
//  main.cpp
//  Virtual_Functions
//
//  Created by Sciencethebird on 2018/11/4.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;
class Entity{
public:
    virtual std::string GetName(){return "Entity";}
};

class Player: public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
    :m_Name(name){}
    std::string GetName() override {return m_Name;}
};
int main(){
    Entity P0;
    Player P1("Hello");
    cout << P0.GetName() <<endl;
    cout << P1.GetName() <<endl;
    return 0;
}



