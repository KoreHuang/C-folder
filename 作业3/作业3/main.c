//
//  main.c
//  作业3
//
//  Created by mac on 15/8/31.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int i,n,j,*a,t;
    printf("Please input the array number n:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Please input your array value:\n");
    for (i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    j=n/2-1;
    for (i=1; j>=0; i++,j--) {
        t=a[j];
        a[j]=a[n-i];
        a[n-i]=t;
    }
    for (i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}
