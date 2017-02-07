//
//  main.c
//  单链表反转
//
//  Created by mac on 16/1/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int  ElemType;
typedef struct Lnode{
    int data;
    struct Lnode *next;
}LNode,*Linklist;
//建链
//*************************************************************
Linklist Creatlist(ElemType *a,ElemType n){
    int i;
    LNode head,*p,*rear;
    rear=&head;
    head.next=NULL;
    for (i=0; i<7; i++) {
        p=(LNode *)malloc(sizeof(LNode));
        p->data=a[i];
        p->next=NULL;
        rear->next=p;
        rear=p;
    }
    return head.next;
}
//反转链
//*************************************************************
Linklist TreLinklist(Linklist L){
    LNode *p,*s;
    s=L;
    L=NULL;
    while (s) {
        p=s;
        s=s->next;
        p->next=L;
        L=p;
    }
    return L;
}
//删除节点，无重复值
//*************************************************************
Linklist DeleLnode(Linklist L,ElemType key){
    LNode *p,*pre;
    p=L;
    if(p->data==key){
        L=p->next;
        free(p);
        return L;
    }
    else {
        while (p&&p->next) {
        pre=p;
        p=p->next;
        if (p->data==key) {
            pre->next=p->next;
            free(p);
        }
        }
    }
    return L;
}
//删除节点中的重复元素，链表升序排列
//************************************************************
Linklist DeleRLnode(Linklist L){
    LNode *p,*pre;
    p=L;
    while (p->next) {
        pre=p;
        p=p->next;
        if (pre->data==p->data) {
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
    }
    return L;
}
//

int main(int argc, const char * argv[]) {
    // insert code here...
    ElemType a[]={1,2,3,4,5,6,7};
    Linklist Head;
    LNode *p;
    Head=Creatlist(a, 7);
    for (p=Head; p; p=p->next) {
        printf("%d\t",p->data);
    }
    Head=TreLinklist(Head);
    for (p=Head; p; p=p->next) {
        printf("%d\t",p->data);
    }
    printf("\n");
    Head=DeleLnode(Head, 7);
    for (p=Head; p; p=p->next) {
        printf("%d\t",p->data);
    }
    printf("\nHello, World!\n");
    return 0;
}
