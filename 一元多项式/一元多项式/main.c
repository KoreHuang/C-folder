//
//  main.c
//  一元多项式
//
//  Created by mac on 15/11/1.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include<stdio.h>
//#include<malloc.h>
#include<stdlib.h>
#define TURE 1
#define FLASE 0
typedef struct polynomail
{
    int coef;                  //œµ ˝
    int expn;                  //÷∏ ˝
    struct polynomail *next;   //÷∏œÚœ¬“ªΩ·µ„µƒ÷∏’Î
}polyn;
polyn * createpoly()             //Ω®¡¢∂‡œÓ Ω
{
    polyn *head,*rear,*s;
    int c,e;
    head=(polyn *)malloc(sizeof(polyn)); //Ω®¡¢∂‡œÓ ΩÕ∑Ω·µ„
    rear=head;                                     //rear º÷’÷∏œÚµ•¡¥±ÌµƒŒ≤£¨±„”⁄Œ≤≤Â∑®Ω®±Ì
    scanf("%d,%d",&c,&e);
    while(c!=0)                                    //»Ùc=0£¨‘Ú¥˙±Ì∂‡œÓ Ω ‰»ÎΩ· ¯
    {
        s=(polyn *)malloc(sizeof(polyn));//…Í«Î–¬µƒΩ·µ„
        s->coef=c;
        s->expn=e;
        rear->next=s;                              //‘⁄µ±«∞±ÌŒ≤≤Â»Î
        rear=s;
        scanf("%d,%d",&c,&e);
    }
    rear->next=NULL;
    return(head);
}
/*No type */void printpolyn(polyn *p)              // ‰≥ˆ∂‡œÓ Ω
{
    polyn *q;
    int flag=1;
    q=p->next;
    if(!q)                            //≈–∂œq «∑Ò «ø’÷∏’Î,œ‡µ±”⁄q==0
    {
        putchar('0');
        printf("\n");
    }
    while(q)                          //µ±q≤ª «ø’÷∏’Î ±Ω¯»Î—≠ª∑
    {
        if(q->coef>0&&flag!=1)
            putchar('+');
        if(q->coef!=1&&q->coef!=-1)
        {
            printf("%d",q->coef);
            if(q->expn==1)
                putchar('X');
            else if(q->expn)
                printf("X^%d",q->expn);
            
        }
        else
        {
            if(q->coef==1)
            {
                if(!q->expn)             //÷∏ ˝Œ™0£¨œ‡µ±”⁄q->expn==0
                    putchar('1');
                else if(q->expn==1)
                    putchar('X');
                else
                    printf("X^%d",q->expn);
            }
            if(q->coef==-1)
            {
                if(!q->expn)
                    printf("-1");
                else if(q->expn==1)
                    printf("-X");
                else
                    printf("-X^%d",q->expn);
            }
        }
        q=q->next;
        flag++;
    }
    printf("\n");
}
polyn /*zhi zhen lei xing de han shu */* addpolyn(polyn *pa,polyn *pb)             //¡Ω∏ˆ∂‡œÓ Ωœ‡º”
{
    polyn *qa,*qb,*pc,*qc = NULL;
    polyn *headc;
    qa=pa->next;
    qb=pb->next;
    headc=(polyn *)malloc(sizeof(polyn));     //µ•¡¥±Ìpc”√¿¥¥Ê∑≈pa+pbµƒ∫Õ
    pc=headc;
    pc->next=NULL;
    while(qa!=NULL&&qb!=NULL)                        //µ±¡Ω∏ˆ∂‡œÓ Ωæ˘Œ¥…®√ËΩ· ¯ ±
    {
        qc=(polyn *)malloc(sizeof(polyn));
        if(qa->expn<qb->expn)                        //∂‡œÓ Ωaµƒ÷∏ ˝–°”⁄∂‡œÓ Ωbµƒ÷∏ ˝
        {
            qc->coef=qa->coef;
            qc->expn=qa->expn;
            qa=qa->next;
        }
        else if(qa->expn==qb->expn)                  //∂‡œÓ Ωaµƒ÷∏ ˝µ»”⁄∂‡œÓ Ωbµƒ÷∏ ˝
        {
            qc->coef=qa->coef+qb->coef;
            qc->expn=qa->expn;
            qa=qa->next;
            qb=qb->next;
        }
        else                                          //∂‡œÓ Ωaµƒ÷∏ ˝¥Û”⁄∂‡œÓ Ωbµƒ÷∏ ˝
        {
            qc->coef=qb->coef;
            qc->expn=qb->expn;
            qb=qb->next;
        }
        if(qc->coef!=0)
        {
            qc->next=pc->next;
            pc->next=qc;
            pc=qc;
        }
        else
            free(qc);
    }
    while(qa!=NULL)                                     //pa÷–»Áπ˚”– £”‡œÓ£¨Ω´ £”‡œÓ≤Â»ÎµΩpcµ±÷–
    {
        qc=(polyn *)malloc(sizeof(polyn));
        qc->coef=qa->coef;
        qc->expn=qa->expn;
        qa=qa->next;
        qc->next=pc->next;
        pc->next=qc;
        pc=qc;
    }
    while(qb!=NULL)                                     //pb÷–»Áπ˚”– £”‡œÓ£¨Ω´ £”‡œÓ≤Â»ÎµΩpcµ±÷–
    {
        qc->coef=qb->coef;
        qc->expn=qb->expn;
        qb=qb->next;
        qc->next=pc->next;
        pc->next=qc;
        pc=qc;
    }
    return headc;
}
polyn/*zhi zhen lei xing de han shu*/ * subtractpolyn(polyn *pa,polyn *pb)       //¡Ω∏ˆ∂‡œÓ Ωœ‡ºı
{
    polyn *h,*p;
    polyn *pd;
    p=pb->next;
    while(p)                                 //µ±p≤ª «ø’÷∏’ÎΩ¯»Î—≠ª∑
    {
        p->coef*=-1;                          //Ω´pbÀ˘”–∂‡œÓ Ωµƒœµ ˝±‰Œ™∆‰œ‡∑¥ ˝
        p=p->next;
    }
    h=pb;
    pd=addpolyn(pa,h);                       //Ω´pa”Î-pbœ‡º”£¨œ‡µ±”⁄pa-pb
    for(p=h->next;p;p=p->next)
        p->coef*=-1;
    return pd;
}
int main(void
         )
{
    polyn *pa,*pb,*pc,*pd;
    printf("«Î ‰»Î∂‡œÓ Ω1µƒ÷∏ ˝∫Õœµ ˝£®÷∏ ˝Œ™0, ‰»ÎΩ· ¯£©£∫\n");
    pa=createpoly();
    printpolyn(pa);
    printf("«Î ‰»Î∂‡œÓ Ω2µƒ÷∏ ˝∫Õœµ ˝£®÷∏ ˝Œ™0, ‰»ÎΩ· ¯£©£∫\n");
    pb=createpoly();
    printpolyn(pb);
    addpolyn(pa,pb);
    printpolyn(pc);
    subtractpolyn(pa,pb);
    printpolyn(pd);
}