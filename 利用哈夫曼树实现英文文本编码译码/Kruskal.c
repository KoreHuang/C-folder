#include<stdio.h>
#include<stdlib.h>
#define Maxsize 20
typedef struct Arcnode{
	int vex;
	int weight;
	struct Arcnode *next;
}ArcNode;
typedef struct{
	char data;
	ArcNode *Head;
}VexType;
typedef struct {
	VexType vertex[Maxsize];
	int vexnum;
	int arcnum;
}AdjList;
typedef struct {
	int start;
	int end;
	int weight;
}EdgeType;
/*creat the graph*/
void CreatGraph(AdjList *G){
	int i;
	int c;
	ArcNode *p=NULL;
	printf("�����붥����:");
	scanf("%d",G->vexnum);
	printf("���������:");
	scanf("%d",G->arcnum);
	for(i=0;i<G->vexnum;i++){
		printf("�������%d������",i+1);
		scanf("%c",G->vertex[i].data);
		G->vertex[i].Head=p;
		printf("������ö����ڽӵ����ж��㣬����������99");
		scanf("%d",&c);
		if(c==99) continue; 
		else while(c!=99){
			      p=(ArcNode * )malloc(sizeof(ArcNode));
			      p->vex=c;
				  printf("�ñ�Ȩֵ��");
				  scanf("%d",&c);
				  p->weight=c;
				  p->next=G->vertex[i].Head;
				  G->vertex[i].Head=p;
				  p=NULL;
				  printf("������ö������һ���ڽӵ�");
				  scanf("%d",&c);
		}
	}
}
/*����һ��Edge���鱣����ڽӱ���ɨ��õ��ı���Ϣ������Ȩֵ�����������б�*/
void CpArc(AdjList *G,EdgeType *Edge){
	int i,j=0,tag;
	ArcNode *p=NULL;
	EdgeType temp;
	for(i=0;i<G->vexnum;i++){
		p=G->vertex[i].Head;
		while(p!=NULL){
			if(p->vex>i){
				Edge[j].start=i;
				Edge[j].end=p->vex;
				Edge[j].weight=p->weight;
				j++;
			}
		}
	}
	tag=j;
	for(i=0;i<tag;i++){
		for(j=i;j<tag;j++){
			if(Edge[j].weight<Edge[i].weight){
				temp=Edge[i];
				Edge[i]=Edge[j];
				Edge[j]=temp;
			}
		}
	}
}
int Search(int p[],int t){
	while(p[t]>0){
		t=p[t];
	}
	return t;
}
/*Kruskal �㷨*/
void Kruskal(EdgeType *Edge,AdjList *G){
	int m,n,i,j;
	int *Parent;
	Parent=(int *)malloc((G->vexnum)*sizeof(int));
	for(i=0;i<G->vexnum;i++)
		Parent[i]=0;
	for(j=0;j<G->arcnum;j++){
		n=Search(Parent,Edge[j].start);
		m=Search(Parent,Edge[j].end);
		if(m!=n){
			Parent[n]=m;
			printf("%c<--->%c  ȨֵΪ:%d",G->vertex[(Edge[j].start)].data,G->vertex[(Edge[j].end)].data,Edge[j].weight);
		}
	}
	free(Parent);
}