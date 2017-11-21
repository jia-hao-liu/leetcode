#include<stdio.h>

int findComplement(int num);

int main(void)
{
    int a,num;
    scanf("%d",&num);
    a=findComplement(num);
    printf("%d\n",a);
    return 0;
}

int findComplement(int num) {
    int arr[32];
    int i=0,output=0,temp=1;
    while(num>0)
    {
        arr[i]=num%2;
        num/=2;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        arr[j]=~arr[j];
        printf("%d ",arr[j]);
    }
    for(int j=0;j<i;j++)
    {
        output+=arr[j]*temp;
        temp*=2;
    }
    return output;
}
