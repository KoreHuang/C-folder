//
//  main.c
//  数组查找
//
//  Created by mac on 15/11/10.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
int FindNum(int a[],int n,int x){
    int i=0,j=n-1;
    if (x==a[i]) {
        return i;
    }if (x==a[j]) {
        return j;
    }
    while (i!=j) {
        if (x>a[(j+i)/2]) {
            i=(j+i+1)/2;
        }else if(x==a[(j+i)/2]){
            return (j+i)/2;
            break;
        }else{
            j=(i+j-1)/2;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    int t,x;
    printf("input your num :");
    scanf("%d",&x);
    t=FindNum(a, 10, x);
    if (t+1) {
    printf("您想找的数在数组的第%d个",t+1);
    }else{
        printf("你要找的数没有在数组里\n");
    }
    return 0;
}
