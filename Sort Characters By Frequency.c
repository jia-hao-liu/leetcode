#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertionsort(int arr[],int N,char arr2[], int n);
char* frequencySort(char* s);

int main(void)
{
    int N;
    scanf("%d",&N);
    char arr[N];
    getchar();
    gets(arr);
    char* p=frequencySort(arr);
    puts(p);
    return 0;
}

char* frequencySort(char* s) {
    int arr[127]={0};
    int i,now=0;
    for(i=0;s[i]!='\0';i++)
    {

        arr[s[i]]++;
    }
    char* result=malloc(sizeof(char)*127);
    for(int j=0;j<127;j++)
        result[j]=j;
    insertionsort(arr,127,result,i);
    memset(result+i,0,sizeof(char)*(127-i));
    char* answer=malloc(sizeof(char)*(i+1));
    for(int j=0;j<i;j++)
    {
        memset(answer+now,result[j],sizeof(char)*arr[j]);
        now+=arr[j];
    }
    answer[now]='\0';
    return answer;
}

void insertionsort(int arr[],int N,char arr2[], int n)
{
    int i,j,temp,temp1;
    for(i=1;i<N;i++)
    {
        temp1=arr2[i];
        temp=arr[i];
        for(j=i-1;j>=0 && arr[j]<temp;j--)
        {
            arr[j+1]=arr[j];
            arr2[j+1]=arr2[j];
        }
        arr[j+1]=temp;
        arr2[j+1]=temp1;

    }

}
