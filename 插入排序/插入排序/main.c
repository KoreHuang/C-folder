//
//  main.c
//  排序
//
//  Created by mac on 16/4/11.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b){int temp;temp=a;a=b;b=temp;}

void Sort(int *data,int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j>=0&&data[j-1]>data[j];j--)
            swap(data[j], data[j-1]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[100];
    srand(time(NULL));
    for (int i=0; i<100; i++) {
        a[i]=rand()%1000;
    }
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }

    Sort(a, 100);
    printf("***********************");
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }
    return 0;
}

