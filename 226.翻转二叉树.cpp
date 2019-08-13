/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
第一遍思路：把所有可能情况想出来然后对号入座即可
 */
// class Solution
// {
// public:
//     TreeNode *invertTree(TreeNode *root)
//     {
//         reverTree(root);
//         return root;
//     }
//     void reverTree(TreeNode *root)
//     {
//         if (!root)
//         {
//             return;
//         }
//         if (!root->left && !root->right)
//         {
//             return;
//         }
//         if (root->left && root->right)
//         {
//             TreeNode *T = root->left;
//             root->left = root->right;
//             root->right = T;
//         }
//         else if (!root->left && root->right) //root左子树为NULL，右子树存在
//         {
//             root->left = root->right;
//             root->right = NULL;
//         }
//         else
//         { //root右子树为NULL，左子树存在
//             root->right = root->left;
//             root->left = NULL;
//         }
//         reverTree(root->left);
//         reverTree(root->right);
//     }
// };
/*
第二遍思路：可以将左子树和右子树有一个不存在的情况统一一下
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        reverTree(root);
        return root;
    }
    void reverTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            return;
        }
        if (root->left && root->right)
        {
            TreeNode *T = root->left;
            root->left = root->right;
            root->right = T;
        }
        else if (!root->left && root->right) //root左子树为NULL，右子树存在
        {
            root->left = root->right;
            root->right = NULL;
        }
        else
        { //root右子树为NULL，左子树存在
            root->right = root->left;
            root->left = NULL;
        }
        reverTree(root->left);
        reverTree(root->right);
    }
};

