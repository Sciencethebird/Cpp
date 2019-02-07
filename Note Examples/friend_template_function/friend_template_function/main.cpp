//
//  main.cpp
//  friend_template_function
//
//  Created by Sciencethebird on 2018/8/31.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <iostream>
template<class T>
class foo{
public:
    foo(){};
    foo(T n):a(n){}
    //friend void a_function(foo<T>& n); // linker error
    template<class U>
    friend void a_function(foo<U>&);
private:
    T a;
};

template<typename T>
void a_function(foo<T>& n){
    std::cout << n.a <<std::endl;
}
int main(int argc, const char * argv[]) {
    foo<const char*> test("lala");
    a_function(test);
    return 0;
}
