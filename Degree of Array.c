#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return (*(int*)a)-(*(int*)b);
}
struct Node{
    int num;
    int fre;
};

int findShortestSubArray(int* nums, int numsSize) {
    int arr[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        arr[i]=nums[i];
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    struct Node record[numsSize];
    record[0].num=nums[0];
    record[0].fre=1;
    int i=0,j,index=1,count=0,numrecord=0;
    while(index<numsSize)
    {

        for( j=0;j<=i;j++)
        {
            if(nums[index]==record[j].num)
            {
                record[j].fre++;
                break;
            }
        }
        if(j>i)
        {
            record[++i].num=nums[index];
            record[i].fre=1;
        }
        index++;
    }
    for(;i>=0;i--)
    {
        if(record[i].fre>count)
        {
            count=record[i].fre;
            numrecord=record[i].num;
        }
    }
    for(i=0;i<numsSize;i++)
    {
        if(arr[i]==numrecord)
            break;
    }
    for(j=0;j<numsSize;j++)
    {
        if(arr[j]==numrecord)
            count=j;
    }
    return count-i+1;
}

int main(void)
{
    int N;
    puts("Please input the number of your data");
    scanf("%d", &N);
    int arr[N];
    puts("Please input your data:");
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",findShortestSubArray(arr, N));
    return 0;

}
