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
	printf("请输入顶点数:");
	scanf("%d",G->vexnum);
	printf("请输入边数:");
	scanf("%d",G->arcnum);
	for(i=0;i<G->vexnum;i++){
		printf("请输入第%d个顶点",i+1);
		scanf("%c",G->vertex[i].data);
		G->vertex[i].Head=p;
		printf("请输入该顶点邻接的所有顶点，孤立点输入99");
		scanf("%d",&c);
		if(c==99) continue; 
		else while(c!=99){
			      p=(ArcNode * )malloc(sizeof(ArcNode));
			      p->vex=c;
				  printf("该边权值：");
				  scanf("%d",&c);
				  p->weight=c;
				  p->next=G->vertex[i].Head;
				  G->vertex[i].Head=p;
				  p=NULL;
				  printf("请输入该顶点的下一个邻接点");
				  scanf("%d",&c);
		}
	}
}
/*创建一个Edge数组保存从邻接表上扫描得到的边信息，并按权值升序排列所有边*/
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
/*Kruskal 算法*/
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
			printf("%c<--->%c  权值为:%d",G->vertex[(Edge[j].start)].data,G->vertex[(Edge[j].end)].data,Edge[j].weight);
		}
	}
	free(Parent);
}