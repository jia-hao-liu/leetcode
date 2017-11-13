#include<stdio.h> //输入项很多时有点小问题


int plus(struct polynomial* pol1, struct polynomial* poly2);

struct polynomial{
    int coef;
    int expon;
    struct polynomial* next;
};

int main(void)
{
    int c,e,N,N1,N2;
    scanf("%d", &N);
    N1=N;
    struct polynomial* P1;
    struct polynomial* P2;
    struct polynomial* temp1;
    struct polynomial* temp2;
    P1=malloc(sizeof(struct polynomial));
    P2=malloc(sizeof(struct polynomial));
    temp1=P1;
    temp2=P2;
    while(N--)
    {
        scanf("%d %d", &c, &e);
        P1->next=malloc(sizeof(struct polynomial));
        P1->next->expon=e;
        P1->next->coef=c;

        if(N==0)
        {
            P1->next->next=NULL;
            P1=temp1;
        }
        else
            P1=P1->next;
    }
    scanf("%d", &N);
    N2=N;
    while(N--)
    {
        scanf("%d %d", &c, &e);
        P2->next=malloc(sizeof(struct polynomial));
        P2->next->expon=e;
        P2->next->coef=c;

        if(N==0)
        {
            P2->next->next=NULL;
            P2=temp2;
        }
        else
            P2=P2->next;
    }
    N=plus(P1,P2);
    N1=N1+N2-N;
    printf("%d  ", N1);
    while(P1->next)
    {
        printf("%d %d  ", P1->next->coef,P1->next->expon);
        P1=P1->next;
    }


    return 0;
}


int plus(struct polynomial* pol1, struct polynomial* pol2)
{
        //if(!(pol1 && pol2 && pol1->next && pol2->next))
            //return null;
        int count=0;
        struct polynomial* temp1;
        struct polynomial* temp2;
        temp1=pol1;
        temp2=pol2;



        while(temp1->next && temp2->next)
        {

            if(temp1->next->expon==temp2->next->expon)
            {
                temp1->next->coef+=temp2->next->coef;
                printf("%d\n", temp1->next->coef);
                temp1=temp1->next;
                temp2=temp2->next;
                count++;
            }
            else if(temp1->next->expon>temp2->next->expon)
                temp1=temp1->next;
            else if(temp1->next->expon<temp2->next->expon)
            {
                temp2=temp2->next;
                struct polynomial* temp;
                temp=malloc(sizeof(struct polynomial));
                temp->coef=temp2->coef;
                temp->expon=temp2->expon;
                temp->next=temp1->next;
                temp1->next=temp;


            }

        }
        while(temp2->next)
        {
            temp1->next=temp2->next;
        }

        return count;
}


