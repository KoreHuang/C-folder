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
    char string [FULL] = "";							//¥Ê¥¢◊÷∑˚¥Æ
    char str [FULL] = "";							//¥Ê¥¢≤ªÕ¨◊÷∑˚
    int w[FULL];								//¥Ê¥¢»®÷µ
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
            End = New;
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
void print(struct huffman *p){
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
void sort(struct huffman *New){
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
    //char k[FULL];
    struct huffman *p,*q;
    struct huffman *t = (struct huffman *)malloc(sizeof(struct huffman));
    t->weight = weight;
    t->LChlid = LChlid;
    t->RChlid = RChlid;
    LChlid->Parent = RChlid->Parent = t;
    t->Parent = NULL;
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
void push(struct huffman *p,struct stack *stk){
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
void huffmanCode(struct huffman *p,int n){
    struct huffman *q,*s;
    char *cd = (char*)malloc(n * sizeof(char));
    int i,start = n-1;
    cd[n-1] = 0;
    s = q = p;
    p = p->Parent;
    while(p != NULL){
        start--;
        if(q == p->LChlid){
            cd[start] = '0';
        } else{
            cd[start] = '1';
        }
        q = p;
        p = p->Parent;
    }
    printf("%c\t",s->n);
    printf("%d\t",s->weight);
    for(i = 0;i < n-1;i++){
        printf("%c",cd[i]);
    }
    printf("\n");
}
void initialize(struct stack *stk){
    stk->cnt = 0;
    stk->top = NULL;
}
int main(void){
    struct huffman *Head;
    struct huffman *p,*q;
    struct huffman *t,*s;
    struct stack temp;
    char a[FULL][FULL];							//¥Ê¥¢±‡¬Î 
    int weight; 					
    int n = 0,k = 0;
    int i = 0,j; 
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
    s = p = Head;
    printf("◊÷∑˚\t»®÷µ\t±‡¬Î\n");
    while(p != NULL){
        if(p->LChlid == NULL && p->RChlid == NULL){
            while(s != NULL){
                s = s->Parent;
                i++;
            }
            huffmanCode(p,i);
            i = 0;
        }
        p = p->next;
        s = p;
    }
    return 0;
}
