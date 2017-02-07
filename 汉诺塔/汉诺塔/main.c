//
//  main.c
//  汉诺塔
//
//  Created by mac on 16/4/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
int cnt=1;
void HannoTower(int n,char a,char b,char c){
    if(!(n-1)){
        printf("\t%c move NO.%d  to %c\n",a,cnt++,c);
    }else{
        HannoTower(n-1,a,c,b);
        printf("\t%c move NO.%d to %c\n",a,cnt++,c);
        HannoTower(n-1, b, a, c);
    }
}
int main(int argc, const char * argv[]) {
    HannoTower(3, 'a', 'b', 'c');
    return 0;
}
