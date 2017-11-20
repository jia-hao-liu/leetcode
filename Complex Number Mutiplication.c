#include<stdio.h>   //字符串中的空字符会自动添加吗？
#include<stdlib.h>
#define MaxSize 10

char* complexNumberMultiply(char* a, char* b, char* ch);
void conversion(int arr[],char* a);

int main(void)
{
    int i=0;
    char* c;
    char ch[MaxSize];
    char a[MaxSize];
    char b[MaxSize];
    while((a[i]=getchar())!='\n')
    {
        i++;
    }
    i=0;
    while((b[i]=getchar())!='\n')
    {
        i++;
    }

    //conversion(arr,);
    complexNumberMultiply(a,b,ch);
    puts(a);
    return 0;
}



char* complexNumberMultiply(char* a, char* b,char * ch) {
    int arra[2],arrb[2];
    int i=0,real,complex;

    conversion(arra,a);
    conversion(arrb,b);
    printf("%d %d %d %d\n",arra[0],arra[1],arrb[0],arrb[1]);
    real=arra[0]*arrb[0]-arra[1]*arrb[1];
    complex=arra[0]*arrb[1]+arra[1]*arrb[0];
    printf("%d %d\n", real, complex);
    //char ch[10];
    //if(real<0)
      //ch[0]='-';
    if(real<0)
        a[i++]='-';
    real=abs(real);
    if(real<10)
        a[i++]=real+48;
    else if(real<100)
    {
        a[i++]=real/10+48;
        a[i++]=real%10+48;
    }
    else
    {
        a[i++]=49;
        a[i++]=48;
        a[i++]=48;
    }
    a[i++]='+';
    if(complex<0)
        a[i++]='-';
    complex=abs(complex);
    if(complex<10)
        a[i++]=complex+48;
    else if(complex<100)
    {
        a[i++]=complex/10+48;
        a[i++]=complex%10+48;
    }
    else
    {
        a[i++]=49;
        a[i++]=48;
        a[i++]=48;
    }
    a[i++]='i';
    a[i++]='\0';
    return a;
}


void conversion(int arr[],char* a)
{       int i,j;
    if(a[0]!='-')
    {
        for( i=0; a[i]!='+';i++);
        if(i=1)
            arr[0]=a[0]-48;
        else if(i=2)
            arr[0]=(a[0]-48)*10+a[1]-48;
        else
            arr[0]=100;
        if(a[i+1]!='-')
        {
            for(j=0;a[j+i+1]!='i';j++);
            if(j=1)
                arr[1]=a[i+1]-48;
            else if(j=2)
                arr[1]=(a[i+1]-48)*10+a[i+2]-48;
            else
                arr[1]=100;
        }
        else
        {
            for(j=0;a[j+i+2]!='i';j++);
            if(j=1)
                arr[1]=-(a[i+2]-48);
            else if(i=2)
                arr[1]=-((a[i+2]-48)*10+a[i+3]-48);
            else
                arr[1]=-100;
        }

    }
    else
    {
        for( i=0; a[i+1]!='+';i++);
        if(i=1)
            arr[0]=-(a[0]-48);
        else if(i=2)
            arr[0]=-((a[0]-48)*10+a[1]-48);
        else
            arr[0]=-100;
        if(a[i+2]!='-')
        {
            for(j=0;a[j+i+2]!='i';j++);
            if(j=1)
                arr[1]=a[i+2]-48;
            else if(j=2)
                arr[1]=(a[i+2]-48)*10+a[i+3]-48;
            else
                arr[1]=100;
        }
        else
        {
            for(j=0;a[j+i+3]!='i';j++);
            if(j=1)
                arr[1]=-(a[i+3]-48);
            else if(i=2)
                arr[1]=-((a[i+3]-48)*10+a[i+4]-48);
            else
                arr[1]=-100;
        }
    }


}
