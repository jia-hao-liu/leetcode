#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maximumSwap(int num) ;
int power(int a, int b);

int main(void)
{
   //printf("%d\n",maximumSwap(20));
   int N;
  // scanf("%d",&N);
   printf("%d\n",maximumSwap(908974));
   //printf("%d\n",maximumSwap(20));
   return 0;
}


/*int maximumSwap(int num) {
    if(num<12)
        return num;
    int result=0;
    int bit_now=0,bit_temp=0,temp=num,count=0;
    int i,j,nowcount;
    while(temp>0)
    {
        count++;
        bit_temp=temp%10;
        temp/=10;
        if(bit_temp>bit_now)
        {
            bit_now=bit_temp;
            nowcount=count;
        }
    }
    int originalHigh=bit_temp;
    if(bit_now==originalHigh)
    {
        if(num%power(10,count-1)/power(10,count-2)==0)
        {
            int temp1=num%power(10,count-2);
            int temp2=temp1;
            int bit_now2=0,count2=0,nowcount2;

            while(temp1>0)
            {
                count2++;
                bit_temp=temp1%10;
                temp1/=10;
                if(bit_temp>bit_now2)
                {
                    bit_now2=bit_temp;
                    nowcount2=count2;
                }
            }
            printf("%d %d %d %d\n",bit_now2*power(10,count-2),count,temp2, bit_now2*power(10,nowcount2-1));
            return power(10,count-1)*originalHigh+bit_now2*power(10,count-2)+temp2-bit_now2*power(10,nowcount2-1);

        }
        return power(10,count-1)*originalHigh+ maximumSwap(num%power(10,count-1));

    }

    temp=num;
    result=num%power(10,nowcount-1)+power(10,nowcount-1)*originalHigh;
    printf("%d   %d  %d  %d %d\n",power(10,count-1)*bit_now, num%power(10,count-1), num%power(10,nowcount),power(10,nowcount), nowcount);
    result+=power(10,count-1)*bit_now+num%power(10,count-1)-num%power(10,nowcount);
    return result;
}
int power(int a,int b)
{
    int temp=1;
    for(int i=1;i<=b;i++)
    {
        temp*=a;

    }
    return temp;
}
*/

int maximumSwap(int num) {
    int arr[10]={0};
    int num_temp=num,count=0,Highbit=0,less=0;
    while(num_temp>0)
    {

        arr[++count]=num_temp%10;
        num_temp/=10;
        if(arr[count]>=arr[Highbit])
        {
            less=Highbit;
            Highbit=count;

        }
    }
    printf("%d  %d\n",Highbit, arr[Highbit]);
    int originalHigh=arr[count];
    if(originalHigh==arr[Highbit])
    {
        if(arr[count-1]==0)
        {
            return originalHigh*power(10,count-1)+arr[less]*power(10,count-2)+num%power(10,count-2)-arr[less]*power(10,less-1);
        }
        return originalHigh*power(10,count-1)+maximumSwap(num%power(10,count-1));

    }
    printf("%d %d %d", Highbit, count, originalHigh);
    return arr[Highbit]*power(10,count-1)+num%power(10,count-1)-(arr[Highbit]-originalHigh)*power(10,Highbit-1);
}
int power(int a,int b)
{
    int temp=1;
    for(int i=1;i<=b;i++)
    {
        temp*=a;

    }
    return temp;
}
