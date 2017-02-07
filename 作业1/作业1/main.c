//
//  main.c
//  作业1
//
//  Created by mac on 15/8/31.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,a[5],count=0,max;
    printf("请输入数组中5个元素的值：\n");
    for (i=0; i<5; i++) {
        scanf("%d",a+i);
    }
    max=a[0];
    for (i=0; i<5; i++) {
        if (a[i]>max) {
            count=0;
            max=a[i];
        }
        if (a[i]==max) {
            count++;
        }
    }
    printf("This array maxvalue is :%d,the count is :%d",max,count);
    
    return 0;
}
