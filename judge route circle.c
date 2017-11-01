#include<stdio.h>
/*     针对本题更简单的算法

bool judgeCircle(char* moves) {
    int i,countL,countR,countU,countD;
    countL=countR=countU=countD=0;

    for(i=0;moves[i]!='\0';i++)
    {
        switch(moves[i])
        {
            case 'L':
                countL++;
                break;
            case 'R':
                countR++;
                break;
            case 'U':
                countU++;
                break;
            case 'D':
                countD++;
                break;
            default:
                puts("error!");
        }
    }
    if(countL==countR && countU==countD)
        return true;
    else
        return false;
}
*/



typedef struct position* pos;
void move(pos node, char ch);

struct position{
    int x;
    int y;
};


int main(void)
{
    int i=0;
    char moves[50];
    puts("Please scanf your moves string:(empty line to end)");
    while((moves[i]=getchar())!='\n')
    {
        i++;
    }
    if(judgeCircle(moves))
        puts("it is a circle!");
    else
        puts("it is not a circle!");
    return 0;
}

int judgeCircle(char* moves) {
    int i=0;
    pos now;
    now=(pos)malloc(sizeof(struct position));
    now->x=0;
    now->y=0;
    for(i=0;moves[i]!='\n';i++)
    {
        move(now,moves[i]);
    }
    if(now->x==0 && now->y==0)
        return 1;
    else
        return 0;
}

void move(pos node, char ch)
{
    if(ch=='R')
        node->x+=1;
    else if(ch=='L')
        node->x-=1;
    else if(ch=='U')
        node->y+=1;
    else if(ch=='D')
        node->y-=1;
    else
        puts("error!");
}


