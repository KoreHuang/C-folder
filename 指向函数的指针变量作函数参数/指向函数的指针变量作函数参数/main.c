//
//  main.c
//  指向函数的指针变量作函数参数
//
//  Created by mac on 15/10/24.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
int evensun(int n){
    int i,sum=0;
    for (i=2; i<=n; i+=2) {
        sum+=i;
    }
    return sum;
}
int oddsum(int n){
    int i,sum=0;
    for(i=1;i<=n;i+=2){
        sum+=i;
    }
    return sum;
}
int result(int n,int (*p)(int a)){
    int sum;
    sum=(*p)(n);
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int sum,n,flag;
    printf("input n:\n");
    scanf("%d",&n);
    printf("input flag:");
    scanf("%d",&flag);
    if (flag==1)
        sum=result(n,oddsum);
    else sum=(n,evensun);
    printf("sum=%d",sum);
    return 0;
}
