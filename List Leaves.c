#include<stdio.h>
#define Null -1

struct TreeNode{
    int num;
    int left;
    int right;
};
typedef struct TreeNode* Tree;

int BuildTree(Tree T,int N);
void Traversal(Tree T,int root);

int main(void)
{
    int N,root;
    puts("Please input the number of your data:");
    scanf("%d",&N);
    struct TreeNode ArrayToTree[N];
    root=BuildTree(ArrayToTree,N);
    Traversal(ArrayToTree,root);
    return 0;
}

int BuildTree(Tree T,int N)
{
    int i;
    int temp[N];
    for(i=0;i<N;i++)
        temp[i]=0;
    if(N)
    {
        for( i=0;i<N;i++)
        {
            scanf("%d %d %d", &T[i].num, &T[i].left, &T[i].right);
            if(T[i].left!=-1)
                temp[T[i].left]=1;
            if(T[i].right!=-1)
                temp[T[i].right]=1;
        }
    }
    else
        return Null;
    for( i=0;i<N;i++)
        if(temp[i]==0)
            break;
    return i;
}

void Traversal(Tree T, int root)
{
    if(root!=-1)
    {
        if(T[root].left==-1 && T[root].right==-1)
            printf("%d %d\n",root, T[root].num);
        Traversal(T,T[root].left);
        Traversal(T,T[root].right);
    }
}
