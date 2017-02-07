//
//  main.c
//  snack
//
//  Created by mac on 15/10/17.
//  Copyright (c) 2015年 mac. All rights reserved.
//
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ESC 27

#define SNACK_COLOR 15
#define FOOD_COLOR 10
#define BG_COLOR 0
#define WALL_COLOR 55
#define TEXT_COLOR 10

#define TRUE 1
#define FALSE 0

#define FINAL_SNACK_SPEED 100 //…ﬂµƒ◊Ó¥ÛÀŸ∂»

struct snack
{
    int x, y; //…ﬂµƒ◊¯±Í
    struct snack * next;
};

int score = 0;
int food_position[2];// ≥ŒÔŒª÷√
int max_score = 0;

void gotoxy(int x, int y)    //…Ë÷√ ‰≥ˆ◊¯±Í £¨“‘◊÷Ω⁄Œ™µ•Œª
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_color(int b)         //…Ë÷√—’…´∫Ø ˝
{
    HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ;
    SetConsoleTextAttribute(hConsole,b) ;
}

//¥À∫Ø ˝œ‘ æ«Ω±⁄
void show_wall()
{
    //…µ±∆µƒª≠«Ω∑Ω∑®£®¥ø¥‚ «æıµ√—≠ª∑Ã´¬È∑≥£¨’‚∏ˆ÷ª“™∏¥÷∆æÕ∫√£©
    int a[20][30] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };
    set_color(WALL_COLOR);
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j< 30; j++)
        {
            if (a[i][j] == 1)
            {
                set_color(WALL_COLOR);
                printf("°ˆ");
            }
            else
            {
                set_color(BG_COLOR);
                printf("  ");
            }
        }
        printf("\n");
    }
    set_color(TEXT_COLOR);
    gotoxy(62, 3);
    printf("Made By: √Œ÷–À≠»Àhappy");
    gotoxy(62, 5);
    printf("«ÎΩ´ ‰»Î∑®«–ªªµΩ”¢Œƒ◊¥Ã¨‘Ÿ“∆∂Ø");
    set_color(TEXT_COLOR);
    gotoxy(62, 7);
    printf(" π”√'w','a','s','d'¿¥“∆∂Ø");
    gotoxy(62, 9);
    printf("∞¥œ¬ESCº¸ÕÀ≥ˆ");
    gotoxy(62, 11);
    printf("µ±«∞∑÷ ˝£∫  %d", score);
    gotoxy(62, 13);
    printf("◊Ó∏ﬂ∑÷ ˝£∫  %d", max_score);
    
}

//≤˙…˙ ≥ŒÔ
void make_food(struct snack * mySnack)
{
    srand(clock());
    int x = rand()%52+1; //“ÚŒ™Œ“’‚¿Ôµƒ◊Ó”“±ﬂµƒ«Ωµƒ x ◊¯±ÍŒ™ 58
    int y = rand()%17+1; //            ◊Óœ¬±ﬂµƒ«Ωµƒ y ◊¯±ÍŒ™ 19
    food_position[0] = x % 2?x+1:x;//»∑±£x∑ΩœÚ…œµƒ «≈º ˝
    food_position[1] = y;
    struct snack * p = mySnack;
    while(p != NULL)
    {
        if (food_position[0] == p->x || food_position[1] == y)//»Áπ˚∫Õ…ﬂ”–÷ÿ∫œ‘Ú÷ÿ–¬…˙≥… ≥ŒÔ
        {
            x = rand()%57+1;
            y = rand()%17+1;
            food_position[0] = x % 2?x+1:x;//»∑±£x∑ΩœÚ…œµƒ «≈º ˝
            food_position[1] = y;
            struct snack * p = mySnack;
            p = mySnack;
        }
        p = p->next;
    }
    set_color(FOOD_COLOR);
    gotoxy(food_position[0], food_position[1]);
    printf("°Ò");
}

//≈–∂œ «∑Ò≥‘µΩ ≥ŒÔ£¨»Áπ˚≥‘µΩ∑µªÿTRUE
int isEat(struct snack * mySnack)
{
    int flag = FALSE;
    if (mySnack->x == food_position[0] && food_position[1] == mySnack->y)
    {
        flag = TRUE;
    }
    return flag;
}

//¥À∫Ø ˝≥ı ºªØΩÁ√Ê
void init(struct snack * mySnack)
{
    show_wall();
    make_food(mySnack);
    draw_Snack(mySnack);
}

//≈–∂œ…ﬂ «∑Ò◊≤«Ω
int hitWall(struct snack * mySnack)
{
    int flag = FALSE;
    if (mySnack->y<1 || mySnack->y>19 || mySnack->x<2 || mySnack->x>58)
        flag = TRUE;
    return flag;
}

//≈–∂œ…ﬂ «∑Ò◊≤µΩ◊‘º∫
int hitSelf(struct snack * mySnack)
{
    int flag = FALSE;
    struct snack * p = mySnack->next;
    while(p != NULL)
    {
        if (p->x == mySnack->x && p->y == mySnack->y)
            flag = TRUE;
        p = p->next;
    }
    return flag;
}

//ª≠≥ˆ…ﬂ
void draw_Snack(struct snack * mySnack)
{
    set_color(SNACK_COLOR);
    struct snack * p = mySnack;
    gotoxy(p->x, p->y);
    printf("°ˆ");
    p = p->next;
    if (p != NULL)
    {
        while (p != NULL)
        {
            gotoxy(p->x, p->y);
            printf("°Ò");
            p = p->next;
        }
        
    }
}

