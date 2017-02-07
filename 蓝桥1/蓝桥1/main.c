//
//  main.c
//  蓝桥1
//
//  Created by mac on 16/5/31.
//  Copyright © 2016年 mac. All rights reserved.
//
//问题描述，按F向前跑97米，按B向后跑127米，问最少按F B多少次可以使向前跑的长度为1米
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int i,j,count[100]={0},m=0;
    int min;
    for(i=1;i<101;i++){
        for(j=1;j<101;j++){
            if((97*i-j*127)==1){
                count[m++]=i+j;
            }
        }
    }
    min=count[0];
    for(i=0;i<10;i++){
        if(count[i]&&count[i]<min){
            min=count[i];
        }
    }
    printf("%d\n",min);
    return 0;
}
