#include<stdio.h>
#include<string.h>

#define Max_CityNum 30     //◊Ó¥Û≥« – ˝
#define TrafficNum 10      //√ø∏ˆ≥« –◊Ó∂‡µƒΩªÕ®œﬂ¬∑ ˝
#define Max_CityName 12    //≥« –◊Ó≥§√˚≥∆

typedef short int CiType;          //∂®“Â≥« –±‡∫≈¿‡–Õ

typedef struct{
    int StartTime;
    int EndTime;
    CiType EndCity;
    char TrainNo[16];
    int cost;
}TrafficT;
//ª≥µ¬∑œﬂ¿‡–Õ∂®“Â£¨∞¸¿®∆ º ±º‰£¨µ÷¥Ô ±º‰£¨µ÷¥Ô≥« –±‡∫≈£¨¡–≥µ±‡∫≈£¨∆±º€
typedef struct{
    int StartTime;
    int EndTime;
    CiType EndCity;
    char FlightNo[16];
    int cost;
}TrafficF;
//∑…ª˙¬∑œﬂ¿‡–Õ∂®“Â £¨∞¸¿®∆ º ±º‰£¨µ÷¥Ô ±º‰£¨µ÷¥Ô≥« –±‡∫≈£¨∫Ω∞‡∫≈£¨∆±º€
typedef struct citynode{
    CiType city;
    int TrainNum;
    int FlightNum;
    TrafficT Train[TrafficNum];
    TrafficF Flight[TrafficNum];
}CityNode;
//≥« –Ω⁄µ„¿‡–Õ∂®“Â £¨∞¸¿®≥« –±‡∫≈£¨ª≥µ¬∑œﬂ ˝£¨∑…ª˙¬∑œﬂ ˝£¨TrafficNumÃıª≥µ¬∑œﬂ£¨∑…ª˙¬∑œﬂ
typedef struct pathnode{
    int city;
    char TrainNo[16];
}PathNode;
//∂®“Â¬∑æ∂¿‡–Õ£¨
/*************************************************************************************/
//»´æ÷±‰¡ø…˘√˜«¯
const char CityFile[]="City.txt";
const char TrainFile[]="TrafficT.txt";
const char FlightFile[]="TrafficF.txt";

PathNode Path[Max_CityNum];              //”√”⁄¥Ê¥¢±È¿˙À„∑®µΩ¥Ôµ±«∞Ω⁄µ„µƒ¬∑æ∂
PathNode MinPath[Max_CityNum];           //”√”⁄¥Ê¥¢µΩ¥Ôµ±«∞Ω⁄µ„◊Ó∂Ã¬∑æ∂

char CityName[Max_CityNum][Max_CityName];    //…˘√˜”√”⁄¥Ê¥¢≥« –√˚≥∆µƒ ˝◊È
int CityNum=0;    //µ±«∞ÃÌº”µƒ≥« – ˝

int StartTime;    //ø™ º ±º‰
int MinTime;      //µ±«∞Œ™÷πµƒ◊Ó–° ±º‰
int ThCityNum;    //±È¿˙æ≠π˝µƒ≥« – ˝ƒø
CityNode Graph[Max_CityNum];
/*************************************************************************************/

//∫Ø ˝∂Œ£∫
/*
 ***************************************************************************************
 *¥Ú”°≤Àµ•*
 ***************************************************************************************
 */
void ShowMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:ÕÀ≥ˆ                               *\n");
    printf("\t\t*      1:Ω¯»Îπ‹¿Ì‘±ΩÁ√Ê                     *\n");
    printf("\t\t*      2:Ω¯»Î¬√øÕΩÁ√Ê                       *\n");
    printf("\t\t*********************************************\n");
}
/*
 ***************************************************************************************
 *¥Ú”°π‹¿Ì‘±≤Àµ•*
 ***************************************************************************************
 */
void AdminiMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:ÕÀ≥ˆ                               *\n");
    printf("\t\t*      1:ÃÌº”≥« –                           *\n");
    printf("\t\t*      2:…æ≥˝≥« –                           *\n");
    printf("\t\t*      3:ÃÌº”¡–≥µ¬∑œﬂ                       *\n");
    printf("\t\t*      4:…æ≥˝¡–≥µ¬∑œﬂ                       *\n");
    printf("\t\t*      5:ÃÌº”∫Ω∞‡¬∑œﬂ                       *\n");
    printf("\t\t*      6:…æ≥˝∫Ω∞‡¬∑œﬂ                       *\n");
    printf("\t\t*********************************************\n");
}
/*
 ***************************************************************************************
 *¥Ú”°¬√øÕ≤Àµ•*
 ***************************************************************************************
 */
void PassMenu(void){
    printf("\t\t*********************************************\n");
    printf("\t\t*      0:ÕÀ≥ˆ                               *\n");
    printf("\t\t*      1:◊ÓµÕª®∑—                           *\n");
    printf("\t\t*      2:◊Ó–°∫ƒ ±                           *\n");
    printf("\t\t*********************************************\n");
}
/*
 ***************************************************************************************
 *∏˘æ›≥« –√˚≤È’“£¨≥« –‘⁄»´æ÷±‰¡ø ˝◊È÷–µƒ±‡∫≈*
 ***************************************************************************************
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
 ***************************************************************************************
 *±£¥Ê ˝æ›µΩŒƒº˛*
 ***************************************************************************************
 */
