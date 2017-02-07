//
//  main.c
//  找数组中的最小值和次小值并输出
//
//  Created by mac on 15/12/3.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int a[10],i;
    int s1,s2 = 0;
    s1=9;
    srand((unsigned)time(NULL));
    for (i=0; i<10; i++) {
        a[i]=(unsigned)rand()%10;
    }
    for (i=0; i<10; i++)
         printf(" %d ",a[i]);
    printf("\n");
    for (i=0; i<8; i++) {
        if (a[i]<=a[s1]) {
            s2=s1;
            s1=i;
        }else  if (a[i]<=a[s2]) {
            s2=i;
        }
    }
    printf("%d,%d,%d,%d\n",s1,s2,a[s1],a[s2]);
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
