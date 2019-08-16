/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    vector<int> ans;
    vector<int> postorder(Node *root)
    {
        post(root);
        return ans;
    }
    void post(Node *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            for (int i = 0; i < root->children.size(); i++)
            {
                post(root->children[i]);
            }
            ans.push_back(root->val);
        }
    }
};
