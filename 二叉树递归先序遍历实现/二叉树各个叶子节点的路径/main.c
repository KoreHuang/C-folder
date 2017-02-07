//
//  main.c
//  二叉树各个叶子节点的路径
//
//  Created by mac on 15/11/24.
//  Copyright © 2015年 mac. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define Max_stack_size 20
#define Icrease_size 10
typedef char Elemtype;
typedef struct BiTNode{
    char data;
    struct BiTNode *LChild,*RChild;
}BiNode,*BiTree;
typedef struct stack{
    BiTree *base,*top;
    int stack_size;
}SeqStack;

void InitStack(SeqStack *S ){
    S->base=(BiTree* )malloc(Max_stack_size*sizeof(BiTree));
    if (!S->base) {
        exit(0);
    }
    S->top=S->base;
    S->stack_size=Max_stack_size;
}
void Push(SeqStack *S,BiTree x){
    if (S->top-S->base == S->stack_size) {
        S->base=(Elemtype **)realloc(S->base, (S->stack_size+Icrease_size)*sizeof(Elemtype));
    }
    if (!S->base) {
        exit(0);
    }
    *(S->top)=x;
    S->top++;
}
void Pop(SeqStack *s,BiTree *a){
    if (s->top==s->base) {
        printf("栈已空");
        exit(0);
    }
    s->top--;//
    (*a)=*s->top;//
    
}
void Top(SeqStack *s,BiTree *a){
    if (s->top==s->base) {
        printf("栈已空,无可取元素!");
        exit(0);
    }
    s->top--;
    (*a)=*s->top;
    s->top++;
}
long StackLen(SeqStack s){
    return (s.top-s.base);
}
int IsEmpty(SeqStack s){
    if (s.top-s.base==0) {
        return 1;
    }
    else return 0;
}

void CreateBitree(BiTree *root){
    char ch;
    scanf("%c",&ch);
    if (ch=='#') {
        *root=NULL;
    }
    else{
        *root=malloc(sizeof(BiNode));
        (*root)->data=ch;
        CreateBitree(&(*root)->LChild);
        CreateBitree(&(*root)->RChild);
    }
}
void PreOrder(BiTree root){
    SeqStack S;
    InitStack(&S);
    BiNode *p;
    p=root;
    while (p||!IsEmpty(S)) {
        while (p) {
            printf("%c",p->data);
            Push(&S, p);
            p=p->LChild;
        }
        if(!IsEmpty(S)){
            Pop(&S, &p);
            /*if(p->RChild)
                p=p->RChild;
            else
                p=NULL;*/
            p=p->RChild;
        }
    }
}
int
main(void){
    printf("请输入数据:\n");
    BiTree root=NULL;
    CreateBitree(&root);
    // Road(root);
    PreOrder(root);
    return 0;
}