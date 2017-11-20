#include<stdio.h>
int* a(void);
void insertsort(int arr[], int N);
int arrayPairSum(int * nums, int numsSize);
int main(void)
{
        int arr[8];
        for(int i=0;i<8;i++)
            scanf("%d", &arr[i]);
        int sum=arrayPairSum(arr,8);
        printf("%d\n", sum);
        return 0;
}
int arrayPairSum(int* nums, int numsSize) {
    insertsort(nums,numsSize);
    int sum=0;
    for(int i=0;2*i<numsSize;i++)
        sum+=nums[2*i];
    return sum;
}
void insertsort(int arr[], int N)
{
    int i,j,k,temp;
    for(i=1;i<N;i++)
    {
        k=i;
        temp=arr[i];
        for(j=i-1;j>=0 && temp<arr[j];j--)
        {
            arr[k--]=arr[j];

        }
        arr[k]=temp;
    }
}
