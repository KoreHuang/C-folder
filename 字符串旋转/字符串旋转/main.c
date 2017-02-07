//
//  main.c
//  字符串旋转
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//

//问题描述：将字符串ABCDEF转换成DEFABC
#include<stdio.h>
#include<string.h>
#define Swap(a,b){char temp=a;a=b;b=temp;}
//方法一：暴力移位
void Revstr(char str[],int l){
    int len=strlen(str),i;
    char tmp;
    while(l>0){
        tmp=str[0];
        for(i=0;i<len-1;i++){
            str[i]=str[i+1];
        }
        str[i]=tmp;
        l--;
    }
}
//方法二：三步旋转
void Chgstr(char str[]){
    int len=strlen(str);
    int i,j,k;
    for(i=0,j=len-1;i<j;i++,j--)
        Swap(str[i],str[j]);
    for(k=0;k<j;k++,j--)
        Swap(str[k],str[j]);
    for(k=len-1;i<k;i++,k--)
        Swap(str[k],str[i]);
}
int main(void){
    char str[]="abcdef";
    Revstr(str,3);
    printf("%s\n",str);
    Chgstr(str);
    printf("%s\n",str);
    return 0;
}
