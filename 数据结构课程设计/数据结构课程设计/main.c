#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max_CityNum 30     //最大城市数
#define TrafficNum 10      //每个城市最多的交通线路数
#define Max_CityName 12    //城市最长名称
#define INF 65535          //定义一个无穷大的量

typedef short int CiType;          //定义城市编号类型

typedef struct{
    int StartTime;
    int EndTime;
    CiType EndCity;
    char TrainNo[16];
    int cost;
}TrafficT;
//火车路线类型定义，包括起始时间，抵达时间，抵达城市编号，列车编号，票价

typedef struct{
    int StartTime;
    int EndTime;
    CiType EndCity;
    char FlightNo[16];
    int cost;
}TrafficF;
//飞机路线类型定义 ，包括起始时间，抵达时间，抵达城市编号，航班号，票价

typedef struct citynode{
    CiType city;
    int TrainNum;
    int FlightNum;
    TrafficT Train[TrafficNum];
    TrafficF Flight[TrafficNum];
}CityNode;
//城市节点类型定义 ，包括城市编号，火车路线数，飞机路线数，TrafficNum条火车路线，FlightNum条飞机路线

typedef struct pathnode{
    CiType city;
    int TrafficNo;
}PathNode;
//定义路径类型，

typedef struct arcnode{
    int cost;
    int TrafficNo;
}AdjMtrix;

/*****************************************************************************/

//全局变量声明区
const char CityFile[]="City.txt";
const char TrainFile[]="TrafficT.txt";
const char FlightFile[]="TrafficF.txt";

PathNode Path[Max_CityNum];              //用于存储遍历算法到达当前节点的路径
PathNode TePath[Max_CityNum];            //临时路径数组
PathNode MinPath[Max_CityNum];           //用于存储到达当前节点最短路径

char CityName[Max_CityNum][Max_CityName];    //声明用于存储城市名称的数组
int CityNum=0;    //当前添加的城市数

int StartTime;    //开始时间
int MinTime;      //当前为止的最小时间
int ThCityNum;    //遍历经过的城市数目 through city num
CityNode Graph[Max_CityNum];

/*****************************************************************************/

//函数段：

/*
 *******************************************************************************
 *打印菜单*
 *******************************************************************************
 */
void ShowMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:退出                               *\n");
    printf("\t\t*      1:进入管理员界面                     *\n");
    printf("\t\t*      2:进入旅客界面                       *\n");
    printf("\t\t*********************************************\n");
}
/*
 *******************************************************************************
 *打印管理员菜单*
 *******************************************************************************
 */
void AdminiMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:退出                               *\n");
    printf("\t\t*      1:添加城市                           *\n");
    printf("\t\t*      2:删除城市                           *\n");
    printf("\t\t*      3:添加列车路线                       *\n");
    printf("\t\t*      4:删除列车路线                       *\n");
    printf("\t\t*      5:添加航班路线                       *\n");
    printf("\t\t*      6:删除航班路线                       *\n");
    printf("\t\t*********************************************\n");
}


/*
 *******************************************************************************
 *打印旅客菜单*
 *******************************************************************************
 */
void PassMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:退出                               *\n");
    printf("\t\t*      1:最低花费                           *\n");
    printf("\t\t*      2:最小耗时                           *\n");
    printf("\t\t*********************************************\n");
}


/*
 *******************************************************************************
 *根据城市名查找，城市在全局变量数组中的编号*
 *******************************************************************************
 */
int Search(char *str){
    int i=0;
    for(;i<CityNum;i++){
        if(!(strcmp(str,CityName[i])))
            return i;
    }
    return -1;
}


/*
 *******************************************************************************
 *保存数据到文件*
 *******************************************************************************
 */
