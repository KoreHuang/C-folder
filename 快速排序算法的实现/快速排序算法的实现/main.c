//
//  main.c
//  快速排序算法的实现
//
//  Created by mac on 16/3/27.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Swap(a,b) {int t;t=a;a=b;b=t;}

void quick_sort(int *date,int left,int right){
    int le=left;
    int ri=right;
    int povit=date[(left+right)/2];
    while (le<=ri) {
        for(;date[le]<povit;le++);
        for(;date[ri]>povit;ri--);
        if (le<=ri) {
            Swap(date[le], date[ri]);
            le++;
            ri--;
        }
    }
    if (le<right) {
        quick_sort(date, le, right);
    }
    if(ri>left){
        quick_sort(date, left, ri);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int a[100];
    srand(time(NULL));
    for (int i=0; i<100; i++) {
        a[i]=rand()%1000;
    }
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }
    printf("*********************************\n");
    quick_sort(a, 0, 99);
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }
    printf("\n");
    return 0;
}
