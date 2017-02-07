//
//  main.c
//  韩信点兵问题
//
//  Created by mac on 15/10/24.
//  Copyright (c) 2015年 mac. All rights reserved.
//

/*****************************/
/**      韩信点兵问题      **/
/** By www.fishc.com 小甲鱼 **/
/*****************************/
#include <stdio.h>
#include <string.h>

int main()
{
    int x=7, flag=0;
    
    // 小甲鱼注释：为什么是从1000开始呢？因为文中说我方死伤四五百人嘛~
    for( x=1000; x <= 1500; x++ )
    {
        if( (x%3==2) && (x%5==3) && (x%7==2) )
        {
            flag = 1;
            break;
        }
    }
    
    if( 1 == flag )
    {
        printf("人数是：%d\n", x);
    }
    else
    {
        printf("在程序限定的范围内找不到答案！\n");
    }
    
    return 0;
}
