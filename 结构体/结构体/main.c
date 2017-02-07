//
//  main.c
//  结构体
//
//  Created by mac on 15/10/18.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#define N 3
struct date{
    int year;
    int month;
    int day;
};
struct student{
    char num[20];
    int score;
    struct date birthday;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    struct student stu[3]={{"06143047",89,1996,10,9},{"06143046",69,1996,11,03},{"06143045",91,1996,11,06}};
    for (i=0; i<N; i++) {
        printf("the num is:%s\n",stu[i].num);
        printf("the score is:%d\n",stu[i].score);
        printf("the score is:%d-%d-%d\n",stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day);
    }
    i=printf("%p", &i);
    printf("\n%d\n",i);
    i=printf("%x", &i);
    printf("\n%d\n",i);
    return 0;
}
