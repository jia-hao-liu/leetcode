#include<stdio.h>      //一人在正方形中心，有许多点可以跳，问是否可以跳到岸上
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define MaxSize 101

struct Node{
    int i;
    int x;
    int y;
};

int power(int a,int b);
int IfEdge(struct Node* L,int L1,int L2,int range);
int visit(struct Node* L,int L1,int range);
void DFS(struct Node* L,int Lsize, int L1,int range);

int flag=0;
bool visited[MaxSize]={0};


int main(void)
{
    int N1,jumpdistance;
    scanf("%d %d",&N1,&jumpdistance);
    struct Node location[N1];
    location[0].x=location[0].y=0;
    for(int i=1;i<=N1;i++)
    {
        location[i].i=i;
        scanf("%d %d", &location[i].x, &location[i].y);
    }
    for(int i=1;i<=N1;i++)
    {
        if(flag)
            break;
        if(IfEdge(location,0,i,jumpdistance)){
        if(!visited[i])
            DFS(location,N1,i,jumpdistance);
        }
    }
    if(!flag)
        printf("No\n");
    return 0;
}

int power(int a,int b)
{
    int temp=1;
    for(int i=1;i<=b;i++)
    {
        temp*=a;

    }
    return temp;
}

int IfEdge(struct Node* L, int L1, int L2, int range)
{
    if(power(L[L1].x-L[L2].x,2)+power(L[L1].y-L[L2].y,2)<range*range)
        return 1;
    else
        return 0;
}

int visit(struct Node* L,int L1, int range)
{
    if(L[L1].x<range-50 || L[L1].x>50-range || L[L1].y<range-50 || L[L1].y>50-range)
        return 1;
    else
        return 0;
}

void DFS(struct Node* L,int Lsize,int L1,int range)
{
    if(flag)
        return;
    if(visit(L,L1,range))
    {
        printf("Yes\n");
        flag=1;
        return;
    }
    visited[L1]=true;
    for(int i=1;i<=Lsize;i++)
    {
        if(!visited[i] && IfEdge(L,L1,i,range))
            DFS(L,Lsize,i,range);
    }
}
