//
//  main.c
//  C语言 内存分配
//
//  Created by mac on 15/8/18.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    /*int i;
    printf("Hello Sir!\n");
    char a[5]="nihao";
    printf("%s\n",a);
    char *ptr=(char*)malloc(5*sizeof(char));
    printf("Please input the string:\n");
    for(i=0;i<5;i++){
        scanf("%c",&ptr[i]);
    }
    for(i=0;i<5;i++){
    printf("%c,",ptr[i]);
     }*/
    int a;
    printf("%d",printf("%d",printf("%2d",printf("%d",a=123))));
    
    int b[5],i,a_max,a_min;
    /*for (i=0; i<5; i++) {
        scanf("%d",b++);
    }*/
    for(i=0;i<5;i++)
        scanf("%d",&b[i]);
    for (i=0; i<5; i++) {
        printf("The array value is %d,",b[i]);
    }
    a_max=b[0];
    a_min=b[0];
    for (i=1; i<5; i++) {
        if (b[i]>a_max) {
            a_max=b[i];
        }
        if (b[i]<a_min) {
            a_min=b[i];
        }
    }
    
    printf("This array maxvalue is:%d,minvalue is :%d",a_max,a_min);
    return 0;
}
