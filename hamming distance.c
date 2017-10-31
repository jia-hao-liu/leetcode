#include<stdio.h>
#define bit 32

void decimaltobinary(int x,int arr[]);
int hammingDistance(int x, int y);

int main(void)
{
    int number1,number2;
    scanf("%d %d", &number1, &number2);
    printf("the hammingDistance of %d and %d is %d.\n",
           number1,number2,hammingDistance(number1,number2));
    return 0;
}







int hammingDistance(int x, int y) {
    //百度十进制数与二进制数之间的转换
    int i,count=0;
    int binary1[bit]={0};
    int binary2[bit]={0};
    decimaltobinary(x,binary1);
    decimaltobinary(y,binary2);
    for(i=0;i<32;i++)
    {
        if(binary1[i]!=binary2[i])
            count++;
    }
    return count;


}

void decimaltobinary(int x, int arr[])
{
    int i;
    for(i=0;i<32;i++)
    {
        arr[i]=x%2;
        if(x==1)
            break;
        x/=2;
    }

}
