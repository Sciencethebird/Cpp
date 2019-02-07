//
//  main.c
//  Cstring
//
//  Created by Sciencethebird on 2018/8/25.
//  Copyright © 2018年 Sciencethebird. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    char* in = "cstring boiii";
    printf("in length = %lu\n", strlen(in));
    char* string = malloc(strlen(in)+1);
    strcpy(string, in);
    printf("%s\n", string);
    string[3] = 'L';
    printf("%s\n", string);
    strcat(string, in);
    puts(string);
    return 0;
}
