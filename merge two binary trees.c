#include<stdio.h>


struct TreeNode* mergeNodes(struct TreeNode* node1, struct TreeNode* node2);
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2);

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };





struct TreeNode* mergeNodes(struct TreeNode* node1, struct TreeNode* node2)
{
    if(node1==NULL)
        return node2;
    if(node2==NULL)
        return node1;
    node1->val+=node2->val;
    if(node1->left==NULL && node2->left!=NULL)
        node1->left=node2->left;
    if(node1->right==NULL && node2->right!=NULL)
        node1->right=node2->right;
    return node1;

}


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode* t;
    t=t1;
    if(t1==NULL)
        return t2;
    if(t2==NULL)
        return t1;
    if(t1->left || t2->left)
        mergeTrees(t1->left,t2->left);
    if(t1->right || t2->right)
        mergeTrees(t1->right,t2->right);
        mergeNodes(t1,t2);
    return t1;

}

