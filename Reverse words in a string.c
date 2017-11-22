#include<stdio.h>
#include<stdlib.h>
void reverseWords(char* s);

int main(void)
{
    char ch[]= "Let's take LeetCode contest";
    reverseWords(ch);
    puts(ch);
    return 0;
}

void reverseWords(char* s) {
    int index=0;

    int count=0,count1=-1,i=0;
    while(s[count]!='\0')
    {


        count++;
    }

    char temp[100];
    int j;
    while(index!=count)
    {
        i=0;
        count1+=1;
        while(s[count1]!=' ' && count1<count)
        {
            temp[i]=s[count1];
            count1++;
            i++;
        }

        for(i=i-1;i>=0;i--)
        {
            s[index++]=temp[i];
        }
        if(index!=count)
            s[index++]=' ';

    }




}
