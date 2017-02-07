//
//  main.c
//  八皇后问题
//
//  Created by mac on 15/11/1.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#define chess_row 10
#define chess_col 10
int count=0;
int notdanger(int row, int col,int (*chess)[chess_col]){
    int i,j,flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    for (i=0; i<chess_row;i++) {
        if (chess[i][col]==1) {
            flag=1;
            break;
        }
    }
    for (j=0; j<chess_col; j++) {
        if (chess[row][j]==1) {
            flag1=1;
            break;
        }
    }
    for (i=row,j=col; i<chess_row&&j<chess_col; i++,j++) {
        if (chess[i][j]==1) {
            flag2=1;
            break;
        }
    }
    for (i=row,j=col; i>=0&&j>=0; i--,j--) {
        if (chess[i][j]==1) {
            flag3=1;
            break;
        }
    }

    for (i=row,j=col; i<chess_row&&j>=0; i++,j--) {
        if (chess[i][j]==1) {
            flag4=1;
            break;
        }
    }
    for (i=row,j=col; i>=0&&j<chess_col; i--,j++) {
        if (chess[i][j]==1) {
            flag5=1;
            break;
        }
    }
    if (flag||flag1||flag2||flag3||flag4||flag5) {
        return 0;
    }else   return 1;
}
void EightQueen(int row,int n,int (*chess)[chess_col]){
    int i,j,chess2[chess_row][chess_col];
    for (i=0; i<chess_row; i++) {
        for (j=0; j<chess_col; j++) {
            chess2[i][j]=chess[i][j];
        }
    }
    if (row==chess_row) {
        printf("第%d种摆法是:\n",count+1);
        for (i=0; i<chess_row; i++) {
            for (j=0; j<chess_col; j++) {
                printf("%d ",chess2[i][j]);
            }
            printf("\n");
        }
        count++;
        printf("\n");
    }else{
        for (j=0; j<n; j++) {
            if (notdanger(row,j,chess)) {
                for (i=0; i<chess_row; i++) {
                    chess2[row][i]=0;
                }
                chess2[row][j]=1;
                EightQueen(row+1, n, chess2);
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int chess[chess_row][chess_col],i,j;
    for (i=0; i<chess_row; i++) {
        for (j=0; j<chess_col; j++) {
            chess[i][j]=0;
        }
    }
    EightQueen(0, chess_col, chess);
    printf("总共有%d种摆法!\n",count);
    printf("Hello, World!\n");
    return 0;
}
