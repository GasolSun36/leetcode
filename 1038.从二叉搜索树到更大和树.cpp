/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：按右中左的顺序进行遍历，因为二叉搜索树的最大值肯定是在右边，其次是中间，最后是左边
所以右子树好理解，从4的左子树开始，第一个结点不看1，而看3，是4的左子树的右子树的最右结点
即左子树最大的结点，从这个结点开始，再按次序往回赋值。
因为要赋值大于等于它的数，（1.）如果它在根的右子树的方向，则大于等于它的数都在它的右子树上（例如6,7,）
或者是上一节点以及其右子树上（例如5）
（2.）但如果它在根的左子树方向，那么它需要加上根节点以及所有根的右子树上的结点（比如1,2,3,0）
*/
class Solution
{
public:
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root)
        {
            root->right = bstToGst(root->right);
            sum += root->val;
            root->val = sum;
            root->left = bstToGst(root->left);
        }
        return root;
    }
};

