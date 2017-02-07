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
    sqStack s,t;
    Elemtype e,x,y;
    int i=0,count=0;
    long cnt;
    Init_stack(&s);
    printf("Hello, World!\n");
    printf("请输入您的序列(按＃结束输入):\n");
    scanf("%c",&e);
    while (e!='#') {
        Push(&s, e);
        scanf("%c",&e);
    }
    getchar();
    cnt=StackLen(s);                /*记录栈长*/
    if (cnt==1) {
        printf("是回文序列!");
    }
    else{
        for(i=0;i<cnt/2;i++) {          /*从栈s里推出cnt/2个元素压入栈t*/
            Pop(&s, &e);
            Push(&t, e);
        }
        if (!(cnt%2)) {
            for (i=0; i<cnt/2; i++) {
            Pop(&s, &x);
            Pop(&t, &y);
            if (x==y)
                count++;
            else{
                printf("该序列不是回文序列");
                break;
            }
            }
        }
        else{
            Pop(&s, &e);
            for (i=0; i<cnt/2; i++) {
                Pop(&s, &x);
                Pop(&t, &y);
                if (x==y)
                    count++;
                else{
                    printf("该序列不是回文序列");
                    break;
                }
            }
        }
    }
    if (count==(cnt/2)) {
        printf("该序列是回文序列");
    }
    return 0;
}
