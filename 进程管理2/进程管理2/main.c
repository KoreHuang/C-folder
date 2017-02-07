//
//  main.c
//  进程管理2
//
//  Created by mac on 16/4/13.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
/* 允许建立的子进程个数最大值 */
#define MAX_CHILD_NUMBER 10
/* 子进程睡眠时间 */
#define SLEEP_INTERVAL 2
int proc_number=0; /* 子进程的自编号，从0开始 */
void do_something();
int main(int argc, char* argv[])
{
    /* 子进程个数 */
    int child_proc_number = MAX_CHILD_NUMBER;
    int i, ch;
    pid_t  child_pid = 0;
    pid_t pid[10]={0};/* 存放每个子进程的id */
    pid_t fpid[10]={0};
    if (argc > 1) /* 命令行参数第一个参数表示子进程个数*/
    {
        child_proc_number = atoi(argv[1]);
        child_proc_number= (child_proc_number > 10) ? 10 : child_proc_number;
    }
    
    for (i=0; i<child_proc_number; i++) {
        /* 填写代码，建立child_proc_number个子进程要执行
         * proc_number = i;
         * do_something();
         * 父进程把子进程的id保存到pid[i] */
        
        
        /***********************************/
        //for(int j=0;i<child_proc_number;j++)
        if(!(child_pid=fork())) break;
        /****创建child_proc_number个子进程****/
        /***********************************/
        
        
        /**********************************/
        if(child_pid<0){       //创建子进程失败则杀死之前创建的所有进程并退出
            printf("Creat child process fail\n");
            for (int i=0; i<proc_number+1; i++) {
                if(fpid[i]!=0){
                    kill(-pid[i], SIGTERM);
                if(pid[i]!=0)
                    kill(pid[ch-'0'], SIGTERM);
                }
            }
            exit(0);
        }else if(child_pid==0) pid[i]=getpid();  //如果是子进程则保存id到pid中
        else fpid[i]=getpid();                  //如果是父进程则保存id到fpid中
        /**********************************/
        proc_number = i;
        do_something();
    }
    /* 让用户选择杀死进程，数字表示杀死该进程，q退出 */
    printf("\nSelect a process to kill:");
    while ((ch = getchar()) != 'q')      {
        if (isdigit(ch))  {
            /*  填写代码，向pid[ch-'0']发信号SIGTERM,杀死该子进程 */
            if(pid[i]!=0){
                kill(pid[ch-'0'], SIGTERM);
                pid[ch-'0']=0;
            }
        }
        printf("\nSelect a process to kill:");
    }
    /* 在这里填写代码，杀死本组的所有进程 */
    for (int i=0; i<proc_number+1; i++) {
        if(fpid[i]!=0)
            kill(-fpid[i], SIGTERM);
        if(pid[i]!=0)
            kill(fpid[i], SIGTERM);
    }
    
    return 0;
}
void do_something() {
    //for(;;)  {
        printf("This is process No.%d and its pid is %d\n",proc_number,  getpid());
        sleep(SLEEP_INTERVAL); /* 主动阻塞两秒钟 */
    //}
} 