void SaveInfo(void){
    FILE *fp;
    int i,j;
    fp=fopen(CityFile,"w");
    fprintf(fp,"%2d\n",CityNum);  //保存城市数目
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%s\n",CityName[i]);  //保存城市名称
    }
    fclose(fp);
    fp=fopen(TrainFile,"w");
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%2d\n",Graph[i].TrainNum);       //保存该城市的列车数
        for(j=0;j<Graph[i].TrainNum;j++){
            fprintf(fp,"%s ",Graph[i].Train[j].TrainNo);   //保存此趟列车编号
            fprintf(fp,"%s %s ",CityName[i],CityName[Graph[i].Train[j].EndCity]);  //出发地和抵达地
            fprintf(fp,"%2d:%2d %2d:%2d ",Graph[i].Train[j].StartTime/60,Graph[i].Train[j].StartTime%60,Graph[i].Train[j].EndTime/60,Graph[i].Train[j].EndTime%60);
            fprintf(fp,"%3d\n",Graph[i].Train[j].cost);
        }
    }
    fclose(fp);
    fp=fopen(FlightFile,"w");
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%2d\n",Graph[i].FlightNum);
        for(j=0;j<Graph[i].FlightNum;j++){
            fprintf(fp,"%s ",Graph[i].Flight[j].FlightNo);
            fprintf(fp,"%s %s ",CityName[i],CityName[Graph[i].Flight[j].EndCity]);
            fprintf(fp,"%2d:%2d %2d:%2d ",Graph[i].Flight[j].StartTime/60,Graph[i].Flight[j].StartTime%60,Graph[i].Flight[j].EndTime/60,Graph[i].Flight[j].EndTime%60);
            fprintf(fp,"%3d\n",Graph[i].Flight[j].cost);
        }
    }
    fclose(fp);
}


/*
 *******************************************************************************
 *初始化，将数据从文件读入内存*
 *******************************************************************************
 */
void InitData(void){
    FILE *fp;
    int i,j;
    char temp1[Max_CityName],temp2[Max_CityName];
    int StartHour,StartMinute,EndHour,EndMinute;
    fp=fopen(CityFile,"r");
    fscanf(fp,"%2d\n",&CityNum);
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%s\n",&CityName[i]);
    }
    fclose(fp);
    fp=fopen(TrainFile,"r");
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%2d",&Graph[i].TrainNum);
        for(j=0;j<Graph[i].TrainNum;j++){
            fscanf(fp,"%s",&Graph[i].Train[j].TrainNo);
            fscanf(fp,"%s%s",&temp1,&temp2);
            Graph[i].Train[j].EndCity=Search(temp2);
            fscanf(fp,"%2d:%2d%2d:%2d",&StartHour,&StartMinute,&EndHour,&EndMinute);
            Graph[i].Train[j].StartTime=StartHour*60+StartMinute;
            Graph[i].Train[j].EndTime=EndHour*60+EndMinute;
            fscanf(fp,"%3d",&Graph[i].Train[j].cost);
        }
    }
    fclose(fp);
    fp=fopen(FlightFile,"r");
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%2d\n",&Graph[i].FlightNum);
        for(j=0;j<Graph[i].FlightNum;j++){
            fscanf(fp,"%s",&Graph[i].Flight[j].FlightNo);
            fscanf(fp,"%s%s",&temp1,&temp2);
            Graph[i].Flight[j].EndCity=Search(temp2);
            fscanf(fp,"%2d:%2d%2d:%2d",&StartHour,&StartMinute,&EndHour,&EndMinute);
            Graph[i].Flight[j].StartTime=StartHour*60+StartMinute;
            Graph[i].Flight[j].EndTime=EndHour*60+EndMinute;
            fscanf(fp,"%3d",&Graph[i].Flight[j].cost);
        }
    }
    fclose(fp);
}


/*
 *******************************************************************************
 *添加城市信息*
 *******************************************************************************
 */
int AddCity(char *Str){
    int i=Search(Str);//若输入城市已经在城市数组中，就无需插入了
    if(i==-1){
        strcpy(CityName[CityNum],Str);
        Graph[CityNum].FlightNum=0;
        Graph[CityNum].TrainNum=0;
        Graph[CityNum].city=CityNum;
        CityNum++;
        return 1;
    }else return 1;
    return 0;
}


/*
 *******************************************************************************
 *删除城市信息*
 *******************************************************************************
 */
