#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize);

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    int* p=malloc(sizeof(int));
    int* a=findDisappearedNumbers(arr,N,p);
    //printf("%d\n",*p);
    for(int i=0;i<*p;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
    }
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
            count++;
    }
    *returnSize=count;
    int* result=malloc(sizeof(int)*count);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
            result[--count]=i+1;
    }
    printf("%d\n",*returnSize);
    return result;
}
