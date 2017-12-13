#include<stdio.h>
#include<stdlib.h>
#include<string.h>                                                  //算法太慢，如何优化？

int arrayNesting(int* nums, int numsSize);

int main(void)
{
    int arr[]={0,2,1};
    printf("%d\n",arrayNesting(arr,3));
    return 0;

}


int arrayNesting(int* nums, int numsSize) {

    int arr[20000]={0};
    int i=0,j,result=0,count;
    for(j=0;j<numsSize;j++)
    {
        i=j;
        count=0;
        while(i!=nums[j])
        {
            count++;
            i=nums[i];

        }
        if(count>result)
            result=count;
        printf("%d\n",arr[0]);
        memset(arr,0,sizeof(int)*20000);
        printf("%d\n",arr[0]);
    }
    return result;
}
