#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FULL 100
struct huffman {
	char n;
	int weight;
	struct huffman *next;
	struct huffman *LChlid,*RChlid,*Parent;
};
struct stack {							
	int cnt;
	struct huffman *top;
};	
struct huffman *create(){
	struct huffman *Head;
	struct huffman *New,*End;
	char string [FULL] = "";							//´æ´¢×Ö·û´® 
	char str [FULL] = "";							//´æ´¢²»Í¬×Ö·û 
	int w[FULL];								//´æ´¢È¨Öµ 
	int i,j;
	int n = 0;
	int sum = 0;
	for(i = 0;i<FULL;i++){
		w[i] = 0;
	}
	printf("Please Input expressions\n");
	gets(string);
	for(i = 0;i<strlen(string);i++){
		for(j = 0;j<i;j++){
			if(string[i] == str[j]){
				break;
			} 
		}
		if(i == j){
			str[n] = string[i];
			w[n]++;
			n++;
		}else{
			w[j]++;
		}
	}
	New = End = (struct huffman *)malloc(sizeof(struct huffman));
	New->n = str[sum];
	New->weight = w[sum];
	while(1){
		sum++;
		if(sum == 1){
			New->next = NULL;
			Head = New;
			End = New;   //
			New->LChlid = NULL;
			New->RChlid = NULL;
		}
		else{
			New->next = NULL;
			End->next = New;
			End = New;
			New->LChlid = NULL;
			New->RChlid = NULL;
		}
		if(sum == n){
			break;
		}
		New = (struct huffman *)malloc(sizeof(struct huffman));
		New->n = str[sum];
		New->weight = w[sum];
	}
	return Head;
}
print(struct huffman *p){
	while(p !=NULL){
		if(p->LChlid == NULL && p->RChlid == NULL){
			printf("%c\t",p->n);
		}else{
			printf("*\t");
		}
		printf("%d\n",p->weight);
		p = p->next;
	}
}
sort(struct huffman *New){
	int j;
	char k;
	struct huffman *End;
	if(New->next != NULL){
		while(New->next!=NULL){
			End = New->next;
			while(End!=NULL){
				if(New->weight>End->weight){
					j = New->weight;
					New->weight = End->weight;
					End->weight = j;
	
					k = New->n;
					New->n = End->n;
					End->n = k;
				}
				End = End->next;
			}
			New = New->next;
		}
	}
}
struct huffman *findLocal(struct huffman *LChlid,struct huffman *RChlid,int weight){
	char k[FULL];
	struct huffman *p,*q;
	struct huffman *t = (struct huffman *)malloc(sizeof(struct huffman));
	t->weight = weight;
	t->LChlid = LChlid;
	t->RChlid = RChlid;
	LChlid->Parent = RChlid->Parent = t; 
	p = RChlid;
	q = p->next;
	while(q != NULL){
		if(t->weight > q->weight && q->next == NULL){
			q->next = t;
			t->next = NULL;
			break;
		} else if(p->weight >= t->weight && p == RChlid) {
			RChlid->next = t;
			t->next = q;
			break;
		} else if(t->weight >= p->weight && t->weight <= q->weight){
			p->next = t;
			t->next = q;
			break;
		} else{
			p = q;
			q = q->next;
		}
	}
	if(q == NULL){
		p->next = t;
		t->next = NULL;
	}
	return RChlid->next;
}	
push(struct huffman *p,struct stack *stk){
	if (stk->cnt != FULL){
		p->next = stk->top;
		stk->top = p;
		stk->cnt++;
	}
}
struct huffman *pop(struct huffman *p,struct stack *stk){
	if(stk->cnt != FULL){
		p = stk->top;
		stk->top = stk->top->next;
		stk->cnt--;
		free(p);
	}	
	return stk->top;
}
initialize(struct stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}
main(){
	struct huffman *Head;
	struct huffman *p,*q;
	struct huffman *t,*s;
	struct stack temp;
	int a[FULL][FULL];							//´æ´¢±àÂë 
	int weight; 					
	int n = 0,k = 0;
	int i,j; 
	Head = p = create();
	q = p->next;
	if(q == NULL){
		print(p);
		return 0;
	}
	sort(p);
	weight = p->weight + q->weight;
	while(1){
		p = findLocal(p,q,weight);
		if(p->next != NULL){
			q = p->next;
			weight = p->weight + q->weight;
		} else{
			break;
		}
	}
	print(Head);
	initialize(&temp);
	s = p;
	while(p != NULL || temp.cnt != 0){
		while(1){
			push(p,&temp);
			if(p->LChlid == NULL){
				t = p;
				break;
			}
			a[n][k] = 0;
			k++;
			p = p->LChlid;
		}
		if(temp.cnt != 0){
			p = pop(p,&temp);
			if(temp.cnt == 0){
				break;
			}
			printf("%d\t",p->weight);
			if(t == p->RChlid){
				p = pop(p,&temp);
				if(p == NULL ){
					break;
				}
				k--;
			}
			p = p->RChlid;
			printf("%d\n",p->weight);
			if(p != NULL && p->LChlid == NULL){
				n++;
				printf("k = %d\t",k);
				printf("n = %d\n",n);
				for(i = 0;i < k;i++){
					a[n][i] = a[n-1][i];
				}
				a[n][k-1] = 1;
			}
		}
		for(i = 0;i < n;i++){
			for(j = 0;j < k;j++){
				printf("a[%d][%d] = %d\t",i,j,*(a[i]+j));
			}
			printf("\n");
		}
		printf("111111\n");
		printf("%d\n",temp.cnt);
	}
			
}