int DeleCity(char *Str){
    int i=Search(Str);
    int j;
    if(i==-1){
        return 1;
    }else {
        for(;i<CityNum-1;i++){
            strcpy(CityName[i],CityName[i+1]);
            Graph[i].FlightNum=Graph[i+1].FlightNum;
            Graph[i].TrainNum=Graph[i+1].TrainNum;
            for(j=0;j<Graph[i].TrainNum;j++){
                strcpy(Graph[i].Train[j].TrainNo,Graph[i+1].Train[j].TrainNo);
                Graph[i].Train[j].StartTime=Graph[i+1].Train[j].StartTime;
                Graph[i].Train[j].EndTime=Graph[i+1].Train[j].EndTime;
                Graph[i].Train[j].cost=Graph[i+1].Train[j].cost;
                Graph[i].Train[j].EndCity=Graph[i+1].Train[j].EndCity;
            }
        }
        CityNum --;
        return 1;
    }
    return 0;
}


/*
 *******************************************************************************
 *添加交通线路*
 ********************************************************************************/

/* 函数名:AddTrain 参数列表:SC-出发城市  EC-抵达城市  ST-出发时间  ET-抵达时间  TN-列车/航班编号  cost-票价  TT-路线类型*/
int AddTraffic(int TT,CiType SC,CiType EC,int ST,int ET,char *TN,int cost){
    if(!TT){
        if(Graph[SC].TrainNum<TrafficNum){
            Graph[SC].Train[Graph[SC].TrainNum].StartTime=ST;
            Graph[SC].Train[Graph[SC].TrainNum].EndTime=ET;
            Graph[SC].Train[Graph[SC].TrainNum].EndCity=EC;
            Graph[SC].Train[Graph[SC].TrainNum].cost= cost;
            strcpy(Graph[SC].Train[Graph[SC].TrainNum].TrainNo,TN);
            Graph[SC].TrainNum++;
            return 1;
        }else {
            printf("该城市列车路线已满");
            return 0;
        }
    }else{
        if(Graph[SC].FlightNum<TrafficNum){
            Graph[SC].Flight[Graph[SC].FlightNum].StartTime=ST;
            Graph[SC].Flight[Graph[SC].FlightNum].EndTime=ET;
            Graph[SC].Flight[Graph[SC].FlightNum].EndCity=EC;
            Graph[SC].Flight[Graph[SC].FlightNum].cost= cost;
            strcpy(Graph[SC].Flight[Graph[SC].FlightNum].FlightNo,TN);
            Graph[SC].FlightNum++;
            return 1;
        }else {
            printf("该城市航班路线已满");
            return 0;
        }
    }
}


/*
 *******************************************************************************
 *删除交通线路*
 *******************************************************************************
 */
int DeleTraffic(int TT,CiType SC,CiType EC){
    int j,i,tag=0;
    if(!TT){
        if(Graph[SC].TrainNum>0){
            for(j=0;j<Graph[SC].TrainNum;j++){
                if(Graph[SC].Train[j].EndCity==EC){
                    for(i=j;i<Graph[SC].TrainNum-1;i++){
                        Graph[SC].Train[i]=Graph[SC].Train[i+1];
                        Graph[SC].TrainNum--;
                    }
                    tag=1;
                }
            }
            if(!tag) return 0;
            else return 1;
        }else {
            return 0;
        }
    }else{
        if(Graph[SC].FlightNum>0){
            for(j=0;j<Graph[SC].FlightNum;j++){
                if(Graph[SC].Flight[j].EndCity==EC){
                    for(i=j;i<Graph[SC].FlightNum-1;i++){
                        Graph[SC].Flight[i]=Graph[SC].Flight[i+1];
                        Graph[SC].FlightNum--;
                    }
                    tag=1;
                }
            }
            if(!tag) return 0;
            else return 1;
        }else {
            return 0;
        }
    }
}

/*
 *******************************************************************************
 *寻找最低花费路线*
 *******************************************************************************
 */
