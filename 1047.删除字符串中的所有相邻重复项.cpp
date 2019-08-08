/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
/*
思路：使用一个栈，将元素按顺序放入，如果当前要放入的元素跟栈顶元素一样，则将栈顶元素弹出
否则就放入当前元素，然后最后从栈顶弹出的元素逆序即结果
注意：一定要注意S.top()或S.pop()之前都要判断栈空，否则会报内存检测的错误
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> stack;
        for (int i = 0; i < S.size(); i++)
        {
            if (!stack.empty())
            {
                if (stack.top() == S[i])
                {
                    stack.pop();
                }
                else
                    stack.push(S[i]);
            }
            else
                stack.push(S[i]);
        }
        string str = "";
        while (!stack.empty())
        {
            str += stack.top();
            stack.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
