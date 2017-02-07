//
//  main.c
//  递归建立链表
//
//  Created by mac on 16/1/13.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
typedef struct node {
    char data;
    struct node *next;
}LNode,*LinkList;
void CreatList(LinkList *Head){
    char ch;
    scanf("%c",&ch);
    if(ch=='^') *Head=NULL;
    else {
        *Head=(LNode *)malloc(sizeof(LNode));
        (*Head)->data=ch;
        CreatList(&((*Head)->next));
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList H;
    CreatList(&H);
    LNode *p;
    p=H;
    //printf("nihao\n");
    while (p!=NULL) {
        printf(" %c ",p->data);
        p=p->next;
    }
    printf("\nHello, World!\n");
    return 0;
}
