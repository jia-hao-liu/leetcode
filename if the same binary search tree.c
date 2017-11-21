#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode{
  int element;
  Tree left;
  Tree right;
  int flag;

};

Tree NewNode(int num);
Tree insert(Tree T, int num);
Tree BuildTree(int N);
int check(Tree T, int num);
int Judge(Tree T, int N);
void Reset(Tree T);

int main(void)
{
  //读入N和L
  int N,L;
  scanf("%d", &N);


  //根据N建一个二叉查找树
  while(N)
  {
    scanf("%d",&L);
    Tree T;
    T=BuildTree(N);
    //判断L与该二叉查找树是否同一颗，进行下一次判断
    while(L--)
    {
      if(Judge(T,N))
        puts("Yes");
      else
        puts("No");
    }
    scanf("%d", &N);
    //Traversal(T);
  }

  return 0;
}

Tree BuildTree(int N)
{
  int num;
  Tree T;

  scanf("%d",&num);
  T=NewNode(num);
  for(int i=1;i<N;i++)
  {
    scanf("%d",&num);
    T=insert(T,num);
  }
  return T;
}

Tree NewNode(int num)
{
  Tree T=(Tree)malloc(sizeof(struct TreeNode));
  T->element=num;
  T->left=NULL;
  T->right=NULL;
  T->flag=0;
}

Tree insert(Tree T,int num)
{
  if(!T)
    return NewNode(num);
  else
  {
    if(num>T->element)
      T->right=insert(T->right,num);
    else
      T->left=insert(T->left,num);
  }
}

int check(Tree T,int num)
{
  if(T->flag)
  {
    if(num>T->element)
      return check(T->right,num);
    else
      return check(T->left,num);
  }
  else
  {
    if(num==T->element)
    {
      T->flag=1;
      return 1;
    }
    else
      return 0;
  }

}

void Reset(Tree T)
{
    T->flag=0;
    if(T->left)
        Reset(T->left);
    if(T->right)
        Reset(T->right);
}

int Judge(Tree T,int N)
{
  int i,num,flag=1;
  for(i=0;i<N;i++)
  {
    scanf("%d",&num);
    if(flag)
      if(!check(T,num))
        flag=0;
  }
  Reset(T);
  return flag;
}
