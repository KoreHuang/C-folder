//
//  main.c
//  进程管理
//
//  Created by mac on 16/4/9.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int p1,p2,i;
    if((p1=fork())){
        for(i=0;i<500;i++){
            printf("parent%d\n",i);
        }
            wait(0);
            exit(0);
        
    }else if((p2=fork())){
        for(i=0;i<500;i++){
            printf("son%d\n",i);
        }
            wait(0);
            exit(0);
        
    }
    else{
        for(i=0;i<500;i++){
            printf("granfchild%d\n",i);
        }
        exit(0);
    }
    return 0;
}
