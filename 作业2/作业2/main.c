//
//  main.c
//  作业2
//
//  Created by mac on 15/8/31.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int i,n,*a,a_max,a_m;
    printf("请输入数组元素的个数n:\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Please input the value of your array:\n");
    for (i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    a_max=*a;
    a_m=*a;
    for (i=1; i<n; i++) {
        if (a[i]>a_max) {
            a_m=a_max;
            a_max=a[i];
        }
    }
    printf("This array maxvalue is : %d,the 2edvalue is %d",a_max,a_m);
    return 0;
}
