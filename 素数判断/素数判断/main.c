//
//  main.c
//  素数判断
//
//  Created by mac on 15/11/23.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_size 1000
void PrintPrime(int n){
    int *prime;
    int i,j,cnt;
    prime=(int *)malloc(max_size*sizeof(int));
    prime[0]=1;//最开始有一个素数2
    prime[1]=2;
    cnt=2;
    for (i=2; i<n; i++) {
        for (j=1; j<cnt; j++) {
            if(!(i%prime[j])) break;
        }
        if (j==cnt) {
            prime[cnt++]=i;
        }
    }
    prime[0]=cnt-1;
    for (i=0; i<cnt; i++) {
        printf("%d-－%d\n",i,prime[i]);
    }
    
}

int main(int argc, const char * argv[]) {
    PrintPrime(1000);
    return 0;
}
