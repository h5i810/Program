#include <iostream>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

bool isSubTree(TreeNode* pRootA, TreeNode* pRootB){
    if(pRootB==NULL)
        return true;
    if(pRootA==NULL)
        return false;
    if(pRootA->val==pRootB->val)
        return isSubTree(pRootA->left,pRootB->left) &&
                isSubTree(pRootA->right, pRootB->right);
    else
        return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot1==NULL||pRoot2==NULL)
        return false;
    if(isSubTree(pRoot1, pRoot2))
        return true;
    else
        return HasSubtree(pRoot1->left, pRoot2)||
                HasSubtree(pRoot1->right, pRoot2);
}
