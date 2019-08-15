/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
因为是平衡二叉树，所以肯定不可以直接用有序数组从头到尾直接创建，这会变成一个斜树
（当然可以用插入法创建，每插入一个新节点就判断是否平衡，不平衡就调整也可以，不过有更简单的方法）
二叉搜索树的中序遍历就是一个先序顺序。
先序顺序数组的中点就应该是平衡二叉搜索树的根节点，所以每次找中点然后递归即可
*/
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sorted(nums, 0, nums.size());
    }
    TreeNode *sorted(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sorted(nums, start, mid);
        root->right = sorted(nums, mid + 1, end);
        return root;
    }
};
