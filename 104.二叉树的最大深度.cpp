/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
第一遍超时两个测试点，因为最后一个return语句maxDepth(root->left)递归时间使用太长，而且使用两遍
 */
// class Solution
// {
// public:
//     int maxDepth(TreeNode *root)
//     {
//         if (!root)
//         {
//             return 0;
//         }
//         else if (!root->left && !root->right)
//         {
//             return 1;
//         }
//         else
//             return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;
//     }
// };
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root){
            return 0;
        }
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
/*
极简法
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
