#include<stdio.h>
#include<stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize);

int main(void)
{
    int l,r;
    scanf("%d %d", &l,&r);
    int* size=malloc(sizeof(int));
    int* p;
    p=selfDividingNumbers(l,r,size);
    printf("%d\n",*size);
    for(int i=0;i<*size;i++)
        printf("%d ", p[i]);
    return 0;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int count=0,temp;
    int l=left;

    int* result=malloc(sizeof(int)*(right-left+1));


    for(;l<=right;l++)
    {
        if(!(l%10))
            continue;
        temp=l;
        while(temp>0 && !(l%(temp%10)) )
        {
            temp/=10;
            if(!(temp%10))
                break;
        }
        if(!temp)
            result[count++]=l;

    }
    *returnSize=count;
    return result;
}
