//
//  main.c
//  调试1
//
//  Created by mac on 15/11/10.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#define N 3
#define Y 5
void average_only(double (*array)[Y])
{
    int i,j;
    double t;
    for(i=0;i<N;i++)
    {   t=0;
        for(j=0;j<Y;j++)
        {
            t=t+array[i][j];
        }
        printf("%2.0lf－－%2.0lf\n",t,t/N);
    }
}
int main(void)
{
    /*double array[N][Y];
    int i,j;
    printf("Please intput three counts:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<Y;j++)
        {
            scanf("%lf",&array[i][j]);
        }
    }
    average_only(array);
    for(i=0;i<N;i++)
     {
     for(j=0;j<Y;j++)
     {
     printf("%2.0lf",array[i][j]);
     }
     printf("\n");
     }*/
    printf("%d",037777777777);
    return 0;
}