//
//  main.c
//  螺旋数组问题
//
//  Created by mac on 15/9/7.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#define N 3
#define M 3
int main(int argc, const char * argv[]) {
    int a[N][N],i,j,k,t;
    /*printf("please input the value of your array \n");
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            scanf("%d",a[i]+j);
        }
    }
    for (i=0; i<M; i++) {
        for (j=0;j<N-1; j++) {
            for (k=j; k<N; k++) {
                if (a[i][j]>a[i][k]) {
                    t=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]=t;
                
                }
            }
        }
    }
        for (i=0; i<M; i++) {
            for (j=0; j<N; j++) {
                printf("%3d",a[i][j]);
            }
            printf("\n");
        }*/
    printf("请输入数据!\n");
    if (N%2) {
    for (k=0,t=0;k<=N/2&&t<=N/2 ; ) {
        i=k;
        j=t;
        for (; j<N-t; ) {
            scanf("%d",a[i]+j);
            j++;
        }
        j--;i++;
        for (; i<N-t; ) {
            scanf("%d",a[i]+j);
            i++;
        }
        i--;j--;
        for (;j>t-1 ; ) {
            scanf("%d",a[i]+j);
            j--;
        }
        ++j;i--;
        for (;i>k; ) {
            scanf("%d",a[i]+j);
            i--;
        }
        ++i;
        k++;t++;
    }
    }
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%2d  ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
