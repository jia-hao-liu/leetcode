#include<stdio.h>
#include<stdlib.h>

void moveZeroes(int* nums, int numsSize) ;

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    moveZeroes(arr,N);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);
    return 0;
}

void moveZeroes(int* nums, int numsSize) {
    int i,j,count;
    int count_non0[numsSize];
    int temp=numsSize-1;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            count_non0[i]=temp--;
            continue;

        }

        count=0;

        for(j=0;j<i;j++)
        {
            if(nums[j]!=0)
                count++;
        }
        count_non0[i]=count;


    }

    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
            continue;
        nums[count_non0[i]]=nums[i];
        //printf("1111\n");
    }

    for(;temp+1<numsSize;temp++)
        nums[temp+1]=0;
}
