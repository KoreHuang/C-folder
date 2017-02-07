//
//  main.c
//  Default
//
//  Created by mac on 16/4/5.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

struct stu {

    char d;
    char i;
    char j;
    char h;
    short c;
    char r;
    short t;
    char o;
    short p;
    double k;
    char l;
    
    int q;
    char y;

};
int main(int argc, const char * argv[]) {
    struct stu s;
    printf("%p\n",&s.d);
    printf("%p\n",&s.i);
    printf("%p\n",&s.j);
    printf("%p\n",&s.c);
    printf("%p\n",&s.r);
    printf("%p\n",&s.t);
    printf("%p\n",&s.o);
    printf("%p\n",&s.p);
    printf("%p\n",&s.k);
    printf("%p\n",&s.l);
    printf("%p\n",&s.d);
    printf("%p\n",&s.q);
    printf("%d\n",sizeof(struct stu));
}
