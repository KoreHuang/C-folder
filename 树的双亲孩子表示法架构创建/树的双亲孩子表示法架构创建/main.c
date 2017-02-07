//
//  main.c
//  树的双亲孩子表示法架构创建
//
//  Created by mac on 15/11/11.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Max_size 100

typedef char Elemtype;

typedef struct node{
    int child;
    struct node *next;
} ChildNode , * Child_Subscript;

typedef struct PNode{
    Elemtype data;
    int parent;
    Child_Subscript FirstChild;
}TreeNode;

typedef struct{
    TreeNode node[Max_size];
    int n;
    int r;
}Tree;

int main(int argc, const char * argv[]) {
    // insert code here...
    Tree root;
    Child_Subscript p = NULL;
    int i,j;
    int count;
    printf("请输入树的节点总数\n");
    scanf("%d",&count);
    root.n=count;
    root.r=0;
    for (i=0; i<count; i++) {
        getchar();
        root.node[i].FirstChild=NULL;
        printf("请输入树本节点的数据:");
        scanf("%c",&root.node[i].data);
        printf("请输入该节点的双亲节点:\n");
        scanf("%d",&root.node[i].parent);
        printf("请输入该节点的孩子数\n");
        scanf("%d",&j);
        while(j) {
            p=(Child_Subscript)malloc(sizeof(ChildNode));
            printf("请输入该节点的孩子节点:");
            scanf("%d",&(*p).child);
            p->next=root.node[i].FirstChild;
            root.node[i].FirstChild=p;
            j--;
        }
    }
    for(i=0;i<count;i++){
        printf("该节点是：%c\n",root.node[i].data);
        printf("它的双亲是:%d\n它的孩子是:",root.node[i].parent);
        p=root.node[i].FirstChild->next;
        if (!p)
            printf("NULL");
        else  while (p) {
            printf(" %d ",p->child);
            p=p->next;
        }
    }

    printf("Hello, World!\n");
    return 0;
}
