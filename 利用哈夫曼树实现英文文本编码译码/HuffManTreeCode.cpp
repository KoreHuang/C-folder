 #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define N 256
#define M 2*N-1

typedef struct
{
	int weight;//权值
	int parent;//双亲结点
	int lchild;//左孩子
	int rchild;//右孩子
}HTNode;       //哈夫曼树结点

typedef struct
{
	int count;//字符出现的次数
	char ch;//保存出现的字符
}Data;
/**************************************************************/
void select(HTNode *ht,int n,int *s1 ,int *s2);
void CrtHuffManTree(HTNode *ht , int *w , int n);
void CrtHuffManCode(HTNode *ht,char **hc,int n);
void DeCodeHuffMan(char *fname,char *oname,char **hc,int n,char *q);
void CrtFileCode(char *fname,char *oname,char **hc,int n,char *q);
void CountWeight(char *fname,Data *code,int *n);
/**************************************************************/

/**************************************************************
**Function Name：CrtHuffManTree
**Description  ：创建哈夫曼树
**Parameters   ：ht：结构体数组存储哈夫曼树，w：权值数组
                 n：叶子结点数              
**Return Value ：无
***************************************************************/
void CrtHuffManTree(HTNode *ht , int *w , int n)
{
	int m;
	int i;
	int s1;
	int s2;
	m=2*n-1;
	
	for(i=0;i<n;i++) //初始化前n个元素为根结点 
	{
		ht[i].weight = w[i];
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	for(i=n;i<m;i++)//初始化后n-1个节点为空结点
	{
		ht[i].weight = 0;
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	for(i=n;i<m;i++)
	{
	select(ht,i,&s1,&s2);//S1和s2保存最小和次小权结点点的下标
	ht[i].weight = ht[s1].weight + ht[s2].weight;
	ht[i].lchild = s1;
	ht[i].rchild = s2;
	ht[s1].parent = i;
	ht[s2].parent = i;
	}
}
/**************************************************************
**Function Name：select
**Description  ：选取权值最小和次小的两个节点
**Parameters   ：ht：结构体数组存储哈夫曼树，n：叶子结点树
                 s1和s2：保存最小和次小结点的下标（优先把新
				 生成的节点放在左边）
**Return Value ：无
***************************************************************/
void select(HTNode *ht,int n,int *s1 ,int *s2)
{
	int i;
	int min1=-2;
	int min2=-2;
	int tem;
	for(i=0;i<n;i++)
	{
		if(ht[i].parent == -1)
		{
			if(min1 == -2)
			{
				min1 = ht[i].weight;
				*s1=i;
				continue;
			}
			if(min2 == -2)
			{
				min2 = ht[i].weight;
				*s2=i;
			}
			if(min1 != -2 && min2 != -2 )
			{
				if(ht[i].weight < min1)
				{
					min2 = min1;
					min1 = ht[i].weight;
					*s2=*s1;
					*s1=i;
				}
				else
				{
					if(ht[i].weight < min2)
					{
						min2 = ht[i].weight;
						*s2=i;
					}
				}
			}
		}
	}
	if(ht[*s1].lchild != -1 && ht[*s2].lchild != -1)
	{
		;
	}
	else if(ht[*s2].lchild != -1)
	{
			tem = *s1;
			*s1 = *s2;
			*s2 = tem;
	
	}

	
}
/**************************************************************
**Function Name：CrtHuffManCode
**Description  ：创建哈夫曼编码
**Parameters   ：ht：结构体数组存储哈夫曼树，hc：字符串指针数组保
				 存哈夫曼编码，n：叶子结点数
                 n：叶子结点数              
**Return Value ：无
***************************************************************/
void CrtHuffManCode(HTNode *ht,char **hc,int n)
{
	char *cd;
	int start;
	int c;
	int p;
	int i;
	cd = (char*)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=0;i<n;i++)
	{
		start = n-1;
		c=i;
		p=ht[i].parent;
		while(p!=-1)
		{
			--start;
			if(ht[p].lchild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=p;
			p=ht[p].parent;
		}
		hc[i]=(char*)malloc(n*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}

/**************************************************************
**Function Name：CountWeight
**Description  ：统计打开的文件中出现的字符和不同字符出现的次数
**Parameters   ：fname：保存文件位置的字符串，code：保存不同字符
				 及其出现次数，n：保存文件中出现了多少种字符              
**Return Value ：无
***************************************************************/
void CountWeight(char *fname,Data *code,int *n)
{
	int count = 0 ;
	FILE *infp;
	int i,j;
	char buff;
	Data tem;
	int file_count;
	infp=fopen(fname,"r");//打开文件
	for(i=0;i<N;i++)
	{
		code[i].count = 0;//初始化code数组
	}
	fseek(infp,0,2);
	file_count = ftell(infp);
	fseek(infp,0,0);
	//printf("%d",file_count);
	while(file_count != ftell(infp))
	{
		fread(&buff,1,1,infp);//从文件中读取一个字符
		//printf("now : %c\n", buff) ;
		code[buff].count++;  //统计字符出现的次数
		code[buff].ch = buff; //保存该字符
		count++ ;
	}
	//count--;
	//code[buff].count--;
	fclose(infp);//关闭文件

	for(i = 0;i<N;i++)//把字符出现的次数按从大到小排序
	{
		for(j=i+1;j<N;j++)
		{
			if(code[i].count<code[j].count)
			{
				tem = code[i];
				code[i] = code[j];
				code[j] = tem;
			
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(code[i].count == 0)
			break;
	}
	*n=i;
	printf("共有 %d 种 %d 个字符。\n", i,count) ;
	/*
	printf("共有%d种字符\n",*n);
	for(i=0;i<*n;i++)
	{
		printf("%c\t%d\t%d\n",code[i].ch,code[i].ch,code[i].count);
	}
	*/
}
/**************************************************************
**Function Name：CrtFileCode
**Description  ：把文件进行哈夫曼编码转换
**Parameters   ：fname：保存读入文件位置的字符串，oname：保存输出
				 文件位置的字符串，hc：哈夫曼编码数组，n：叶子结点
				 数，q：保存哈夫曼编码对应字符的数组             
**Return Value ：无
***************************************************************/
void CrtFileCode(char *fname,char *oname,char **hc,int n,char *q)
{
	FILE *infp,*outfp;
	char ch;
	int i=0;
	infp = fopen(fname,"r");
	outfp = fopen(oname,"w");
	int count;
	fseek(infp,0,2);
	count=ftell(infp);
	fseek(infp,0,0);
	while(count != ftell(infp) )
	{
		fread(&ch,1,1,infp);
		for(i=0;i<n;i++)
		{
			if(q[i] == ch)
			{
				fwrite(hc[i],strlen(hc[i])+1,1,outfp);
			}
		}


	}
	fclose(infp);
	fclose(outfp);
	
}

/**************************************************************
**Function Name：DeCodeHuffMan
**Description  ：进行哈夫曼解码
**Parameters   ：fname：保存读入文件位置的字符串，oname：保存输出
				 文件位置的字符串，hc：哈夫曼编码数组，n：叶子结点
				 数，q：保存哈夫曼编码对应字符的数组             
**Return Value ：无
***************************************************************/
void DeCodeHuffMan(char *fname,char *oname,char **hc,int n,char *q)
{
	//char *p;
	FILE *infp,*outfp;
	char buff;
	char s[N];
	int i,j=0;
	infp=fopen(fname,"r");
	outfp=fopen(oname,"w");
 
	while(!feof(infp))
	{	
	//	p=(char*)malloc(100*sizeof(char));
		fread(&buff,1,1,infp);
		s[j++]=buff;
		if(buff == EOF ) break;
		if(buff=='\0')
		{
			for(i=0;i<n;i++)
			{
				if(strcmp(s,hc[i])==0)
				{
					//printf("ok\n");
					fwrite(&q[i],1,1,outfp);
					j=0;
				}
			}
			
		}
	//	free(p);
			
		
	}
	fclose(infp);
	fclose(outfp);
}

int main()
{
	int choice;
	int n;
	int i;
	int *p;
	char *q;
	HTNode *ht;
	char **hc;
	char fname[N];
	char decode[N];
	char crtcode[N];
	Data code[N];
//	FILE *fp;




//	CrtFileCode("qq.txt","CodeFile.txt",hc,n,q); //解码
	printf("\t******************************************\n");
	printf("\t*           哈夫曼编码解码               *\n");
	printf("\t*1.无文件操作                            *\n");
	printf("\t*2.有文件操作                            *\n");
	printf("\t*                                        *\n");
	printf("\t*                                        *\n");
	printf("\t******************************************\n");
	printf("请输入选择:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("请输入字符数量n：");
		scanf("%d",&n);
		flushall();
		//申请空间
		p = (int*)malloc(n*sizeof(int));
		q = (char*)malloc(n*sizeof(char));
		ht = (HTNode*)malloc((2*n-1)*sizeof(HTNode));
		hc = (char **)malloc(n*sizeof(char*));
		for(i=0;i<n;i++)
		{
			printf("请输入第%d个字符",i+1);
			scanf("%c",&q[i]);
			flushall();
			printf("\n请输入第%d个字符的权值：",i+1);
			scanf("%d",&p[i]);
			flushall();
		}
	/*	for(i=0;i<n;i++)
		{
			printf("%c %d\n",q[i],p[i]);

		}
	*/	CrtHuffManTree(ht,p,n);				
		CrtHuffManCode(ht,hc,n);
		for(i=0;i<n;i++)
			printf("字符 %c 的编码:%s\n",q[i],hc[i]);                    //打印每个字符对应的编码   
														//对字符串进行编码并打印编码
	  //释放申请的空间
		free(p);
		free(q);
		free(ht);
		free(hc);
		printf("按任意键结束...\n");
		break;
	case 2:
		printf("输入要打开的文本文件的路径(不带后缀):\n");
		scanf("%s",fname);
		strcat(fname,".txt");
		CountWeight(fname,code,&n);
		p = (int*)malloc(n*sizeof(int));
		q = (char*)malloc(n*sizeof(char));
		ht = (HTNode*)malloc((2*n-1)*sizeof(HTNode));
		hc = (char **)malloc(n*sizeof(char*));
		for(i=0;i<n;i++)
		{
			p[i]=code[i].count;
			q[i]=code[i].ch;
		}
		CrtHuffManTree(ht,p,n);
		CrtHuffManCode(ht,hc,n);
	/*	for(i=0;i<n;i++)
		{
			printf("字符 %c 的编码: %d\n",q[i],p[i]);

		}*/
		for(i=0;i<n;i++)
			printf("字符 %c 的编码:%s\n",q[i],hc[i]);  //打印每个字符对应的编码   
	    printf("输入源文件编码后输出文件CodeFile的路径:");
		scanf("%s",crtcode);
		strcat(crtcode,"CodeFile.txt");
		CrtFileCode(fname,crtcode,hc,n,q); 
		printf("输出CodeFile文件完成\n输入CodeFile文件解码后DeCodeFile文件的路径:");
		flushall();
		scanf("%s",decode);
		strcat(decode,"DeCodeFile.txt");
		DeCodeHuffMan(crtcode,decode,hc,n,q);//解码	
		printf("输出DeCodeFile文件完成\n按任意键结束...\n");
		
		 //释放申请的空间
		free(p);
		free(q);
		free(ht);
		free(hc);
			break;
	default :
		printf("输入错误\n");
		break;
		}
		
/*	fp=fopen("CodeFile.txt","r");
	while(!feof(fp))
	{
		printf("%d ",fgetc(fp));
	}
	fclose(fp);*/


/*	printf("请输入字符数量n：");
	scanf("%d",&n);
	flushall();
	//申请空间
	p = (int*)malloc(n*sizeof(int));
	q = (char*)malloc(n*sizeof(char));
	ht = (HTNode*)malloc((2*n-1)*sizeof(HTNode));
	hc = (char **)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个字符",i+1);
		scanf("%c",&q[i]);
		flushall();
		printf("\n请输入第%d个字符的权值：",i+1);
		scanf("%d",&p[i]);
		flushall();
	}
	for(i=0;i<n;i++)
	{
		printf("%c %d\n",q[i],p[i]);

	}
	CrtHuffManTree(ht,p,n);
	
	
	CrtHuffManCode(ht,hc,n);
	for(i=0;i<n;i++)
		printf("%c:%s\n",q[i],hc[i]);                    //打印每个字符对应的编码   
                                                    //对字符串进行编码并打印编码
	for(i=0;i<2*n-1;i++)
	  printf("%d\t%d\t%d\t%d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);	
*/getch();


  return 0;
}