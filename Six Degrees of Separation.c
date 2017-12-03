#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include"../package/Queuestruct.h"
#define MaxSize 10000




typedef int Vertex;
typedef struct adjvNode* PtrToadjvNode;
struct adjvNode{
    Vertex Vindex;
    PtrToadjvNode next;
};
typedef struct ENode* Edge;
struct ENode{
    Vertex V1,V2;
};
struct VNode{
    PtrToadjvNode FirstEdge;
};
typedef struct VNode AdjList[MaxSize];
typedef struct GraphNode* ListGraph;
struct GraphNode{
    int Nvertex;
    int Nedge;
    AdjList G;

};

void visit(Vertex V);
int BFS(ListGraph LG,Vertex V);
int IfEdge_double(ListGraph LG, Vertex V1, Vertex V2);
ListGraph BuildGraph(int Vertexnum);
void insertEdge_double(ListGraph LG,Edge E);

bool visited[MaxSize];

int main(void)
{
    //读入顶点数和边数
    int VertexNum,EdgeNum,Num;
    ListGraph LG;
    Edge E=malloc(sizeof(struct ENode));
    scanf("%d %d",&VertexNum,&EdgeNum);
    //创建图，读入边并连接
    LG=BuildGraph(VertexNum);
    for(int i=0;i<EdgeNum;i++)
    {
        scanf("%d %d",&E->V1,&E->V2);
        insertEdge_double(LG,E);
    }
    //遍历每个点，计算与其距离小于6的点个数，输出百分比
    for(int i=0;i<VertexNum;i++)
    {
        for(int i=0;i<MaxSize;i++)
            visited[i]=0;
        Num=BFS(LG,i);
        PtrToadjvNode temp=LG->G[i].FirstEdge;

        printf("%d: %.2f%%\n", i+1, Num/(double)VertexNum*100.0);
    }
    return 0;
}

void visit(Vertex V)
{
    return;
}

int IfEdge_double(ListGraph LG, Vertex V1,Vertex V2)
{
    PtrToadjvNode temp=LG->G[V1].FirstEdge;
    while(temp)
    {
        if(temp->Vindex==V2)
            return 1;
        temp=temp->next;
    }
    return 0;
}
void insertEdge_double(ListGraph LG, Edge E)
{
    PtrToadjvNode NewNode=malloc(sizeof(struct adjvNode));
    NewNode->Vindex=E->V2;
    NewNode->next=LG->G[E->V1].FirstEdge;
    LG->G[E->V1].FirstEdge=NewNode;
    PtrToadjvNode NewNode2 =malloc(sizeof(struct adjvNode));
    NewNode2->Vindex=E->V1;
    NewNode2->next=LG->G[E->V2].FirstEdge;
    LG->G[E->V2].FirstEdge=NewNode2;

}

ListGraph BuildGraph(int Vertexnum)
{
    ListGraph LG=malloc(sizeof(struct GraphNode));
    LG->Nvertex=Vertexnum;
    LG->Nedge=0;
    for(int i=0;i<Vertexnum;i++)
        LG->G[i].FirstEdge=NULL;

    return LG;
}


int BFS(ListGraph LG, Vertex V)
{
    int level=0,count=1,last=V,tail;
    Queue Q=CreateQueue(LG->Nvertex);
    PtrToadjvNode W;
    Enqueue(Q,V);
    visit(V);
    visited[V]=true;
    while(!IsEmpty(Q))
    {
        V=Dequeue(Q);
        for(W=LG->G[V].FirstEdge;W;W=W->next)
        {
            if(!visited[W->Vindex])
            {
                Enqueue(Q,W->Vindex);
                visit(W->Vindex);
                visited[W->Vindex]=true;
                count++;
                tail=W->Vindex;
            }
        }
        if(V==last)
        {
            level++;
            last=tail;
        }
        if(level==6)
            break;
    }
    return count;
}
