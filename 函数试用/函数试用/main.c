//
//  main.c
//  函数试用
//
//  Created by mac on 16/2/24.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
int g=0;
int f(){
    g++;
    return g;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a,b;
    a=f();
    b=f();
    printf("%d  %d\n",a,b);
    return 0;
}
