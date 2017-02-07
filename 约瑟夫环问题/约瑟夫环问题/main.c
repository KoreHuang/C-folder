//
//  main.c
//  约瑟夫环问题
//
//  Created by mac on 15/10/19.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define len struct person
typedef struct person {
    int num;
    int Password;
    len *next;
}node;
struct person *Creat(int n){
    node *pHead;
    int i=1;
    node *s = NULL,*p;
    pHead=(node*)malloc(sizeof(len));
    p=pHead;
    if (n) {
        while (i<=n) {
            s=(struct person*)malloc(sizeof(len));
            s->num=i++;
            p->next=s;
            p=s;
        }
        s->next=pHead->next;
    }
    free(pHead);
    if (n) {
        p=s->next;
        for (i=0; i<n; i++) {
            printf("请输入第%d个人的密码:",i+1);
            scanf("%d",&p->Password);
            p=p->next;
        }
    }
    return s->next;
}
void Josephu(node *L,int n,int password){
    int j=0,i=0,m=password,x=n,k;
    node *s=L,*r = NULL;
    m%=x;
    while (1) {
        for (k=1; k<m; k++) s=s->next;
        r=s;
        for (k=1; k<x; k++) r=r->next;
        i++;
        m=s->Password;
        r->next=s->next;
        printf("第%d个出列的人是%d号，他的密码是:%d\n",i,s->num,s->Password);
        free(s);
        s=r->next;
        x--;
        m%=x;
        j=0;
        if (s->next->num==s->num) break;
    }
    printf("第%d个出列的人是%d号，他的密码是:%d\n",i+1,s->num,s->Password);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    node *L;
    printf("请输入总人数n：");
    scanf("%d",&n);
    printf("请输入初始密码：");
    scanf("%d",&m);
    
    L=Creat(n);
    Josephu(L, n, m);
    return 0;
}