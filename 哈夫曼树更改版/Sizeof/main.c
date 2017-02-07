
//  main.c
//  利用哈夫曼树实现英文文本编码译码
//
//  Created by mac on 15/11/12.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_size 1000
typedef char ** Huffmancode;
typedef char  ElemType;
//定义权值数组类型，一个代表字符，一个代表该字符的权值
typedef struct{
    char Alphabet;
    int value;
} WeightType ;
//定义哈夫曼节点类型其中包括权值域，双亲节点域，左右孩子域
typedef struct {
    WeightType weight;
    int parent;
    int LChild;
    int RChild;
} HuffmanNode;
//从整型数组中找到元素值不为0的个数
int GetRenum(int *A,int n){
    int i,cnt=0;
    for (i=0; i<n; i++) {
        if (A[i]) {
            cnt++;
        }
    }
    return cnt;
}
//创建权值数组
WeightType *CreatWeight(int *x,char *Mainstring){
    char c;
    printf("请输入文本¨:");
    char str[1000];
    int alphabet[26];
    int Alphabet[26];
    int Punctu[32];
    int SpaceNum=0,n=0,i,k=0,j;
    WeightType *weight;
    memset(alphabet,0,26*sizeof(int));
    memset(Alphabet,0,26*sizeof(int));
    memset(Punctu,0,32*sizeof(int));
    gets(str);
    strcpy(Mainstring, str);
    printf("%s\n",str);
    while (str[k]!='\0') {
        c=str[k];
        if (c>32&&c<65) {
            Punctu[c-32]++;
        }else if (c==' ') {
            SpaceNum++;
        }else if (c>64&&c<91) {
            Alphabet[c-65]++;
        }else if (c>96&&c<123) {
            alphabet[c-97]++;
        }else printf("请输入合法字符!");
        k++;
    }
    n=GetRenum(alphabet,26)+GetRenum(Alphabet, 26)+GetRenum(Punctu, 32)+1;
    *x=n;
    weight=(WeightType*)malloc(n*sizeof(WeightType));
    j=0;
    weight[j].Alphabet=32;
    weight[j++].value=SpaceNum;
    for (i=0; i<26; i++) {
        if (alphabet[i]) {
            weight[j].Alphabet=i+97;
            weight[j++].value=alphabet[i];
        }
    }
    for (i=0; i<26; i++) {
        if (Alphabet[i]) {
            weight[j].Alphabet=i+65;
            weight[j++].value=Alphabet[i];
        }
    }
    for (i=0; i<32; i++) {
        if (Punctu[i]) {
            weight[j].Alphabet=i+32;
            weight[j++].value=Punctu[i];
        }
    }
    for (i=0; i<n; i++) {
        printf("%c %d \n",weight[i].Alphabet,weight[i].value);
    }
    return weight;
}
//创建Select函数，找到前n个节点中双亲为0，且权值最小的两个节点
void Select(HuffmanNode *ht,int n,int *s1,int *s2){
    int i=1;
    while (ht[i].parent!=0) {
        i++;
    }
    *s1=n;
    *s2=i;
    for (;i<n;i++) {
        if (!ht[i].parent) {
            if (ht[i].weight.value<=ht[*s1].weight.value) {
                *s2=*s1;
                *s1=i;
            }else if(ht[i].weight.value<ht[*s2].weight.value){
                *s2=i;
            }
        }
    }
}
//创建哈夫曼书树
HuffmanNode *CrtHuffmanTree(WeightType *w,int n){
    HuffmanNode *ht;
    int m=2*n-1;
    int i,s1,s2;
    ht=(HuffmanNode*)malloc((m+1)*sizeof(HuffmanNode));
    for (i=1; i<=n; i++) {
        ht[i].weight.Alphabet=w[i-1].Alphabet;
        ht[i].weight.value=w[i-1].value;
        ht[i].parent=0;
        ht[i].LChild=0;
        ht[i].RChild=0;
    }
    for (i=n+1; i<=m; i++) {
        ht[i].weight.Alphabet=0;
        ht[i].weight.value=0;
        ht[i].parent=0;
        ht[i].LChild=0;
        ht[i].RChild=0;
    }
    for (i=n+1; i<=m; i++) {
        Select(ht, i-1, &s1, &s2);
        ht[i].weight.value=ht[s1].weight.value+ht[s2].weight.value;
        ht[i].LChild=s1;
        ht[i].RChild=s2;
        ht[s1].parent=i;
        ht[s2].parent=i;
    }
    return ht;
}
//对已创建的哈夫曼树进行编码
Huffmancode CrtHuffmancoding(HuffmanNode *ht,int n){
    Huffmancode hc;
    int c,f,i,start;
    char *cd;
    hc=(Huffmancode)malloc((n+1)*sizeof(char*));//分配n个字符编码的头指针向量
    cd = (char *)malloc(n*sizeof(char));    // 分配编码组的临时存储空间
    cd[n-1] = '\0';                         // 编码串结束标志
    for (i=1; i<=n; ++i) {                  // 逐个字符求哈夫曼编码
        start = n-1;                          // 编码结束位置
        for (c=i, f=ht[i].parent; f!=0; c=f, f=ht[f].parent){
            // 从叶子到根求编码
            if (ht[f].LChild==c) cd[--start] = '0';
            else cd[--start] = '1';
        }
        hc[i] = (char *)malloc((n-start)*sizeof(char));
        // 为第i个字符编码分配存储空间
        strcpy(hc[i], &cd[start]);    // 从临时编码组将编码复制到hc
    }
    free(cd);   //  释放临时字符存储空间
    return hc;
} // HuffmanCoding
void TranslateHuffmanCoffe(HuffmanNode *ht,char *Code,int n){
    int i=0;
    int p=2*n-1;
    while (Code[i]!='\0') {
        if (Code[i]=='0') {
            p=ht[p].LChild;
        }
        else
            p=ht[p].RChild;
        if (ht[p].RChild==0||ht[p].LChild==0) {
            printf("%c",ht[p].weight.Alphabet);
            p=2*n-1;
        }
        i++;
    }
    printf("%c",ht[p].weight.Alphabet);
}

int main(int argc, const char * argv[]) {
    int n,i,j;
    char str[Max_size];
    char HuffmanCodeArray[Max_size];
    Huffmancode hc;
    WeightType *w;
    HuffmanNode *ht;
    w=CreatWeight(&n,str);
    ht=CrtHuffmanTree(w,n);
    printf("%d\n%s\n",n,str);
    for (i=1; i<2*n; i++) {
        printf("%c %d %d %d %d",ht[i].weight.Alphabet,ht[i].weight.value,ht[i].parent,ht[i].LChild,ht[i].RChild);
        printf("\n");
    }
    hc=CrtHuffmancoding(ht, n);
    for (i=1; i<=n; i++) {
        printf("%c的哈夫曼编码是%s\n",ht[i].weight.Alphabet,hc[i]);
    }
    printf("输入的密文是:\n");
    i=0;
    HuffmanCodeArray[0]='\0';
    while (str[i]!='\0') {
        for (j=1; j<=n; j++) {
            if (str[i]==ht[j].weight.Alphabet) {
                strcat(HuffmanCodeArray, hc[j]);
            }
        }
        i++;
    }
    printf("%s\n根据密文译出的原文是:\n",HuffmanCodeArray);
    TranslateHuffmanCoffe( ht, HuffmanCodeArray,n);
    printf("\n");
    return 0;
}
