//
//  main.c
//  辗转相除转换进制
//
//  Created by mac on 15/10/26.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int date;
    struct node *next;
}Linkstack;
void conversion(int N,int r){
    Linkstack *top;
    Linkstack *s = NULL;
    top=(Linkstack *)malloc(sizeof(Linkstack));
    top->next=NULL;
    int x=N;
/*    if ((s=(Linkstack *)malloc(sizeof(Linkstack)))==NULL) {
        printf("内存已满！");
        exit(0);
    }
    top->next=s;*/
    while (x/r) {
        if ((s=(Linkstack *)malloc(sizeof(Linkstack)))==NULL) {
            printf("内存已满！");
            exit(0);
        }
        s->next=top->next;
        top->next=s;
        s->date=x%r;
        x/=r;
    }
    s=(Linkstack *)malloc(sizeof(Linkstack));
    s->date=x%r;
    s->next=top->next;
    top->next=s;
    while (top->next) {
        printf("%d",top->next->date);
        top=top->next;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,r;
    printf("请输入N,r");
    scanf("%d%d",&N,&r);
    conversion(N, r);
    return 0;
}
