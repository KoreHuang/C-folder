//
//  main.c
//  回文序列判断
//
//  Created by mac on 15/10/29.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max_stack_size 30
#define Icrease_size 10

typedef char Elemtype;

typedef struct {
    Elemtype *top;
    Elemtype *base;
    int stacksize;
}sqStack;
void Init_stack(sqStack *s){
    s->base=(Elemtype *)malloc(Max_stack_size*sizeof(Elemtype));
    if (!s->base) {
        exit(0);
    }
    s->top=s->base;
    s->stacksize=Max_stack_size;
}
void Push(sqStack *s,Elemtype a){
    if(s->top-s->base>=s->stacksize){
        s->base=(Elemtype *)realloc(s->base, (s->stacksize+Icrease_size)*sizeof(Elemtype));
        if (!s->base) {
            exit(0);
        }
    }
    *(s->top)=a;
    s->top++;
}
void Pop(sqStack *s,Elemtype *a){
    if (s->top==s->base) {
        printf("栈已空");
        exit(0);
    }
    *a=*--(s->top);
}
long StackLen(sqStack s){
    return (s.top-s.base);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
