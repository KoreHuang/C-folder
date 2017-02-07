//
//  main.c
//  求圆周率
//
//  Created by mac on 15/11/22.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct dot{
    float x;
    float y;
} Dot;
int main(int argc, const char * argv[]) {
    // insert code here...
    Dot a;
    int count;
    srand((unsigned)time(NULL));
    for (int i=0; i<100000000;i++ ) {
        a.x = (float)(rand()%101)/100;
        a.y = (float)(rand()%101)/100;
        if (a.x*a.x+a.y*a.y<=1) {
            count++;
        }
    }
    printf("Hello, World!\n%lf\n",1.0*count/100000000*4);
    return 0;
}
