//
//  main.c
//  Josephu
//
//  Created by mac on 15/12/13.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
void Josephu(int a[],int n,int m){
    int i=0,j;
    int x;
    while (n>1) {
        i=(i+m-1)%n;
        x=a[i];
        for (j=i; j<n-1; j++) {
            a[j]=a[j+1];
        }
        a[j]=x;
        n--;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10],i;
    int n=10;
    printf("Hello, World!\n");
    for (i=0; i<n; i++) {
        a[i]=i+1;
    }
    Josephu(a, n, 3);
    for (i=n-1; i>-1; i--)
        printf(" %2d ",a[i]);
    return 0;
}
