#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void QuickSort(int arr[],int N);
void Qsort(int left, int right, int arr[]);
bool containsDuplicate(int* nums, int numsSize);

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",containsDuplicate(arr,N));
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize<=1)
        return false;
    QuickSort(nums,numsSize);

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=nums[i+1])
            continue;
        else
            return true;
    }
    return false;
}


void QuickSort(int arr[],int N)
{
    Qsort(0,N-1,arr);
}

void Qsort(int left, int right, int arr[])
{
    int l,r,x;
    if(left<right)
    {

        l=left;
        r=right;
        x=arr[l];
        while(l<r){
            while(l<r && arr[r]>x)
                    r--;
            if(l<r)
                arr[l++]=arr[r];
            while(r>l && arr[l]<x)
                l++;
            if(l<r)
                arr[r--]=arr[l];
        }
        arr[l]=x;
        Qsort(left,l-1,arr);
        Qsort(l+1,right,arr);
    }

}
