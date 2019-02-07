//
//  tool_finctions.h
//  Sorting
//
//  Created by Sciencethebird on 2018/8/28.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#ifndef tool_finctions_h
#define tool_finctions_h
#include <iostream>

using namespace std;
template<typename T>
std::ostream& operator <<(std::ostream &out, std::vector<T> arr){
    size_t sz = arr.size();
    for(int i = 0; i <sz; i++)
        out << arr[i] << " ";
    return out;
}

#endif /* tool_finctions_h */
