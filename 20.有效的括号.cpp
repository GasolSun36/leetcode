/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
/*
思路：坑点比较多，如果遇到左括号则加入到栈中，遇到右括号则看栈顶元素是否与之匹配，若不匹配则false
若匹配则将栈顶元素删除，继续做判断。当然，比较时应注意先判断栈是否为空
因为只有右括号时肯定是false，但不判断就进行S.top()肯定会错误
最后判断，如果栈为空，说明全部匹配，则正确，否则错误
 */
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> S;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                S.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!S.empty())
                {
                    if (S.top() != '(')
                    {
                        return false;
                    }
                    else
                        S.pop();
                }
                else return false;
            }
            else if (s[i] == '}')
            {
                if (!S.empty())
                {
                    if (S.top() != '{')
                    {
                        return false;
                    }
                    else
                        S.pop();
                }
                else return false;
            }
            else
            {
                if (!S.empty())
                {
                    if (S.top() != '[')
                    {
                        return false;
                    }
                    else
                        S.pop();
                }
                else return false;
            }
        }
        if (!S.empty())
        {
            return false;
        }
        else
            return true;
    }
};
