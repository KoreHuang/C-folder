//
//  main.c
//  递归倒序输出
//
//  Created by mac on 15/11/1.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node *next;
}LinkNode,*Linklist;
//***********************************
//递归建链
void CreatList(Linklist *root){
    char ch;
    scanf("%c",&ch);
    if(!(ch-'^')){
        (*root)=NULL;
    }else{
        (*root)=(LinkNode *)malloc(sizeof(struct node));
        (*root)->data=ch;
        CreatList(&(*root)->next);
    }
}
//************************************
void showList(Linklist h){
    if(h){
        printf("%c",h->data);
        showList(h->next);
    }
}
//*************************************
void preList(Linklist head){
    if(!head->next){
        printf("%c",head->data);
    }else{
        preList(head->next);
        printf("%c",head->data);
    }
}
//*************************************
/*就地逆置单向链表*/
LinkNode *h=NULL;
Linklist preChgList(Linklist head){
    if(head&&!head->next) h=head;
    else{
        preChgList(head->next)->next=head;
        head->next=NULL;
    }
    return  head;
}
//**************************************
LinkNode *prechgList(Linklist head){
    LinkNode *ph,*T;
    if(!head->next){
        return head;
    }else{
        ph=prechgList(head->next);
        T=head->next;
        head->next=T->next;
        T->next=head;
        return ph;
    }
    
}
//**************************************
void print(){
    char c;
    scanf("%c",&c);
    if (c!='#') print();
    printf("%C",c);
}
//**************************************
int main(int argc, const char * argv[]) {
    // insert code here...
    Linklist Head;
    printf("请输入原链表!");
    CreatList(&Head);
    showList(Head);
    //print();
    printf("\n");
    preList(Head);
    printf("\n");
    showList(Head);
    printf("\n");
    preChgList(Head);
    Head=h;
    showList(Head);
    printf("\n");
    preChgList(Head);
    Head=h;
    showList(Head);
    printf("\n");
    Head=prechgList(Head);
    showList(Head);
    printf("\n");
    return 0;
}
