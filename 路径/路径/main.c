//
//  main.c
//  路径
//
//  Created by mac on 15/11/26.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max_stack_size 30
#define Icrease_size 10


typedef struct Binode{
    char data;
    struct Binode *LChild,*RChild;
}Binode,*BiTree;
typedef struct stack{
    int Stack_size;
    char *top,*base;
}SeqStack;
//SeqStack S;
char Unuse;
void InitStack(SeqStack *S ){
    S->base=(char*)malloc(Max_stack_size*sizeof(char));
    if (!S->base) {
        exit(0);
    }
    S->top=S->base;
    S->Stack_size=Max_stack_size;
}
void Push(SeqStack *S,char x){
    if (S->top-S->base == S->Stack_size) {
        S->base=(char*)realloc(S->base, (S->Stack_size+Icrease_size)*sizeof(char));
    }
    if (!S->base) {
        exit(0);
    }
    *(S->top) = x;
    S->top++;
}
void Pop(SeqStack *s,char *a){
    if (s->top==s->base) {
        printf("栈已空");
        exit(0);
    }
    *a=*--(s->top);
}
long StackLen(SeqStack s){
    return (s.top-s.base);
}
void PrintStack(SeqStack S){
    char *p;
    p=S.base;
    while (p<=S.top) {
        printf("%c",*p);
        p++;
    }
     printf("\n");
}
void CreateBitree(BiTree *root){
    //BiTree p;
    char ch;
    //printf("请输入节点信息:");
    scanf("%c",&ch);
    if (ch=='#') {
          *root=NULL;
    }
    else{
        *root=malloc(sizeof(Binode));
        (*root)->data=ch;
        CreateBitree(&(*root)->LChild);
        CreateBitree(&(*root)->RChild);
    }
}
void Road(BiTree root,SeqStack *S){
    if(root){
        Road(root->LChild,S);
        Road(root->RChild,S);
        //Push(S, root->data);
        if (root->LChild==NULL&&root->RChild==NULL) {
            //PrintStack(*S);
           // Pop(S,&Unuse);
        }
    }else{
        //Pop(S, &Unuse);
        return;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    SeqStack S;
    printf("Hello, World!\n");
    BiTree root;
    CreateBitree(&root);
    InitStack(&S);
    Road(root,&S);
    return 0;
}
