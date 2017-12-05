#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MaxSize 1000

void insertionsort(int arr[], int N);
int LengthOfLeft(int N);
void BuildTree(int arr[],int L,int R,int TRoot);

int Tree[MaxSize];

int main(void)
{
    //读入数据存入数组
    int N;
    scanf("%d", &N);
    int input[N];
    for(int i=0;i<N;i++)
        scanf("%d",&input[i]);
    //将数据排序
    insertionsort(input,N);
    //按完全二叉搜索树的顺序存入数组
    BuildTree(input,0, N-1,0);
    //输出
    printf("%d",Tree[0]);
    for(int i=1;i<N;i++)
        printf(" %d", Tree[i]);
    return 0;
}

void insertionsort(int arr[], int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
        for(j=i;j>0 && arr[j-1]>temp;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;

    }
}

int LengthOfLeft(int N)
{
    //if(N==1)
      //  return 0;
    int Hight=log(N)/log(2);
    int temp=(int)pow(2.0,Hight);
    int surplus=N-temp+1;
    if(surplus>temp/2)
        surplus=temp/2;
    return surplus+(temp-2)/2;
}

void BuildTree(int arr[],int L,int R,int TRoot)
{
    int Tnum=R-L+1;
    if(Tnum==0)
        return;
    int index=LengthOfLeft(Tnum);
    Tree[TRoot]=arr[L+index];
    BuildTree(arr,L,L+index-1,2*TRoot+1);
    BuildTree(arr,L+index+1,R,2*TRoot+2);
}
