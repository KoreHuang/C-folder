//
//  main.c
//  装箱
//
//  Created by mac on 16/8/25.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define v 30
#define Swap(a,b){Good tmp=a;a=b;b=tmp;}
typedef struct {
    int gNo;
    int gV;
}Good;

typedef struct gNode{
    int gNo;
    struct gNode *next;
} GNode;

typedef struct Gbox{
    int ResiV;
    GNode *first;
    struct Gbox *next;
}GBox;

void goodQuickSort(Good* ,int ,int );
void showGoods(Good*,int);
int InitGoodInfo(Good **);
void InitGBox(GBox *);
void goodQuickSort(Good*,int,int);

int InitGoodInfo(Good **goods){
    int num;
    printf("Entry good number:");
    scanf("%d",&num);
    *goods = (Good*)malloc(num*sizeof(Good));
    for (int i=0; i<num; i++) {
        (*goods)[i].gNo=i+1;
        printf("输入%d号物品的体积:",i+1);
        scanf("%d",&(*goods)[i].gV);
    }
    showGoods(*goods, num);
    goodQuickSort(*goods, 0, num-1);
    return num;
}
void InitGBox(GBox* newBox){
    newBox->first=NULL;
    newBox->next=NULL;
    newBox->ResiV=v;
}
//利用快速排序算法对商品按照体积大小进行排序
void goodQuickSort(Good* data,int left,int right){
    int lIndex=left;    //左起指针
    int rIndex=right;   //右起指针
    int poivtValue=data[(left+right)/2].gV;  //标杆值
    while (lIndex<=rIndex) {
        for (;data[lIndex].gV>poivtValue ;lIndex++ );   //从左向右遍历找到比标杆小的元素停止
        for (;data[rIndex].gV<poivtValue ;rIndex-- );   //从右向左遍历找到比标杆大的元素停止
        if(lIndex<=rIndex){                             //由于降序排列,找到标杆两边不符合降序
            Swap(data[lIndex], data[rIndex]);           //的两个元素即停止并交换
            lIndex++;
            rIndex--;
        }
    }
    if(lIndex<right){
        goodQuickSort(data, lIndex, right);             //为完成整个数组的排序,应排递归拍完右半边
    }
    if(rIndex>left){
        goodQuickSort(data, left, rIndex);              //为完成整个数组的排序,应排递归拍完左半边
    }
}

void showGoods(Good* goods,int num){
    if(!num){
        printf("录入商品信息有误，请重启动!");
        exit(1);
    }
    printf("录入的商品信息为:\n");
    printf("*************\n");
    for (int i=0; i<num; i++) {
        printf("--商品编号:%d\n",goods[i].gNo);
        printf("--商品大小:%d\n",goods[i].gV);
        printf("*************\n");
    }
}

GBox * entryBox(Good * goods,int num){
    if(!goods||!num){
        printf("非法的参数输入!");
        exit(1);
    }
    GBox *hbox=NULL;
    GBox *tbox=NULL;
    GBox *pbox=NULL;
    tbox=hbox=pbox=(GBox*)malloc(sizeof(GBox));
    InitGBox(pbox);     //装第一个物品,必须开一个新箱子
    if(goods[0].gV>pbox->ResiV){
        printf("箱子容量小于最大的物品体积,问题无解!");
    }
    GNode * newGNode=(GNode*)malloc(sizeof(GNode));
    newGNode->gNo=goods[0].gNo;
    newGNode->next=NULL;
    pbox->first=newGNode;
    pbox->ResiV-=goods[newGNode->gNo-1].gV;
    pbox->next=NULL;
    GNode* qNode=NULL;
    GNode* tmpNode=NULL;
    for (int i=1; i<num; i++) {
        qNode=(GNode*)malloc(sizeof(GNode));
        qNode->gNo=goods[i].gNo;
        qNode->next=NULL;
        //将需要挂链的物品转化成物品节点
        for(pbox=hbox;pbox&&(pbox->ResiV<goods[i].gV);pbox=pbox->next);
        //从头开始找能放下物品i的箱子,若剩余容量大于物品体积则停,跑到最后一个节点的时候也停止,否则判断下一个箱子
        if(!pbox){  //如果工作指针为空的时候说明之前的箱子都放不下该物品,需要新开一个箱子
            pbox=(GBox*)malloc(sizeof(GBox));
            InitGBox(pbox);
            tbox=tbox->next=pbox;
            pbox->first=qNode;
        }else{      //否则装箱挂链
            for (tmpNode=pbox->first;tmpNode->next; tmpNode=tmpNode->next);
            tmpNode->next=qNode;
        }
        pbox->ResiV-=goods[i].gV;//装进箱子之后需要修改,箱子剩余空间大小
    }
    return hbox;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Good *goods=NULL;
    int num=InitGoodInfo(&goods);
    if(!goods)printf("goods 创建失败!");
    GBox *head = entryBox(goods,num);
//    GBox *hbox=NULL;
//    GBox *tbox=NULL;
//    GBox *pbox=NULL;
//    tbox=hbox=pbox=(GBox*)malloc(sizeof(GBox));
//    InitGBox(pbox);     //装第一个物品,必须开一个新箱子
//    printf("$$$$--%d--$$$$",pbox->ResiV);

    free(goods);
    free(head);
    return 0;
}
