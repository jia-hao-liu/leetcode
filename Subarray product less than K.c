#include<stdio.h>                 //leetcode 713  不知道为什么有两个案例不通过
#include<stdlib.h>
#include<math.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k);

int main(void)
{
    int N;
    scanf("%d",&N);


    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);

    printf("%d\n", numSubarrayProductLessThanK(arr,N,9));
    return 0;
}


int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int count=0,product=1;
    int j=0;
    for(int i=0;i<numsSize;i++)
    {

        for(;j<numsSize;j++)
        {
            product*=nums[j];
            if(product<k)
                count++;
            else
            {
                if(j==i)
                {
                    j++;
                    break;
                }
                count+=j-i-1;
                product/=(nums[i]*nums[j]);
                break;
            }

        }
        if(j==numsSize)
        {
            count+=(j-i-1)*(j-i)/2;
            break;
        }
    }
    return count;
}