void SaveInfo(void){
    FILE *fp;
    int i,j;
    fp=fopen(CityFile,"w");
    fprintf(fp,"%2d\n",CityNum);  //±£¥Ê≥« – ˝ƒø
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%s\n",CityName[i]);  //±£¥Ê≥« –√˚≥∆
    }
    fclose(fp);
    fp=fopen(TrainFile,"w");
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%2d\n",Graph[i].TrainNum);       //±£¥Ê∏√≥« –µƒ¡–≥µ ˝
        for(j=0;j<Graph[i].TrainNum;j++){
            fprintf(fp,"%s:",Graph[i].Train[j].TrainNo);   //±£¥Ê¥ÀÃÀ¡–≥µ±‡∫≈
            fprintf(fp,"%s-%s",CityName[i],CityName[Graph[i].Train[j].EndCity]);  //≥ˆ∑¢µÿ∫Õ º∑¢µÿ
            fprintf(fp,"%2d:%2d-%2d:%2d\n",Graph[i].Train[j].StartTime/60,Graph[i].Train[j].StartTime%60,Graph[i].Train[j].EndTime/60,Graph[i].Train[j].EndTime%60);
            fprintf(fp,"%3d",Graph[i].Train[j].cost);
        }
    }
    fclose(fp);
    fp=fopen(FlightFile,"w");
    for(i=0;i<CityNum;i++){
        fprintf(fp,"%2d\n",Graph[i].FlightNum);
        for(j=0;j<Graph[i].TrainNum;j++){
            fprintf(fp,"%s:",Graph[i].Flight[j].FlightNo);
            fprintf(fp,"%s-%s",CityName[i],CityName[Graph[i].Flight[j].EndCity]);
            fprintf(fp,"%2d:%2d-%2d:%2d\n",Graph[i].Flight[j].StartTime/60,Graph[i].Flight[j].StartTime%60,Graph[i].Flight[j].EndTime/60,Graph[i].Flight[j].EndTime%60);
            fprintf(fp,"%3d",Graph[i].Flight[j].cost);
        }
    }
    fclose(fp);
}
/*
 ***************************************************************************************
 *≥ı ºªØ£¨Ω´ ˝æ›¥”Œƒº˛∂¡»Îƒ⁄¥Ê*
 ***************************************************************************************
 */
void InitData(void){
    FILE *fp;
    int i,j;
    char temp1[Max_CityName],temp2[Max_CityName];
    int StartHour,StartMinute,EndHour,EndMinute;
    fp=fopen(CityFile,"r");
    fscanf(fp,"%2d",&CityNum);
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%s",CityName[i]);
    }
    fclose(fp);
    fp=fopen(TrainFile,"r");
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%2d",&Graph[i].TrainNum);
        for(j=0;j<Graph[i].TrainNum;j++){
            fscanf(fp,"%s:",Graph[i].Train[j].TrainNo);
            fscanf(fp,"%s-%s",temp1,temp2);
            Graph[i].Train[j].EndCity=Search(temp2);
            fscanf(fp,"%2d:%2d-%2d:%2d\n",&StartHour,&StartMinute,&EndHour,&EndMinute);
            Graph[i].Train[j].StartTime=StartHour*60+StartMinute;
            Graph[i].Train[j].EndTime=EndHour*60+EndMinute;
            fscanf(fp,"%3d",&Graph[i].Train[j].cost);
        }
    }
    fclose(fp);
    fp=fopen(FlightFile,"r");
    for(i=0;i<CityNum;i++){
        fscanf(fp,"%2d\n",&Graph[i].FlightNum);
        for(j=0;j<Graph[i].TrainNum;j++){
            fscanf(fp,"%s:",Graph[i].Flight[j].FlightNo);
            fscanf(fp,"%s-%s",temp1,temp2);
            Graph[i].Flight[j].EndCity=Search(temp2);
            fscanf(fp,"%2d:%2d-%2d:%2d\n",&StartHour,&StartMinute,&EndHour,&EndMinute);
            Graph[i].Flight[j].StartTime=StartHour*60+StartMinute;
            Graph[i].Flight[j].EndTime=EndHour*60+EndMinute;
            fscanf(fp,"%3d",&Graph[i].Flight[j].cost);
        }
    }
    fclose(fp);
}
/*
 ***************************************************************************************
 *ÃÌº”≥« ––≈œ¢*
 ***************************************************************************************
 */
int AddCity(char *Str){
    int i=Search(Str);
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
 ***************************************************************************************
 *…æ≥˝≥« ––≈œ¢*
 ***************************************************************************************
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
        CityNum--;
        return 1;
    }
    return 0;
}

int main(void){
    int i;
    InitData();
    printf("%d\n",CityNum);
    for(i=0;i<CityNum;i++){
        printf("%s\n",CityName[i]);
    }
    return 0;
}
