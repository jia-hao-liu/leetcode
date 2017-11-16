#include<stdio.h>
#include<stdlib.h>

int findmax(int arr[], int N);
struct TreeNode* a(int* nums, int numsSize);

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int main(void)
{

}

sturct TreeNode* a(int* nums,int numsSize)
{
    struct TreeNode* root;
    root=malloc(sizeof(struct TreeNode));
    root->val=findmax(nums,numsSize);

}



/*int main(void)
{
    int arr[]={3,2,1,6,0,5,8,7,1};
    int N=9;
    struct TreeNode* root;
    root=a(arr,N);


    printf("%d\n", root->val);
    printf("%d", findmax(arr,N));
    return 0;
}

struct TreeNode* a(int* nums, int numsSize) {
    if(numsSize==0)
        puts("error!");

    struct TreeNode* root;
    int i=findmax(nums,numsSize);
    int L,R;
    root=malloc(sizeof(struct TreeNode));
    root->val=nums[i];
    printf("%d %d\n",root->val, i);
    //printf("%d\n", root->val);
    //root->left=malloc(sizeof(struct TreeNode));
    //root->right=malloc(sizeof(struct TreeNode));
    //roor->left->val=nums[findmax(nums,i)];
    //root->right-val=nums(findmax(nums+i+1,N-i-1));
    if(i>1 && i<numsSize-2)
    {
        root->left=a(nums,i);
        root->right=a(nums+i+1,numsSize-i-1);
    }
    else if(i==1 && i!=numsSize-1)
    {
        root->left=malloc(sizeof(struct TreeNode));
        root->left->val=nums[0];
        root->left->left=root->left->right=NULL;
        root->right=a(nums+2,numsSize-2);
    }
    else if(i==numsSize-2 && i!=0)
    {
        root->right=malloc(sizeof(struct TreeNode));
        root->right->val=nums[numsSize-1];
        root->left=a(nums,numsSize-2);
        root->right->left=root->right->right=NULL;
    }
    else if(numsSize==1)
    {
        root->left=root->right=NULL;
    }
    else if(i==0)
    {
        root->left=NULL;
        printf("%d\n",numsSize-1);
        root->right=a(nums+1,numsSize-1);

    }
    else if(i==numsSize-1)
    {
        root->right=NULL;
        root->left=a(nums,numsSize-1);
    }
    return root;


}
*/
int findmax(int arr[], int N)//找最大的数的算法
{

    int i,index=0,temp=arr[0];
    for(i=1;i<N;i++)
    {
        if(arr[i]>temp)
        {
            temp=arr[i];
            index=i;
        }
    }

    return index;

}
