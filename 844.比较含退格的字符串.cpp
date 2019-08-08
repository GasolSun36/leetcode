/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
/*
思路：使用栈，遇到退格符就把栈顶元素弹出，最后比较两个栈是否一样
如果#加入栈时栈为空，则不允许其加入
 */
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<int> s;
        stack<int> t;
        for (int i = 0; i < S.size(); i++)
        {
            // if (!s.empty())
            // {
            //     if (S[i] == '#')
            //         s.pop();
            //     else
            //         s.push(S[i]);
            // }
            // else
            // {
            //     if (S[i] != '#')
            //     {
            //         s.push(S[i]);
            //     }
            // }
            if (S[i] == '#')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                else
                {
                    continue;
                }
            }
            else
                s.push(S[i]);
        }
        for (int i = 0; i < T.size(); i++)
        {
            // if (!T.empty())
            // {
            //     if (T[i] == '#')
            //         t.pop();
            //     else
            //         t.push(T[i]);
            // }
            // else
            // {
            //     if (T[i] != '#')
            //     {
            //         t.push(T[i]);
            //     }
            // }
            if (T[i] == '#')
            {
                if (!t.empty())
                {
                    t.pop();
                }
                else
                {
                    continue;
                }
            }
            else
                t.push(T[i]);
        }
        while (!s.empty() && !t.empty())
        {
            if (s.top() != t.top())
            {
                return false;
            }
            s.pop();
            t.pop();
        }
        if (!s.empty() || !t.empty())
        {
            return false;
        }
        return true;
    }
};
