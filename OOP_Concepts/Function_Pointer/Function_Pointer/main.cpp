//
//  main.cpp
//  Function_Pointer
//
//  Created by Sciencethebird on 2018/11/4.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>

void Hello(){
    std::cout << "Hello" << std::endl;
}

int main(){
    typedef void(*f_type)();
    f_type  function = Hello;
    function();
}
