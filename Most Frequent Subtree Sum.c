#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode* PtrToLnode;
struct LNode{
    int num;
    int frequency;
    PtrToLnode next;

};
typedef PtrToLnode List;
typedef PtrToLnode Position;

typedef struct TableNode* HashTable;
struct TableNode{
    int TableSize;
    List Heads;
};
typedef struct TreeNode* PtrToTreeNode;
struct TreeNode{
    int val;
    PtrToTreeNode left;
    PtrToTreeNode right;
};

int NextPrime(int N);
int Hash(int N,int M);
HashTable CreateTable(int Size);
Position find(HashTable H, int num);
void insert(HashTable H, int num);
void traversal(struct TreeNode* root);
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) ;
int getLine(struct TreeNode* root);
typedef struct TreeNode* PtrToTreeNode;

void Inorder(struct TreeNode* root);
typedef PtrToTreeNode Tree;

Tree BuildTree(int num);
void Insert(Tree T, int num);
HashTable H;

int main(void)
{
    Tree T=BuildTree(5);
    int N;
    scanf("%d",&N);
    int num;
    for(int i=0;i<N;i++)
    {
        scanf("%d", &num);
        Insert(T,num);

    }

    int* a=malloc(sizeof(int));
    int* p=findFrequentTreeSum(T,a);
    for(int i=0;i<*a;i++)
        printf("%d ",p[i]);
    return 0;
}

int NextPrime(int N)
{
    if(N==1)
        return 1;
    int i=0;
    while(i<N-1)
    {
        for( i=2;i<N;i++)
        {
            if(N%i==0)
                break;
        }
        N++;
    }
    printf("%d", i);
    return i;
}

int Hash(int N, int M)
{

    return N%M;
}
HashTable CreateTable(int Size)
{
    HashTable hash;
    hash=malloc(sizeof(struct TableNode));
    hash->TableSize=NextPrime(Size);
    hash->Heads=malloc(sizeof(struct LNode)*hash->TableSize);
    for(int i=0;i<hash->TableSize;i++)
    {
        hash->Heads[i].num=-1;
        hash->Heads[i].next=NULL;
        hash->Heads[i].frequency=0;
    }
    return hash;
}

Position find(HashTable H, int num)
{
    Position P;
    int index;
    index=Hash(num,H->TableSize);
    P=H->Heads[index].next;
    while(P && P->num!=num)
        P=P->next;
    return P;
}
void insert(HashTable H,int num)
{
    Position P,NewNode;
    int index;
    P=find(H,num);
    if(!P)
    {
        NewNode=malloc(sizeof(struct LNode));
        index=Hash(num,H->TableSize);
        NewNode->next=H->Heads[index].next;
        H->Heads[index].next=NewNode;
        NewNode->num=num;
        NewNode->frequency=1;
    }
    else
    {
        P->frequency++;
    }

}
int getLine(struct TreeNode* root)
{
    if(!root)
        return 0;
    else if(!root->left && !root->right)
        return 1;

        return 1+getLine(root->left)>getLine(root->right)?getLine(root->left):getLine(root->right);
}


int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    if(!root)
        return NULL;
    int countfre=0,countres=0;
    int row=getLine(root);
    int size=(int)pow(2,row)-1;
    H=CreateTable(size);
    traversal(root);
    PtrToLnode temp;
    for(int i=0;i<H->TableSize;i++)
    {
        temp=H->Heads[i].next;
        while(temp)
        {
            if(temp->frequency>countfre)
            {
                countfre=temp->frequency;
                countres=1;
            }
            else if(temp->frequency==countfre)
            {
                countres++;
            }
            temp=temp->next;
        }
    }

    int* result=malloc(sizeof(int)*countres);
    *returnSize=countres;
    countres=0;
    for(int i=0;i<H->TableSize;i++)
    {
        temp=H->Heads[i].next;
        while(temp)
        {
            if(temp->frequency==countfre)
                result[countres++]=temp->num;
            temp=temp->next;
        }

    }

    return result;

}

void traversal(struct TreeNode* root)
{
    if(root)
    {
        traversal(root->right);
        traversal(root->left);
        if(root->left && root->right)
            insert(H,root->val+root->left->val+root->right->val);
        else if(root->left)
            insert(H,root->val+root->left->val);
        else if(root->right)
            insert(H,root->val+root->right->val);
        else
            insert(H,root->val);


    }
}
Tree BuildTree(int num)
{
    Tree T=malloc(sizeof(struct TreeNode));
    T->val=num;
    T->left=T->right=NULL;
    return T;
}

void Insert(Tree T, int num)
{
    if(!T->left)
    {
        T->left=malloc(sizeof(struct TreeNode));
        T->left->val=num;
        T->left->right=T->left->left=NULL;
    }
    else if(!T->right)
    {
        T->right=malloc(sizeof(struct TreeNode));
        T->right->val=num;
        T->right->right=T->right->left=NULL;

    }
    else
        Insert(T->left,num);

}
