//
//  main.c
//  希尔排序
//
//  Created by mac on 16/5/31.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Swap(a,b) {int tmp=a;a=b;b=tmp;}
void ShellSort(int data[],int n){
    int gap;
    int i,j,k,m;
    for(gap=n/2;gap>0;gap/=2){
        for(i=0;i<gap;i++){
            for (m=i; m<n; m+=gap) {
                k=m;
                for(j=m;j<n;j+=gap)
                    if(data[j]<data[k])k=j;
                if(k!=m)
                    Swap(data[k],data[m]);
            
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int data[10]={7,8,4,6,1,0,9,2,3,5};
    ShellSort(data, 10);
    for(int i=0;i<10;i++){
        printf("%d ",data[i]);
    }
    printf("\n*********************************\n");
    int a[100];
    srand(time(NULL));
    for (int i=0; i<100; i++) {
        a[i]=rand()%1000;
    }
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }
    printf("\n*********************************\n");
    ShellSort(a,100);
    for (int i=0; i<100; i++) {
        printf("%3d ",a[i]);
    }
    return 0;
}
