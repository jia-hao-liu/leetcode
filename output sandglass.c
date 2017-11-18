#include<stdio.h>
int main(void)
{
  int N;
  char ch;
  puts("Please scanf your character and your character numbers.");
  scanf("%d",&N);
  getchar();
  scanf("%c", &ch);
  //printf("%d", N);
  challeng(N,ch);
  return 0;
}

void challeng(int N, char ch)
{

  int j,k,odd=N-1,i=3,count=0;
  while(odd>=2*i)
  {
    count++;
    odd-=2*i;
    i+=2;
  }

  for(i=count;i>=0;i--)
  {
      for( k=0;k<count-i;k++)
        printf(" ");
      for(j=0;j<2*i+1;j++)
        printf("%c",ch);
      printf("\n");
  }

  for(i=1;i<=count;i++)
  {
    for(k=0;k<count-i;k++)
      printf(" ");
    for(j=0;j<2*i+1;j++)
      printf("%c",ch);
    printf("\n");
  }

  printf("%d\n", odd);

}

