#include<stdio.h>
#include<stdlib.h>

void insertionsort(int arr[],int N);
int leastInterval(char* tasks, int tasksSize, int n);

int main(void)
{
    int N,n;
    scanf("%d %d",&N, &n);
    char arr[N];
    for(int i=0;i<N;i++)
        scanf("%s",&arr[i]);
    N=leastInterval(arr,N,n);
    printf("%d\n", N);
    return 0;

}





int leastInterval(char* tasks, int tasksSize, int n) {
    int i,arr[100]={0},count=0,count_n=0;
    for(i=0;i<tasksSize;i++)
    {
        arr[tasks[i]]++;
    }


    insertionsort(arr+65,26);
    while(arr[65])
    {
        count_n=0;
        while(count_n<n+1)
        {
            if(arr[65]==0)
                break;
            if(arr[65+count_n]>0 && count_n<26)
                arr[65+count_n]--;

            count++;
            //printf("%d\n",count);
            count_n++;
        }
        insertionsort(arr+65,26);

    }
    return count;

}


void insertionsort(int arr[], int N)
{


    int i,j,temp;

    for(i=1;i<N;i++)
    {
        temp=arr[i];
        for(j=i;j>0 && arr[j-1]<temp;j--)
        {
            arr[j]=arr[j-1];

        }
        arr[j]=temp;

    }
}
