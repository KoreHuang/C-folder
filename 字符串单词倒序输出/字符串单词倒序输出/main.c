//
//  main.c
//  字符串单词倒序输出
//
//  Created by mac on 16/5/31.
//  Copyright © 2016年 mac. All rights reserved.
//

//问题描述:将字符串Xi'an university of posts and telecommunications转化为：
//telecommunications and posts of university Xi'an并输出
#include<stdio.h>
#include<string.h>
#define Swap(a,b){char tmp=a;a=b;b=tmp;}
void Reverse(char str[],int low,int high){
    while(low<high){
        Swap(str[low],str[high])
        low++;
        high--;
    }
}
void ChgStr(char str[]){
    int pre,i,len;
    pre=i=0;
    len=strlen(str);
    Reverse(str,0,len-1);
    while(i<len){
        if(str[i]==' '){
            Reverse(str,pre,i-1);
            pre=i+1;
        }
        i++;
    }
    Reverse(str,pre,i-1);
}
int main(void){
    char str[]="Xi'an university of posts and telecommunications";
    ChgStr(str);
    printf("%s\n",str);
    return 0;
}
