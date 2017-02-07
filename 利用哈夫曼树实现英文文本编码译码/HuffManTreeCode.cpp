 #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define N 256
#define M 2*N-1

typedef struct
{
	int weight;//Ȩֵ
	int parent;//˫�׽��
	int lchild;//����
	int rchild;//�Һ���
}HTNode;       //�����������

typedef struct
{
	int count;//�ַ����ֵĴ���
	char ch;//������ֵ��ַ�
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
**Function Name��CrtHuffManTree
**Description  ��������������
**Parameters   ��ht���ṹ������洢����������w��Ȩֵ����
                 n��Ҷ�ӽ����              
**Return Value ����
***************************************************************/
void CrtHuffManTree(HTNode *ht , int *w , int n)
{
	int m;
	int i;
	int s1;
	int s2;
	m=2*n-1;
	
	for(i=0;i<n;i++) //��ʼ��ǰn��Ԫ��Ϊ����� 
	{
		ht[i].weight = w[i];
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	for(i=n;i<m;i++)//��ʼ����n-1���ڵ�Ϊ�ս��
	{
		ht[i].weight = 0;
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	for(i=n;i<m;i++)
	{
	select(ht,i,&s1,&s2);//S1��s2������С�ʹ�СȨ������±�
	ht[i].weight = ht[s1].weight + ht[s2].weight;
	ht[i].lchild = s1;
	ht[i].rchild = s2;
	ht[s1].parent = i;
	ht[s2].parent = i;
	}
}
/**************************************************************
**Function Name��select
**Description  ��ѡȡȨֵ��С�ʹ�С�������ڵ�
**Parameters   ��ht���ṹ������洢����������n��Ҷ�ӽ����
                 s1��s2��������С�ʹ�С�����±꣨���Ȱ���
				 ���ɵĽڵ������ߣ�
**Return Value ����
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
**Function Name��CrtHuffManCode
**Description  ����������������
**Parameters   ��ht���ṹ������洢����������hc���ַ���ָ�����鱣
				 ����������룬n��Ҷ�ӽ����
                 n��Ҷ�ӽ����              
**Return Value ����
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
**Function Name��CountWeight
**Description  ��ͳ�ƴ򿪵��ļ��г��ֵ��ַ��Ͳ�ͬ�ַ����ֵĴ���
**Parameters   ��fname�������ļ�λ�õ��ַ�����code�����治ͬ�ַ�
				 ������ִ�����n�������ļ��г����˶������ַ�              
**Return Value ����
***************************************************************/
void CountWeight(char *fname,Data *code,int *n)
{
	int count = 0 ;
	FILE *infp;
	int i,j;
	char buff;
	Data tem;
	int file_count;
	infp=fopen(fname,"r");//���ļ�
	for(i=0;i<N;i++)
	{
		code[i].count = 0;//��ʼ��code����
	}
	fseek(infp,0,2);
	file_count = ftell(infp);
	fseek(infp,0,0);
	//printf("%d",file_count);
	while(file_count != ftell(infp))
	{
		fread(&buff,1,1,infp);//���ļ��ж�ȡһ���ַ�
		//printf("now : %c\n", buff) ;
		code[buff].count++;  //ͳ���ַ����ֵĴ���
		code[buff].ch = buff; //������ַ�
		count++ ;
	}
	//count--;
	//code[buff].count--;
	fclose(infp);//�ر��ļ�

	for(i = 0;i<N;i++)//���ַ����ֵĴ������Ӵ�С����
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
	printf("���� %d �� %d ���ַ���\n", i,count) ;
	/*
	printf("����%d���ַ�\n",*n);
	for(i=0;i<*n;i++)
	{
		printf("%c\t%d\t%d\n",code[i].ch,code[i].ch,code[i].count);
	}
	*/
}
/**************************************************************
**Function Name��CrtFileCode
**Description  �����ļ����й���������ת��
**Parameters   ��fname����������ļ�λ�õ��ַ�����oname���������
				 �ļ�λ�õ��ַ�����hc���������������飬n��Ҷ�ӽ��
				 ����q����������������Ӧ�ַ�������             
**Return Value ����
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
**Function Name��DeCodeHuffMan
**Description  �����й���������
**Parameters   ��fname����������ļ�λ�õ��ַ�����oname���������
				 �ļ�λ�õ��ַ�����hc���������������飬n��Ҷ�ӽ��
				 ����q����������������Ӧ�ַ�������             
**Return Value ����
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




//	CrtFileCode("qq.txt","CodeFile.txt",hc,n,q); //����
	printf("\t******************************************\n");
	printf("\t*           �������������               *\n");
	printf("\t*1.���ļ�����                            *\n");
	printf("\t*2.���ļ�����                            *\n");
	printf("\t*                                        *\n");
	printf("\t*                                        *\n");
	printf("\t******************************************\n");
	printf("������ѡ��:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("�������ַ�����n��");
		scanf("%d",&n);
		flushall();
		//����ռ�
		p = (int*)malloc(n*sizeof(int));
		q = (char*)malloc(n*sizeof(char));
		ht = (HTNode*)malloc((2*n-1)*sizeof(HTNode));
		hc = (char **)malloc(n*sizeof(char*));
		for(i=0;i<n;i++)
		{
			printf("�������%d���ַ�",i+1);
			scanf("%c",&q[i]);
			flushall();
			printf("\n�������%d���ַ���Ȩֵ��",i+1);
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
			printf("�ַ� %c �ı���:%s\n",q[i],hc[i]);                    //��ӡÿ���ַ���Ӧ�ı���   
														//���ַ������б��벢��ӡ����
	  //�ͷ�����Ŀռ�
		free(p);
		free(q);
		free(ht);
		free(hc);
		printf("�����������...\n");
		break;
	case 2:
		printf("����Ҫ�򿪵��ı��ļ���·��(������׺):\n");
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
			printf("�ַ� %c �ı���: %d\n",q[i],p[i]);

		}*/
		for(i=0;i<n;i++)
			printf("�ַ� %c �ı���:%s\n",q[i],hc[i]);  //��ӡÿ���ַ���Ӧ�ı���   
	    printf("����Դ�ļ����������ļ�CodeFile��·��:");
		scanf("%s",crtcode);
		strcat(crtcode,"CodeFile.txt");
		CrtFileCode(fname,crtcode,hc,n,q); 
		printf("���CodeFile�ļ����\n����CodeFile�ļ������DeCodeFile�ļ���·��:");
		flushall();
		scanf("%s",decode);
		strcat(decode,"DeCodeFile.txt");
		DeCodeHuffMan(crtcode,decode,hc,n,q);//����	
		printf("���DeCodeFile�ļ����\n�����������...\n");
		
		 //�ͷ�����Ŀռ�
		free(p);
		free(q);
		free(ht);
		free(hc);
			break;
	default :
		printf("�������\n");
		break;
		}
		
/*	fp=fopen("CodeFile.txt","r");
	while(!feof(fp))
	{
		printf("%d ",fgetc(fp));
	}
	fclose(fp);*/


/*	printf("�������ַ�����n��");
	scanf("%d",&n);
	flushall();
	//����ռ�
	p = (int*)malloc(n*sizeof(int));
	q = (char*)malloc(n*sizeof(char));
	ht = (HTNode*)malloc((2*n-1)*sizeof(HTNode));
	hc = (char **)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
	{
		printf("�������%d���ַ�",i+1);
		scanf("%c",&q[i]);
		flushall();
		printf("\n�������%d���ַ���Ȩֵ��",i+1);
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
		printf("%c:%s\n",q[i],hc[i]);                    //��ӡÿ���ַ���Ӧ�ı���   
                                                    //���ַ������б��벢��ӡ����
	for(i=0;i<2*n-1;i++)
	  printf("%d\t%d\t%d\t%d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);	
*/getch();


  return 0;
}