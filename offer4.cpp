/************************************************************************
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设
 *       输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入
 *       前序遍历序列 {1,2,4,7,3,5,6,8}和中序遍历序列{4, 7, 2, 1, 5, 3,
 *       8, 6}，则重建二叉树并返回。
 ***********************************************************************/

 /**************************************************
  * struct TreeNode{
  *     int val;
  *     TreeNode* left;
  *     TreeNode* right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  * ************************************************/

/*********************************************************************
 * 思路：
 *     1、先求出根节点（前序序列第一个元素）。
 *     2、将根节点带入到中序遍历序列中求出左右子树的中序遍历序列
 *     3、通过左右子树的中序序列元素集合，带入到前序遍历序列可以求出
 *        左右子树的前序序列
 *     4、左右子树的前序序列的第一个元素分别是根节点的左右儿子
 *     5、求出左右子树的四种序列可以递归上述步骤
 *********************************************************************/

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin){
    if(pre.size()==0||vin.size()==0||pre.size()==vin.size())
        return NULL;
    int root=pre[0]; 
    TreeNode* node=new TreeNode(root);
    vector<int>::iterator it, target;
    
    target=find(vin.begin(), vin.end(), root);
    if(target==vin.end())
        return NULL;
    vector<int> inLeft(vin.begin(), target);
    vector<int> inRight(++target, vin.end());

    int numleft=inLeft.size();
    int numRight=inright.size();
    vector<int> preLeft(pre.begin()+1, pre.begin.begin()+numleft+1);
    vector<int> preRight(pre.begin()+1+numleft, pre.end());

    node->left=reConstructBinaryTree(preLeft, inLeft);
    node->right=reConstructBinaryTree(preRight, inRight);

    return node;
 }