int main(void)
{
    system("mode con cols=100 lines=25");//…Ë÷√øÿ÷∆Ã®¥∞ø⁄¥Û–°
    int direct = UP;
    int key = 0;
    int delay_time = 500;
    int choice;
    struct snack * mySnack = (struct snack *)malloc(sizeof(struct snack));
    mySnack->x = 30;
    mySnack->y = 10;
    mySnack->next = NULL;
    
    struct snack * p;
    struct snack * tail; //”√”⁄±£¥Ê◊Ó∫Û“ª∏ˆΩ⁄µ„
    struct snack * perTail; //”√”⁄±£¥Ê◊Ó∫Û“ª∏ˆΩ⁄µ„µƒ«∞«˝Ω⁄µ„
    
    FILE * fp = fopen("record.txt", "a+");  //¥Úø™◊Ó∏ﬂºÕ¬ºŒƒº˛
    if (fp == NULL)
    {
        printf("¥Úø™¿˙ ∑º«¬ºŒƒº˛ ß∞‹£°");
        exit(-1);
    }
    char sc[8];
    
    if (fgets(sc, 8, fp) != NULL)
        max_score = atoi(sc);
    
    init(mySnack);
    while (1)
    {
        if (kbhit())
        {
            key = getch();
            switch (key)
            {
                case 'w':
                case 'W':
                    if (direct != DOWN)
                    {
                        direct = UP;
                    }
                    break;
                case 's':
                case 'S':
                    if (direct != UP)
                    {
                        direct = DOWN;
                    }
                    break;
                case 'a':
                case 'A':
                    if (direct != RIGHT)
                    {
                        direct = LEFT;
                    }
                    break;
                case 'd':
                case 'D':
                    if (direct != LEFT)
                    {
                        direct = RIGHT;
                    }
                    break;
                case ESC:
                    choice = MessageBox(NULL,TEXT("ƒ˙“™ÕÀ≥ˆ¬£ø"),TEXT("æØ∏Ê"),MB_ICONINFORMATION|MB_YESNO);
                    switch (choice){
                        case IDYES:
                            if (score > max_score)
                            {
                                fclose(fp);
                                fp = fopen("record.txt", "w");
                                if(fp == NULL)
                                {
                                    printf("¥Úø™º«¬ºŒƒº˛ ß∞‹£°");
                                    exit(-1);
                                }
                                fprintf(fp, "%d", score);
                                fclose(fp);
                            }
                            exit(0);
                            break;
                        case IDNO:
                            break;
                    }
            }
        }
        
        p = (struct snack *)malloc(sizeof(struct snack));  //…˙≥…“ª∏ˆ–¬µƒΩ⁄µ„”√¿¥◊˜Œ™…ﬂ–¬µƒÕ∑≤ø
        
        if (direct == UP)
        {
            p->y = (mySnack->y)-1;
            p->x = mySnack->x;
        }
        else if(direct == DOWN)
        {
            p->y = mySnack->y+1;
            p->x = mySnack->x;
        }
        else if(direct == LEFT)
        {
            p->x = mySnack->x-2;
            p->y = mySnack->y;
        }
        else
        {
            p->x = mySnack->x +2;
            p->y = mySnack->y;
        }
        p->next = mySnack;
        mySnack = p;
        
        if (isEat(mySnack)) //»Áπ˚≥‘µΩ¡À ≥ŒÔæÕ÷ÿ–¬…˙≥…–¬µƒ ≥ŒÔ≤¢«“≤ª»•µÙ…ﬂŒ≤Ω⁄µ„
        {
            score++;
            if (delay_time > FINAL_SNACK_SPEED)
                delay_time -= 50;
            set_color(TEXT_COLOR);
            gotoxy(62, 9);
            printf("µ±«∞∑÷ ˝£∫  %d", score);
            make_food(mySnack); //≥‘µΩ ≥ŒÔ÷Æ∫Û“™…˙≥…–¬µƒ ≥ŒÔ
        }
        else  //»Áπ˚√ª≥‘µΩ ≥ŒÔæÕ∞—¡¥±Ì÷–µƒŒ≤Ω·µ„»•µÙ£¨≤¢«“‘≠¿¥ª≠Œ≤Ω·µ„µƒŒª÷√”√±≥æ∞…´ÃÓ≥‰
        {
            tail = mySnack;
            perTail = NULL;
            while (tail->next != NULL)
            {
                perTail = tail;
                tail = tail->next;
            }
            set_color(BG_COLOR);
            gotoxy(tail->x, tail->y);
            printf("°ˆ");
            free(tail);
            perTail->next = NULL; //Ω´Œ≤Ω·µ„µƒ÷∏’Î”Ú÷∏œÚNULL
        }
        
        if (hitWall(mySnack) || hitSelf(mySnack))
        {
            //”Œœ∑Ω· ¯
            if (score > max_score)
            {
                fclose(fp);
                fp = fopen("record.txt", "w");
                if(fp == NULL)
                {
                    printf("¥Úø™º«¬ºŒƒº˛ ß∞‹£°");
                    exit(-1);
                }
                fprintf(fp, "%d", score);
                fclose(fp);
            }
            MessageBox(NULL,TEXT("oo ƒ˙π“¡À£¨«Î÷ÿ¿¥∞…£°"),TEXT("≤ª∫√“‚Àº"),MB_OK);
            exit(0);
        }
        draw_Snack(mySnack);
        Sleep(delay_time);
    }
    
    return 0;
}