int Dijkstra(AdjMtrix Arcs[][Max_CityNum],CiType StartCity,CiType EndCity){
    int i,j,k = 0,min;
    int *dist=(int*)malloc(CityNum*sizeof(int));
    int *Tag=(int*)malloc(CityNum*sizeof(int));
    memset(Tag,0,CityNum*sizeof(int));
    for(i=0;i<CityNum;i++){
        dist[i]=Arcs[StartCity][i].cost;
        if(dist[i]!=INF){
            Path[i].city=StartCity;
            Path[i].TrafficNo=Arcs[StartCity][i].TrafficNo;
        }
    }
    Tag[StartCity]=1;
    while(Tag[EndCity]==0){
        min=INF;
        for(j=0;j<CityNum;j++){
            if(!Tag[j]&&dist[j]<min){
                min=dist[j];
                k=j;
            }
        }
        if(min==INF) return 0;
        Tag[k]=1;
        for(j=0;j<CityNum;j++){
            if(!Tag[j]&&(dist[k]+Arcs[k][j].cost<dist[j])){
                Path[j].city=k;
                Path[j].TrafficNo=Arcs[k][j].TrafficNo;
                dist[j]=Arcs[k][j].cost+dist[k];
            }
        }
    }
    free(dist);
    free(Tag);
    return 1;
}
/*
 *******************************************************************************
 *计算最低花费并打印*
 *******************************************************************************
 */

/*函数名:CalcuMincost  参数列表:TT-出行方式  StartCity-出发城市   EndCity-抵达城市*/

void CalcuMincost(int TT,CiType StartCity,CiType EndCity){
    int i,j,k,t,min,flag;
    int Mincost=0;
    int StartH,StartM,EndH,EndM;
    AdjMtrix Matx[Max_CityNum][Max_CityNum];
    for(i=0;i<Max_CityNum;i++){
        for(j=0;j<Max_CityNum;j++){
            Matx[i][j].cost=INF;
        }
    }//初始化邻接矩阵，将每条边的权值都只为无穷大
    
    if(!TT){
        for(i=0;i<CityNum;i++){
            for(j=0;j<Graph[i].TrainNum;j++){
                t=j;
                min=Graph[i].Train[j].cost;
                for(k=j+1;k<Graph[i].TrainNum;k++){
                    if((Graph[i].Train[j].EndCity==Graph[i].Train[k].EndCity)&&(Graph[i].Train[k].cost<min)){
                        min=Graph[i].Train[k].cost;
                        t=k;
                    }
                }
                Matx[i][Graph[i].Train[t].EndCity].cost=min;
                Matx[i][Graph[i].Train[t].EndCity].TrafficNo=t;
            }
        }
    }else{
        for(i=0;i<CityNum;i++){
            for(j=0;j<Graph[i].FlightNum;j++){
                t=j;
                min=Graph[i].Flight[j].cost;
                for(k=j+1;k<Graph[i].FlightNum;k++){
                    if((Graph[i].Flight[j].EndCity==Graph[i].Flight[k].EndCity)&&(Graph[i].Flight[k].cost<min)){
                        min=Graph[i].Flight[k].cost;
                        t=k;
                    }
                }
                Matx[i][Graph[i].Flight[t].EndCity].cost=min;
                Matx[i][Graph[i].Flight[t].EndCity].TrafficNo=t;
            }
        }
    }
    //扫描图中每个城市出发交通线路，并将每条线路到抵达城市最小费用赋值到邻接矩阵中
    flag=Dijkstra(Matx,StartCity,EndCity);
    if(flag){
        if(!TT){
            i=EndCity;
            while(Path[i].city!=StartCity){
                printf("%s:",Graph[Path[i].city].Train[Path[i].TrafficNo].TrainNo);
                StartH=Graph[Path[i].city].Train[Path[i].TrafficNo].StartTime/60;
                StartM=Graph[Path[i].city].Train[Path[i].TrafficNo].StartTime%60;
                EndH=Graph[Path[i].city].Train[Path[i].TrafficNo].EndTime/60;
                EndM=Graph[Path[i].city].Train[Path[i].TrafficNo].EndTime%60;
                printf("  %d:%d -- %d:%d ",StartH,StartM,EndH,EndM);
                printf("%s--%s\n",CityName[Path[i].city],CityName[i]);
                i=Path[i].city;
                Mincost+=Graph[Path[i].city].Train[Path[i].TrafficNo].cost;
            }
            printf("%s:",Graph[Path[i].city].Train[Path[i].TrafficNo].TrainNo);
            StartH=Graph[Path[i].city].Train[Path[i].TrafficNo].StartTime/60;
            StartM=Graph[Path[i].city].Train[Path[i].TrafficNo].StartTime%60;
            EndH=Graph[Path[i].city].Train[Path[i].TrafficNo].EndTime/60;
            EndM=Graph[Path[i].city].Train[Path[i].TrafficNo].EndTime%60;
            printf("  %d:%d -- %d:%d ",StartH,StartM,EndH,EndM);
            printf("%s--%s\n",CityName[Path[i].city],CityName[i]);
            Mincost+=Graph[Path[i].city].Train[Path[i].TrafficNo].cost;
            printf("最小花费：%d\n",Mincost);
        }else{
            i=EndCity;
            while(Path[i].city!=StartCity){
                printf("%s:",Graph[Path[i].city].Flight[Path[i].TrafficNo].FlightNo);
                StartH=Graph[Path[i].city].Flight[Path[i].TrafficNo].StartTime/60;
                StartM=Graph[Path[i].city].Flight[Path[i].TrafficNo].StartTime%60;
                EndH=Graph[Path[i].city].Flight[Path[i].TrafficNo].EndTime/60;
                EndM=Graph[Path[i].city].Flight[Path[i].TrafficNo].EndTime%60;
                printf("  %d:%d -- %d:%d ",StartH,StartM,EndH,EndM);
                printf("%s--%s\n",CityName[Path[i].city],CityName[i]);
                i=Path[i].city;
                Mincost+=Graph[Path[i].city].Flight[Path[i].TrafficNo].cost;
            }
            printf("%s:",Graph[Path[i].city].Flight[Path[i].TrafficNo].FlightNo);
            StartH=Graph[Path[i].city].Flight[Path[i].TrafficNo].StartTime/60;
            StartM=Graph[Path[i].city].Flight[Path[i].TrafficNo].StartTime%60;
            EndH=Graph[Path[i].city].Flight[Path[i].TrafficNo].EndTime/60;
            EndM=Graph[Path[i].city].Flight[Path[i].TrafficNo].EndTime%60;
            printf("  %d:%d -- %d:%d ",StartH,StartM,EndH,EndM);
            printf("%s--%s\n",CityName[Path[i].city],CityName[i]);
            Mincost+=Graph[Path[i].city].Flight[Path[i].TrafficNo].cost;
            printf("最小花费：%d\n",Mincost);
        }
    }else printf("两城市间无连同的线路\n");
    
}




