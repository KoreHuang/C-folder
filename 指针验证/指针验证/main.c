//
//  main.c
//  指针验证
//
//  Created by mac on 15/12/2.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
/*int *func(int a){
    a=5;
    return &a;
}*/
typedef struct{
    int a;
    int b;
    int c;
}node;
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    node *g;
    printf("****%ld****\n%p\n%p\n%p\n%p\n****\n",sizeof(*g),&g->a,&g->b,&g->c,g);
    x=6;
    //x=*func(x);
    int a[10]={0};
    int (*p)[10];
    p=&a;
    printf("Hello, World!\n%d\n",x);
    printf("%p\n%p\n%p\n%p\n",&p,p+1,&a,&a[9]);
    printf("%lu\n",sizeof(char*));
    return 0;
}
