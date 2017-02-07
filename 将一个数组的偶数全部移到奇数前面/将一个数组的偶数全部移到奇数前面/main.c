//
//  main.c
//  将一个数组的偶数全部移到奇数前面
//
//  Created by mac on 15/11/15.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
int * Move_array(int *A,int n){
    int i=0,j;
    int x;
    while (i<n-1) {
        if (A[i]%2) {
            i++;
        }else{
            x=A[i];
            for (j=i; j<n-1; j++) {
                A[j]=A[j+1];
            }
            A[j]=x;
            n--;
        }
    }
    return A;
}
void MoveArray(int *A,int n){
    int i,j,t;
    i=0;
    j=n-1;
    while (i<j){
        for (; (i<n)&&(A[i]%2); i++) ;
        for (; (j>-1)&&!(A[j]%2); j--) ;
        if (i<j) {
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
}
void Move_Array(int *A,int n){
    int i,j,t;
    i=0;
    j=n-1;
    while (i<j){
        if (A[i]%2) i++;
        else if(!(A[j]%2)) j--;
        else{
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10]={1,2,3,4,5,6,7,8,9,0},i;
    int *b;
    MoveArray(a, 10);
    for (i=0; i<10; i++) {
        printf("%d\n",a[i]);
    }
    printf("\n");
    b=Move_array(a, 10);
    for (i=0; i<10; i++) {
        printf("%d\n",b[i]);
    }
    printf("Hello, World!\n");
    return 0;
}
