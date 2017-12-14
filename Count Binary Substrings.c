#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int power(int a,int b)
{
    int temp=1;
    for(int i=1;i<=b;i++)
    {
        temp*=a;

    }
    return temp;
}
int missingNumber(int* nums, int numsSize);
int countBinarySubstrings(char* s);

int main(void)
{
    int N;
    scanf("%d",&N);
    char arr[N+1];
    getchar();
    gets(arr);
    printf("%d\n",countBinarySubstrings(arr));

}
int countBinarySubstrings(char* s) {
    int count0=0,count1=0,i=0,flag=0,result=0,index;
    while(s[i]!='\0')
    {
        //printf("%d %d\n",count0,  count1);
        if(s[i]=='0')
            count0++;
        else
            count1++;
        if(s[i]!=s[i+1])
        {
            flag++;
        }
        if(flag==2)
        {
            result+=count0>count1?count1:count0;
            flag=1;
            if(s[i]=='1')
                {
                    count0=0;
                   // printf("11111\n");
                }
            else
                count1=0;
        }
        i++;
    }
    return result;
}
