//
//  main.cpp
//  Strings
//
//  Created by Sciencethebird on 2018/8/25.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

int main(int argc, const char * argv[]) {
    
    const char *string1 = "lalala\"";
    char string2[] = "adalskdaj";
    strcpy(string2, string1);
    std::cout << string2 << std::endl;
    
    std::string cppstring = "c++string";
    char *cstring  =(char*) malloc(cppstring.length()+1);
    strcpy(cstring , cppstring.c_str());
    cstring[3] = 'G';
    std::cout << cstring << std::endl;
    return 0;
    
}
