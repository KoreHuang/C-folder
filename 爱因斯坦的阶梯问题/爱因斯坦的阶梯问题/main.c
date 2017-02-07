//
//  main.c
//  爱因斯坦的阶梯问题
//
//  Created by mac on 15/10/24.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    int x=7, i, flag=0;
    
    for( i=1; i <= 100; i++ )
    {
        if( (x%2==1) && (x%3==2) && (x%5==4) && (x%6==5) )
        {
            flag = 1;
            break;
        }
        
        x = 7 * (i+1);
    }
    
    if( 1 == flag )
    {
        printf("阶梯数是：%d\n", x);
    }
    else
    {
        printf("在程序限定的范围内找不到答案！\n");
    }
    
    return 0;
}
