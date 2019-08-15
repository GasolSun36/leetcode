/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
递归
 */
class Solution
{
public:
    int maxDepth(Node *root)
    {
        int temp = 0;
        if (!root)
        {
            return 0;
        }
        else
        {
            for (auto num : root->children)
            {
                temp = max(temp, maxDepth(num));
            }
        }
        return temp + 1;
    }
};
