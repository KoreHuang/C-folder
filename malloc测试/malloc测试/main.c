//
//  main.c
//  malloc测试
//
//  Created by mac on 16/3/3.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    char *name;
    name=(char*)malloc(5*sizeof(char));
    printf("Hello, World!\n");
    printf("%p\n",name);
    scanf("%s",name);
    printf("%s\n",name);
    free(name);
    printf("%p\n",name);
    printf("%s\n",name);
    return 0;
}
