//
//  main.c
//  程序员一
//
//  Created by mac on 15/11/9.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
void ChangArray(int a[],int m,int n){
    int t,i,j;
    i=0;j=n-1;
    while (j>i) {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;j--;
    }
    i=0;j=m-1;
    while (j>i) {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;j--;
    }
    i=m;j=n-1;
    while (j>i) {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;j--;
    }
}
void print(int a[],int n){
    int i;
    for (i=0; i<n; i++) {
        printf("%d",a[i]);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...

    int a[10]={1,2,3,4,5,6,7,8,9,0};
    int m=3;
    int n=10;
   ChangArray(a, m, n);
    print(a,n);
    return 0;
}
