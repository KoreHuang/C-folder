//
//  main.c
//  链表各项操作
//
//  Created by mac on 15/10/22.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR -1

typedef int Status;
typedef int ElemType;

typedef struct Node//定义单链表
{
    ElemType data;
    struct Node *next;
}LinkList;

LinkList *InitList()//初始化
{
    LinkList *L;
    L = (LinkList*)malloc(sizeof(LinkList));
    if(!L)
    {
        printf("储存分配失败!");
        exit(ERROR);
    }
    L ->next = NULL;
    
    return L;
}

Status TailInsert(LinkList *L)//尾插法建立单链表
{
    int i;
    LinkList *tail,*p;
    tail = L;                  //尾指针的初值为头结点
    printf("请输入正整数(以86结束):");
    scanf("%d",&i);
    
    while(i != 86)
    {
        p = (LinkList*)malloc(sizeof(LinkList));
        p->data = i;           //给新节点赋值
        tail->next = p;        //新节点插入到表尾tail之后
        tail = p;              //将尾指针tail指向新的尾节点
        scanf("%d",&i);
    }
    
    tail->next = NULL;         //将单链表最后一个指针域置空
    
    return OK;
}

Status HeadInsert(LinkList *L)//头插法
{
    LinkList *p;
    int i;
    
    printf("请输入整数<以86结束>:");
    scanf("%d",&i);
    while( i != 86)
    {
        p = (LinkList*)malloc(sizeof(LinkList));//生成新节点
        p->data = i;
        p->next = L->next;
        L->next = p;
        scanf("%5d",&i);
    }
    
    return OK;
}

Status PrintList(LinkList *L)//输出
{
    LinkList *p;
    p = L ->next;
    printf("操作结果是:");
    while(p!=NULL)
    {
        printf("%5d",p->data);
        p = p->next;
    }
    printf("\n");
    
    return OK;
}

Status ListLength(LinkList *L)//求长度
{
    int i=0;
    LinkList *p;
    
    p = L->next;
    while(p!=NULL)
    {
        i++;
        p = p ->next;
    }
    printf("线性表的长度是:%d\n",i);
    return i;
}

Status GetElem(LinkList *L)//获取元素
{
    int i=0,j;
    LinkList *p;
    
    p = L->next;
    printf("请输入想要查找元素的位置<不检查越界>:");
    scanf("%d",&j);
    while(p!=NULL)
    {
        i++;
        if(i==j)
        {
            printf("第%d位置上的数是:%d\n",j,p->data);
            break;
        }
        p = p ->next;
    }
    return OK;
}

Status LocateElem(LinkList *L)//定位
{
    int i=0,j,k=0;
    LinkList *p;
    
    p = L->next;
    printf("请输入想要查找的数:");
    scanf("%d",&j);
    while(p!=NULL)
    {
        i++;
        if((p->data) == j)
        {
            printf("%d的位置是%d\n",j,i);
            k = 1;
            break;
        }
        p = p->next;
    }
    if(k==0)
    {
        printf("要查找的元素不存在!\n");
    }
    
    return OK;
}

Status ListInsert(LinkList *L)//插入
{
    int i,j,k=0;
    LinkList *p,*q,*r;
    
    p = L ->next;
    printf("请输入插入的位置以及想要插入的数<不检查越界>:");
    scanf("%d%d",&i,&j);
    
    q = (LinkList *)malloc(sizeof(LinkList));
    q->data = j;
    while(p!=NULL)
    {
        k++;
        if(i == 1)
        {
            q ->next = L ->next;
            L ->next = q;
            break;
        }
        else if((k+1) == i)
        {
            q->next = p->next;
            p ->next =q;
            break;
        }
        p = p->next;
    }
    
    r = L->next;
    printf("操作结果是:");
    while(r!=NULL)
    {
        printf("%5d",(r->data));
        r = r->next;
    }
    printf("\n");
    return OK;
}

Status ListDelete(LinkList *L)//删除
{
    int i;
    LinkList *p,*q;
    
    p = L->next;
    printf("请输入你想要删除的数<相同的只删除第一个>:");
    scanf("%d",&i);
    while(p!=NULL)
    {
        if(L->next->data == i)
        {
            L->next = L->next->next;
            break;
        }
        else if(p->next->data == i)
        {
            p->next = p->next->next;
            break;
        }
        p = p ->next;
    }
    q = L->next;
    printf("操作结果是:");
    while(q!=NULL)
    {
        
        printf("%5d",(q->data));
        q = q->next;
    }
    printf("\n");
    return OK;
}

Status ListSort(LinkList *L)//冒泡法排序
{
    LinkList *p,*q,*r,*s;
    int temp;
    
    for(p = L->next;p->next!=NULL;p=p->next)//遍历
    {
        r = p;
        for(q=p->next;q;q=q->next)//赋值q节点
        {
            if(q->data< r->data)//比较 q和r节点的值
            {
                r=q;//赋值
            }
            if(r!=p)//交换值
            {
                temp = p->data;
                p->data=r->data;
                r->data=temp;
            }
        }
    }
    s = L->next;
    printf("操作结果是:");
    while(s!=NULL)
    {
        
        printf("%5d",(s->data));
        s = s->next;
    }
    printf("\n");
    return OK;
}

Status main()//主函数
{
    int i,j;
    LinkList *L;
    
    L = InitList();//初始化
    while(1)
    {
        
        printf("建立单链表: 1.头插法 2.尾插法 3.结束\n");
        printf("请输入操作号:");
        scanf("%d",&i);
        if(i==1)
        {
            HeadInsert(L);//头插法
            PrintList(L);//输出
            break;
        }
        else if(i == 2)
        {
            TailInsert(L);//尾插法
            PrintList(L);//输出
            break;
        }
        else if(i == 3)
        {
            exit(0);
        }
        else
        {
            printf("输入有误,请重新输入!\n");
        }
        
    }
    
    printf("单链表操作:1.求长度 2.按位置求值 3.查找 4.插入 5.删除 6.排序 7.退出\n");
    while(1)
    {
        printf("请输入操作号:");
        scanf("%d",&j);
        if(j==1)
        {
            ListLength(L);//求长度
        }
        else if(j==2)
        {
            GetElem(L);//获取元素
        }
        else if(j==3)
        {
            LocateElem(L);//定位
        }
        else if(j==4)
        {
            ListInsert(L);//插入
        }
        else if(j==5)
        {
            ListDelete(L);//删除
        }
        else if(j==6)
        {
            ListSort(L);//排序
        }
        else if(j==7)
        {
            exit(0);
        }
        else
        {
            printf("输入有误,请重新输入!\n");
        }
        
    }
    
    return 0;
    
    
}