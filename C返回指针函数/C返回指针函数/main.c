//
//  main.c
//  C返回指针函数
//
//  Created by mac on 15/8/17.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
char *strcat(char *str1,const char *str2)
{
    char *adress=str1;
    while(*str1) str1++ ;
    while((*str1++=*str2++));
    return (adress);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char a[30]="hello,";
    printf("%s",strcat(a, "world"));
    return 0;
}
