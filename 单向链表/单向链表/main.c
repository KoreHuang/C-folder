//
//  main.c
//  单向链表
//
//  Created by mac on 15/10/18.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct student{
    char num[20];
    char name[20];
    int score;
    struct student *next;
};
int iCount;
struct student *Creat(){
    struct student *pHead=NULL;
    struct student *pNew,*pEnd;
    pNew=pEnd=(struct student *)malloc(sizeof(struct student));
    iCount=1;
    scanf("%s%s%d",pNew->num,pNew->name,&pNew->score);
    while (pNew->score!=0) {
        if (iCount==1) {
            pNew->next=pHead;
            pEnd=pNew;
            pHead=pNew;
        }
        else{
            pNew->next=NULL;
            pEnd->next=pNew;
            pEnd=pNew;
        }
        pNew=(struct student*)malloc(sizeof(struct student));
        scanf("%s%s%d",pNew->num,pNew->name,&pNew->score);
        iCount++;
    }
    free(pNew);
    return pHead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
        printf("Hello, World!\n");
    return 0;
}
