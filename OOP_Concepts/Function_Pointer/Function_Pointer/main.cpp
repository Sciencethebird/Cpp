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

// A.Function Pointer
void Hello(int a){
    std::cout << a << "Hello" << std::endl;
}
void LMAO(int a){
    std::cout << a << "LMAO" << std::endl;
}

/// B.Function Pointer Vector
void PrintValue(int value){
    std::cout << "Value: " << value << std::endl;
}
void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value : values)
        func(value);
}

/// Function that eats functions
void Print(int a, void(*function)(int)){
    std::cout << "Function" << std::endl;
    function(a);
}

int main(){
    
    //Function Pointer Declaration
    typedef void(*f_type)(int);
    f_type  function = Hello;
    function(7);
    
    //A.Function Pointer
    Print(69, Hello);
    Print(69, LMAO);
    
    //Lambda
    Print(87,
    [](int a){std::cout << a<< std::endl;}
    );
    
    //B.Function Pointer Vector
    std::vector<int> values = {1,5,2,6,7,4,3};
    ForEach(values, PrintValue);
}
