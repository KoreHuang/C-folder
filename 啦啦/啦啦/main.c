//
//  main.c
//  啦啦
//
//  Created by mac on 16/6/21.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include <time.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i=0,j;
    srand(time(NULL));
    printf("****************\n");
    while (i<5) {
        for ( j=0; j<7; ) {
            n=rand();
            if (!((n%1000)%7-j)) {
                printf(" *%d* \n",n%1000);
                j++;
            }
        }
        printf("\n***************\n");
        i++;
    }
    return 0;
}
