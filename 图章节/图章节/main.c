//
//  main.c
//  图章节
//
//  Created by mac on 16/4/9.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MaxVex 25

typedef  char  ElemType;
/*******************临接矩阵***********************/
typedef struct adjmatrix{
    int vexnum;
    int arcnum;
    ElemType node[MaxVex];
    int arc[MaxVex][MaxVex];
}AdjMatrix;
/********************临接表***********************/
typedef struct node{
    int Weight;
    int NextVex;
    struct node* next;
}ArcNode;
struct head{
    int HeadVex;
    ArcNode *head;
};
typedef struct {
    ElemType data[MaxVex];
    struct head list[MaxVex];
    int vexnum;
    int arcnum;
}AdjList;
/*********************栈***********************/
typedef struct stack {
    ArcNode *data[MaxVex];
    int top;
}Stack;
int IsEmpty(Stack S){
    return S.top==0?1:0;
}
int IsFull(Stack S){
    return S.top==MaxVex?1:0;
}
ArcNode * Pop(Stack *S){
    if(!IsEmpty(*S)){
        S->top--;
        return S->data[S->top+1];
    }else return NULL;
}
void Push(Stack *S,const ArcNode *p){
    if(IsFull(*S)){
        printf("Allocation error!This Stack is Full!");
        return;
    }
    S->data[S->top]=p;
    S->top++;
}
/******************创建临界矩阵**********************/
void CreatAdjMatrix(AdjMatrix *G){
    int num;
    printf("Input the vertex num:");
    scanf("%d",&num);
    G->vexnum=num;
    printf("Input the arc num:");
    scanf("%d",&num);
    G->arcnum=num;
    for(int i=0;i<G->vexnum;i++){
        printf("请输入第%d个定点的值",i+1);
        scanf("%c",&G->node[i]);
    }
    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            printf("Input the weight of the %c to %c",G->node[i],G->node[j]);
            scanf("%d",&G->arc[i][j]);
        }
    }
}
/*******************创建临接表*********************/
void CreatAdjList(AdjList *G){
    int num;
    char temp;
    ArcNode *p=NULL;
    printf("Input the vertex num:");
    scanf("%d",&num);
    G->vexnum=num;
    printf("Input the arc num:");
    scanf("%d",&num);
    G->arcnum=num;
    for(int i=0;i<G->vexnum;i++){
        printf("请输入第%d个定点的值",i+1);
        scanf("%c",&G->data[i]);
    }
    for(int i=0;i<G->vexnum;i++){
        G->list[i].HeadVex=i+1;
        G->list[i].head=NULL;
        do{
            printf("请输入%c顶点的临近顶点信息,",G->data[i]);
            scanf("%c",&temp);
            if(temp!='^'){
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->NextVex=temp-'0';
                printf("从顶点%c,到顶点%c的权值",G->data[i],G->data[temp-'0']);
                scanf("%d",&(p->Weight));
                p->next=G->list[i].head;
                G->list[i].head=p;
            }else p=NULL;
        }while (p);
    }
}
/*******************深度优先搜索BFS**********************/
int GetFirstAdjVex(AdjList *G,int v0){
    return G->list[v0-1].head==NULL?-1:(G->list[v0-1].head)->NextVex;
}
int GetNextAdjVex(AdjList *G,int v,int v0){
    ArcNode *p;
    for(p=G->list[v0].head;p->NextVex!=v;p=p->next);
    return p->next==NULL?-1:p->next->NextVex;
}
int Visted[MaxVex];
void Vist(AdjList *G,int v){
    printf("%c\n",G->data[v-1]);
}
void BFS(AdjList *G,int v0){
    int w;
    Vist(G, v0);
    Visted[v0]=1;
    w=GetFirstAdjVex(G, v0);
    while (w!=-1) {
        if(!Visted[w]) BFS(G, w);
        w=GetNextAdjVex(G, w, v0);
    }
}
//

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
