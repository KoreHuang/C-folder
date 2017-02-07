//
//  main.c
//  求马鞍点
//
//  Created by mac on 15/10/28.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max_row 3
#define Max_col 4
void SearchS(int a[][Max_col]){
    int i,j,k,iMin,t,cnt=0;
    int  row,col;
    col=Max_col;      /*求出二维数组的列数*/
    row=Max_row;     /*求出二维数组的行数*/
    for (i=0; i<row; i++) {
        iMin=a[i][0];
        for (j=0; j<col; j++) {
            if (a[i][j]<iMin) {
                iMin=a[i][j];     /* 找到每行的最小值，将其值赋给iMin */
            }
        }
        for (j=0; j<col; j++) {
            if (!(a[i][j]-iMin)) {  /*找到该行最小值，并记录其下标，判断它是不是所在列的最大值*/
                k=j;
                t=0;
                while (t<row&&(iMin>=a[t][k])) {
                    t++;
                }
                if (!(t-row)) {
                    cnt++;
                    printf("第%d个鞍点是：(%d,%d),其值为%d",cnt,i+1,k+1,a[i][k]);
                }
                
            }
        }
    }
    if (!cnt) {
        printf("该矩阵无鞍点!");
    }
}

void display(int a[][Max_col]){
    int i,j;
    int  row,col;
    col=Max_col;      /*求出二维数组的列数*/
    row=Max_row;     /*求出二维数组的行数*/
    printf("您的矩阵是：************\n");
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[Max_row][Max_col];
    int i,j;
    memset(a,0,sizeof(a));
    printf("亲!输入你的矩阵!\n");
    for (i=0; i<Max_row; i++) {
        for (j=0; j<Max_col; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    display(a);
    SearchS(a);
    return 0;
}
