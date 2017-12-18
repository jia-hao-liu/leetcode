#include<stdio.h>
#include<stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) ;

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",arr[i]);
    int* size=malloc(sizeof(int));
    int* p=dailyTemperatures(arr,N,size);
    for(int i=0;i<*size;i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}



int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result=malloc(sizeof(int)*temperaturesSize);
    *returnSize=temperaturesSize;
    int stack[temperaturesSize];
    int top=-1;
    int index;
    for(index=0;index<temperaturesSize;index++)
    {
        while(top>-1 && temperatures[index]>temperatures[stack[top]])
        {
            int distance=index-stack[top];
            result[stack[top--]]=distance;
        }
        stack[++top]=index;
    }
    while(top>-1)
        result[stack[top--]]=0;
    return result;

}
