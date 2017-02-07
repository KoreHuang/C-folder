//
//  main.c
//  string库函数应用
//
//  Created by mac on 15/11/22.
//  Copyright © 2015年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    char g[]="25142,330,Smith, \n j,239-4123\n";
    unsigned long len1,len2,len3;
    len1=strspn(g, "1234567890");
    len2=strspn(g, ",2134567890");
    len3=strcspn(g, "\n\r\f\t\v ");
    printf("%s",g);
    printf("Hello, World!\n%lu   %lu   %lu\n",len1,len2,len3);
    return 0;
}