/*
 *******************************************************************************
 *查找最低耗时路径*  Travel type , Mean ciity , Mean time ,Now throuh path num
 *******************************************************************************
 */
/*函数名:SearchMinTime  参数列表:TT-出行方式   MeCity-当前到达的城市    EndCity-目的地  MeTime-截止到现在的时间  NTPathNum-当前经过的城市数  */
void SearchMinTime(int TT,CiType MeCity,CiType EndCity,int MeTime,int NTPathNum){
    int i;
    if(MeCity==EndCity){
        if(MeTime-StartTime<MinTime){
            for(i=0;i<NTPathNum+1;i++){
                MinPath[i].city=TePath[i].city;
                MinPath[i].TrafficNo=TePath[i].TrafficNo;
            }
            ThCityNum=NTPathNum;
            MinTime=MeTime-StartTime;
        }
    }else{
        NTPathNum++;
        TePath[NTPathNum].city=MeCity;
        if(!TT){
            for(i=0;i<Graph[MeCity].TrainNum;i++){
                if(Graph[MeCity].Train[i].StartTime>=(MeTime%(24*60))&&(Graph[MeCity].Train[i].EndTime+(MeTime/1440)*1440)-StartTime<MinTime){
                    TePath[NTPathNum].TrafficNo=i;
                    SearchMinTime(TT,Graph[MeCity].Train[i].EndCity,EndCity,(Graph[MeCity].Train[i].EndTime+(MeTime/1440)*1440),NTPathNum);
                }
                if(Graph[MeCity].Train[i].StartTime<(MeTime%(24*60))&&(Graph[MeCity].Train[i].EndTime+(MeTime/1440)*1440)-StartTime<MinTime){
                    TePath[NTPathNum].TrafficNo=i;
                    SearchMinTime(TT,Graph[MeCity].Train[i].EndCity,EndCity,(Graph[MeCity].Train[i].EndTime+(MeTime/1440+1)*1440),NTPathNum);
                }
            }
        }else{
            for(i=0;i<Graph[MeCity].FlightNum;i++){
                if(Graph[MeCity].Flight[i].StartTime>=(MeTime%(24*60))&&(Graph[MeCity].Flight[i].EndTime+(MeTime/1440)*1440)-StartTime<MinTime){
                    TePath[NTPathNum].TrafficNo=i;
                    SearchMinTime(TT,Graph[MeCity].Flight[i].EndCity,EndCity,Graph[MeCity].Flight[i].EndTime+(MeTime/1440)*1440,NTPathNum);
                }
                if(Graph[MeCity].Flight[i].StartTime<(MeTime%(24*60))&&(Graph[MeCity].Flight[i].EndTime+(MeTime/1440)*1440)-StartTime<MinTime){
                    TePath[NTPathNum].TrafficNo=i;
                    SearchMinTime(TT,Graph[MeCity].Flight[i].EndCity,EndCity,Graph[MeCity].Flight[i].EndTime+(MeTime/1440+1)*1440,NTPathNum);
                }
            }
        }
    }
}


