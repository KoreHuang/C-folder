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
    return p;
}
void Josephu(node *L,int n,int password){
    int j=1,i=0,m=password,x=n;
    node *p=L,*s;
    m%=n;
    while (p->num!=p->next->num) {
        p=p->next;
        s=p->next;
        j++;
        if (j==m-1) {
            i++;
            m=s->Password;
            p->next=s->next;
            printf("第%d个出列的人是：%d，他的密码是：%d\n",i,s->num,s->Password);
            free(s);
            x--;
            m%=x;
            j=0;
        }
    }
    printf("最后一个出列的人是：%d，他的密码是：%d\n",p->num,p->Password);
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