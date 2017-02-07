//
//  main.c
//  二叉树路径
//
//  Created by mac on 15/11/26.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max_stack_size 30
#define Icrease_size 10
#define Elemtype BiNode
typedef struct BiNode{
    char data;
    struct BiNode *LChild,*RChild;
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
void PrintStack(SeqStack s){
    BiTree *temp;
    temp=s.base;
    while (temp<s.top) {
        printf("%c",(*temp)->data);
        temp++;
    }
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
void PostOrder(BiTree root){
    BiTree p,q=NULL;
    SeqStack s;
    InitStack(&s);
    p=root;
    while (p!=NULL||!IsEmpty(s)) {
        while (p!=NULL) {
            Push(&s, p);
            //if (p->LChild==NULL&&p->RChild==NULL) {
            //    PrintStack(s);
            //    printf("\n");
            //}
            //printf("%c",p->data);
            p=p->LChild;
        }
        if (!IsEmpty(s)) {
            Top(&s,&p);
            if((p->LChild==NULL)&&(p->RChild==NULL)) {
                PrintStack(s);
                printf("\n");
            }
            if ((p->RChild==NULL)||(p->RChild==q)) {
                Pop(&s, &p);
                q=p;
                p=NULL;
            }else p=p->RChild;
            /*if(p->RChild!=NULL)//
            p=p->RChild;
            else
                p=NULL;*/
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    BiTree root;
    printf("Hello, World!\n");
    CreateBitree(&root);
    PostOrder(root);
    return 0;
}
