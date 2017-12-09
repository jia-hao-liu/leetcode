#include<stdio.h>                                       //为何输入比N小1个字符串时就会退出循环，为何有*returnSize就会崩溃
#include<stdlib.h>
#include<string.h>


int getLine(char c);
char** findWords(char** words, int wordsSize, int* returnSize) ;

int main(void)
{
    int N;
    int* p;
    scanf("%d",&N);
    char** ch=malloc(sizeof(int)*(N+1));
    for(int i=0;i<6;i++)
    {
        ch[i]=malloc(20);
        gets(ch[i]);
    }
    ch=findWords(ch,N,p);
    for(int i=0;i<6;i++)
        puts(ch[i]);
    return 0;
}


char** findWords(char** words, int wordsSize, int* returnSize) {
    int i,j,c,row=0;
    char** result=malloc(sizeof(int)*wordsSize);
    for(i=0;i<wordsSize;i++)
    {

        if(words[i][1]=='\0')
        {
            char* newrow=malloc(2);
            result[row++]=strcpy(newrow,words[i]);
        }
        j=1;
        while(words[i][j]!='\0')
        {
            if(getLine(words[i][j-1])!=getLine(words[i][j++]))
                break;
            if(!words[i][j])
            {
                char* newrow=malloc(j+1);
                result[row++]=strcpy(newrow,words[i]);

            }
        }


    }
    //printf("1\n");
   // *returnSize=row;
    return result;
}

int getLine(char c)
{
    int i;
    char ch[3][20]={"ASDFGHJKLasdfghjkl","QWERTYUIOPqwertyuiop","ZXCVBNMzcvbnm"};
    for(i=0;i<18;i++)
    {
        if(c==ch[0][i])
            return 2;
    }
    for( i=0;i<20;i++)
        if(c==ch[1][i])
            return 1;
    return 3;
}
