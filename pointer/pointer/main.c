//
//  main.c
//  pointer
//
//  Created by mac on 15/10/3.
//  Copyright (c) 2015年 mac. All rights reserved.
//


#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char * argv[])
{
    int a[5][5] ;
    int (*p)[4] ;
    p=a;
    printf("%d", -(&p[1][0]-&a[4][2]) ) ;
}
