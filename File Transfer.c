#include<stdio.h>
#include<stdlib.h>

typedef int SetType;
typedef int DisjSet[100];

void Initialize(DisjSet S);
void SetUnion(DisjSet S,SetType X1, SetType X2);
SetType find(DisjSet S, int X);
SetType check(DisjSet S,int X1, int X2);

int main(void)
{
    DisjSet S;
    Initialize(S);

    SetUnion(S,5,70);
    SetUnion(S,70,8);
    printf("%d\n", check(S, 5, 8));

    return 0;
}

void Initialize(DisjSet S)
{
    for(int i=0;i<100;i++)
        S[i]=-1;
}

SetType find(DisjSet S,int X)
{
    if(S[X]<0)
        return X;
    else
        return S[X]=find(S,S[X]);
}

SetType check(DisjSet S,SetType X1, SetType X2)
{
    if (find(S,X1)==find(S,X2))
        return 1;
    else
        return 0;
}

void SetUnion(DisjSet S, SetType X1, SetType X2)
{
    int root1,root2;
    if((root1=find(S,X1))==(root2=find(S,X2)))
        return;
    else
    {
        if(S[root1]>S[root2])
        {
            S[root1]=root2;
            S[root2]--;
        }
        else
        {

            S[root2]=root1;
            S[root1]--;
        }

    }
}