/*
 *******************************************************************************
 *计算最低耗时路径所需时间，并打印路径上的每个城市应选择的交通信息*
 *******************************************************************************
 */
/*函数名:CalcuMinTime  参数列表:TT-出行方式   StartCity-起始城市   EndCity-抵达城市*/
void CalcuMinTime(int TT,CiType StartCity,CiType EndCity){
    int i;
    int StartH,StartM,EndH,EndM;
    MinTime=INF;
    ThCityNum=0;
    TePath[0].city=StartCity;
    if(!TT){
        for(i=0;i<Graph[StartCity].TrainNum;i++){
            TePath[0].TrafficNo=i;
            StartTime=Graph[StartCity].Train[i].StartTime;
            SearchMinTime(TT,Graph[StartCity].Train[i].EndCity,EndCity,Graph[StartCity].Train[i].EndTime,0);
        }
    }else{
        for(i=0;i<Graph[StartCity].FlightNum;i++){
            TePath[0].TrafficNo=i;
            StartTime=Graph[StartCity].Flight[i].StartTime;
            SearchMinTime(TT,Graph[StartCity].Flight[i].EndCity,EndCity,Graph[StartCity].Flight[i].EndTime,0);
        }
    }
    if(MinTime==INF){
        printf("两城市之间无连同路径\n");
    }else {
        if(!TT){
            /*printf("所应经过的路程是:\n");
             for(i=0;i<=ThCityNum;i++){
             printf("%s ",CityName[MinPath[i].city]);
             }*/
            printf("\n应在相应时间乘坐以下列车:\n");
            for(i=0;i<=ThCityNum;i++){
                StartH=Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].StartTime/60;
                StartM=Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].StartTime%60;
                EndH=Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].EndTime/60;
                EndM=Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].EndTime%60;
                printf("%d:%d在 %s乘坐: %s 于 %d:%d 抵达:",StartH,StartM,CityName[MinPath[i].city],Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].TrainNo,EndH,EndM);
                printf("%s\n",CityName[Graph[MinPath[i].city].Train[MinPath[i].TrafficNo].EndCity]);
            }
            printf("共耗时：%d天%d小时%d分钟\n",MinTime/1440,MinTime/60,MinTime%60);
        }else{
            printf("\n应在相应时间乘坐以下航班:\n");
            for(i=0;i<=ThCityNum;i++){
                StartH=Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].StartTime/60;
                StartM=Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].StartTime%60;
                EndH=Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].EndTime/60;
                EndM=Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].EndTime%60;
                printf("%d:%d在 %s乘坐: %s 于 %d:%d 抵达:",StartH,StartM,CityName[MinPath[i].city],Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].FlightNo,EndH,EndM);
                printf("%s\n",CityName[Graph[MinPath[i].city].Flight[MinPath[i].TrafficNo].EndCity]);
            }
            printf("共耗时：%d\n",MinTime);
        }
        
    }
}
int main(void){
    int Require,require,tag;
    char StartCity[Max_CityName],EndCity[Max_CityName];
    char CityN[Max_CityName],TN[16];
    int TT,StartH,StartM,EndH,EndM,ST,ET,cost;
    CiType SC,EC;
    printf("******************欢迎使用06143047号城市交通咨询模拟系统************************\n");
    while(1){
        ShowMenu();
        printf("\n请输入你的需求:");
        scanf("%d",&Require);
        switch(Require){
            case 0:
                return 0;
            case 1:
                AdminiMenu();
                printf("\n管理员，您好！请输入您的需求:");
                scanf("%d",&require);
                switch(require){
                    case 0:return 0;
                    case 1:
                        printf("\n请输入添加城市名:");
                        scanf("%s",&CityN);
                        InitData();
                        tag=AddCity(CityN);
                        SaveInfo();
                        if(tag) printf("\n添加成功!\n");
                        break;
                    case 2:
                        printf("\n请输入删除城市名:");
                        scanf("%s",&CityN);
                        InitData();
                        tag=DeleCity(CityN);
                        SaveInfo();
                        if(tag) printf("\n删除成功!\n");
                        break;
                    case 3:
                        InitData();
                        //printf("\n请输入添加的交通线路类型:(0:火车 1:飞机)");
                        //scanf("%d",&TT);
                        printf("\n请输入路线起点:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入路线终点:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入发车时间:");
                        scanf("%d%d",&StartH,&StartM);
                        ST=StartH*60+StartM;
                        printf("\n请输入抵达时间:");
                        scanf("%d%d",&EndH,&EndM);
                        ET=EndH*60+EndM;
                        printf("\n请输入该列车编号:");
                        scanf("%s",&TN);
                        printf("\n请输入票价:");
                        scanf("%d",&cost);
                        AddTraffic(0,SC,EC,ST,ET,TN,cost);
                        SaveInfo();
                        break;
                    case 4:
                        InitData();
                        //printf("\n请输入要删除的交通线路类型:(0:火车 1:飞机)");
                        //scanf("%d",&TT);
                        printf("\n请输入要删除路线的起点:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入要删除路线的终点:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        DeleTraffic(0,SC,EC);
                        SaveInfo();
                        break;
                    case 5:
                        InitData();
                        //printf("\n请输入添加的交通线路类型:(0:火车 1:飞机)");
                        //scanf("%d",&TT);
                        printf("\n请输入路线起点:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入路线终点:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入发车时间:");
                        scanf("%d%d",&StartH,&StartM);
                        ST=StartH*60+StartM;
                        printf("\n请输入抵达时间:");
                        scanf("%d%d",&EndH,&EndM);
                        ET=EndH*60+EndM;
                        printf("\n请输入该航班编号:");
                        scanf("%s",&TN);
                        printf("\n请输入票价:");
                        scanf("%d",&cost);
                        AddTraffic(1,SC,EC,ST,ET,TN,cost);
                        SaveInfo();
                        break; 
                    case 6:
                        InitData();
                        //printf("\n请输入要删除的交通线路类型:(0:火车 1:飞机)");
                        //scanf("%d",&TT);
                        printf("\n请输入要删除路线的起点:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入要删除路线的终点:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        DeleTraffic(1,SC,EC);
                        SaveInfo();
                        break; 
                }
                break;
            case 2:
                PassMenu();
                printf("\n旅客，您好！请输入您的需求:");
                scanf("%d",&require);
                switch(require){
                    case 0: return 0;
                    case 1:
                        InitData();
                        printf("\n请选择出行方式:(0:火车 1:飞机)");
                        scanf("%d",&TT);
                        printf("\n请输入起点城市:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入要抵达的终点:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        CalcuMincost(TT,SC,EC);
                        break; 
                    case 2:
                        InitData();
                        printf("\n请选择出行方式:(0:火车 1:飞机)");
                        scanf("%d",&TT);
                        printf("\n请输入起点城市:");
                        scanf("%s",&StartCity);
                        SC=Search(StartCity);
                        if(SC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        printf("\n请输入终点城市:");
                        scanf("%s",&EndCity);
                        EC=Search(EndCity);
                        if(EC==-1) {
                            printf("\n路线网中无该城市!");
                            break;
                        }
                        CalcuMinTime(TT,SC,EC);
                        break;  
                }
                break;	
        }
    } 
    return 0;
}
