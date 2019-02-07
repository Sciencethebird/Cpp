//
//  main.cpp
//  Function_Pointer
//
//  Created by Sciencethebird on 2018/11/4.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

///including Function Pointers and Lambda

#include <iostream>
#include <vector>


// A.Functions
void Hello(int a){
    std::cout << a << "Hello" << std::endl;
}
void LMAO(int a){
    std::cout << a << "LMAO" << std::endl;
}
/// B.Functions with Vector
void PrintValue(int value){
    std::cout << "Value: " << value << std::endl;
}


/// A.Function that eats functions
void Print(int a, void(*function)(int)){
    std::cout << "Function" << std::endl;
    function(a);
}
/// B.Functions that eats functions with vector
void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value : values)
        func(value);
}


int main(){
    
    //How to declare a pointer that points to a function
    typedef void(*f_type)(int);
    f_type  function = Hello;
    function(7);
    
    //A.
    Print(69, Hello);
    Print(69, LMAO);
    
    //Lambda
    Print(87,
    [](int a){std::cout << a<< std::endl;}
    );
    
    //B.
    std::vector<int> values = {1,5,2,6,7,4,3};
    ForEach(values, PrintValue);
}
///output
/*
 7Hello
 Function
 69Hello
 Function
 69LMAO
 Function
 87
 Value: 1
 Value: 5
 Value: 2
 Value: 6
 Value: 7
 Value: 4
 Value: 3
 */
