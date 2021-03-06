#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void initial(int location[8][8])
{
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            location[i][j]=-1;                                                             // 初始化location
        }
    }
}

int getexit(int x,int y,int location[8][8])                                                // 得到次數
{
    int num=0,i;
    int ktmove1[8]= {-2,-1,1,2,2,1,-1,-2};
    int ktmove2[8]= {1,2,2,1,-1,-2,-2,-1};
    for(i=0; i<8; i++)
    {
        if(x+ktmove1[i]>=0 && y+ktmove2[i]>=0 && x+ktmove1[i]<8 && y+ktmove2[i]<8 && location[x+ktmove1[i]][y+ktmove2[i]]==-1)
        {
            num++;
        }
    }
    return num;
}

void findnum(int num[8],int location[8][8],int x,int y)                                    // 紀錄次數
{
    int ktmove1[8]= {-2,-1,1,2,2,1,-1,-2};
    int ktmove2[8]= {1,2,2,1,-1,-2,-2,-1};
    int min,i,j;
    for(i=0; i<8; i++)
    {
            if(x+ktmove1[i]>=0 && y+ktmove2[i]>=0 && x+ktmove1[i]<8 && y+ktmove2[i]<8 && location[x+ktmove1[i]][y+ktmove2[i]]==-1)
            {
                num[i]=getexit(x+ktmove1[i],y+ktmove2[i],location);
            }
            else
            {
                num[i]=9;
            }
    }
}

int getmin(int x,int y,int location[8][8],int num[8])                                      // 得到最小出口數
{
    int min=8,i,j;
        for(i=0; i<8; i++)
        {
            if(min>num[i])
            {
                min=num[i];
            }
        }
        return min;
}

void output(int location[8][8])
{
    int i,j;
    printf("\n     Chess! Knight Patroling\n--------------------------------\n\n");        // 輸出
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(location[i][j]==-1)
            {
                printf("   ");
            }
            else
            {
                printf("%3d",location[i][j]);
            }
            printf("|");
        }
        printf("\n\n");
    }
    printf("--------------------------------\n");
}

void Move()
{
    int location[8][8],ktmove1[8]= {-2,-1,1,2,2,1,-1,-2},ktmove2[8]= {1,2,2,1,-1,-2,-2,-1},min,i,j,num[8],x,y,N=0;
    initial(location);                         // 初始化
    srand(time(NULL));                         // 亂數
    x=rand()%8,y=rand()%8,location[x][y]=N;
    location[x][y]=N;
    while(N<64)
    {
        findnum(num,location,x,y);             // 儲存出口數
        min=getmin(x,y,location,num);          // 找最小值
        if(min==0)
        {
            break;                             // 沒路走直接跳出到輸出
        }
        for(i=0; i<8; i++)
        {
            if(min==num[i])
            {
                x=x+ktmove1[i];                // 選擇第一個最少出口的
                y=y+ktmove2[i];
                break;
            }
        }
        N++;
        location[x][y]=N;                      // 走第幾步
    }
    output(location);                          // 輸出騎士走過的路，我是以一開始隨機亂數抓一個座標做為起點開始巡邏。
}
