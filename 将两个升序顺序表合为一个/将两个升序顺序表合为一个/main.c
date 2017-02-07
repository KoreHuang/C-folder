//
//  main.c
//  将两个升序顺序表合为一个
//
//  Created by mac on 15/11/16.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int *Add_Array(int *A,int n,int m,int *B){
    int *C;
    C=(int * )malloc((m+n)*sizeof(int));
    int i,j,k;
    i=j=k=0;
    while (i<n&&j<m) {
        if (A[i]<B[j])   C[k++]=A[i++];
        else             C[k++]=B[j++];
    }
    if (i>=n) {
        while (j<m)    C[k++]=B[j++];
    }else{
        while (i<n)   C[k++]=A[i++];
    }
    return C;
}
int *Add(int *A,int n,int *B,int m){
    int *C;
    int i,j,k;
    C=(int *)malloc((m+n)*sizeof(int));
    i=j=k=0;
    while (i<n||j<m) {
        if (i>=n||((j<m)&&(A[i]>B[j]))) {
            C[k++]=B[j++];
        }
        else C[k++]=A[i++];
    }
    return C;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
