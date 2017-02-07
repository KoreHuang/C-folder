//
//  main.c
//  图
//
//  Created by mac on 16/3/13.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#define Max 20
typedef struct node{
    int vex;
    int weught;
    struct node *next;
}Arcnode;
typedef struct vertex{
    char data;
    Arcnode *head;
}vertex;
typedef struct adjlist{
    vertex Vertex[Max];
    int arcnum;
    int vexnum;
}AdjList;
typedef struct {
    char vertex[Max];
    int arc[Max][Max];
    int arcnum;
    int vexnum;
}AdjMatrix;

void BFS(AdjMatrix *G){
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
