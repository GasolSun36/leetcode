/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
自己的方法：
判断，如果root的值正好在p和q的值之间，那么就返回root的值（这种情况root肯定是两个的最近公共祖先）
如果root的值正好等于p或q，那么直接返回p或q（这种情况对应一个结点可能是它自己的祖先）
而如果root的值比p或q大或者比p或q都要小，那么递归判断root的左子树后右子树
*/
// class Solution
// {
// public:
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         if (root)
//         {
//             if (root->val > p->val && root->val < q->val || root->val > q->val && root->val < p->val)
//             {
//                 return root;
//             }
//             else if (root->val == p->val)
//             {
//                 return p;
//             }
//             else if (root->val == q->val)
//             {
//                 return q;
//             }
//             else
//             {
//                 if (root->val > p->val && root->val > q->val)
//                 {
//                     return lowestCommonAncestor(root->left, p, q);
//                 }
//                 else
//                     return lowestCommonAncestor(root->right, p, q);
//             }
//         }
//         return root;
//     }
// };
/*
将上面的方法简化了一下，root->val == p->val和root->val == q->val以及上面
root->val > p->val && root->val < q->val || root->val > q->val && root->val < p->val
都可以算到下面方法的else里面，这样简化了计算
需要注意的是，实际上可以删去else return root，因为如果走else的话，那么就直接弹出if循环
走最外面的return root
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if (root->val < p->val && root->val < q->val)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
            else
                return root;
        }
        return root;
    }
};
