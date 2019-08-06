/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
/*
思路：遇到数字放到栈里面，遇到操作符则取出栈顶两个元素并进行运算，然后再将结果存入栈中
 */
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int back, front, sum;
        stack<int> S;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                back = S.top();
                S.pop();
                front = S.top();
                S.pop();
                sum = front + back;
                S.push(sum);
            }
            else if (tokens[i] == "-")
            {
                back = S.top();
                S.pop();
                front = S.top();
                S.pop();
                sum = front - back;
                S.push(sum);
            }
            else if (tokens[i] == "*")
            {
                back = S.top();
                S.pop();
                front = S.top();
                S.pop();
                sum = front * back;
                S.push(sum);
            }
            else if (tokens[i] == "/")
            {
                back = S.top();
                S.pop();
                front = S.top();
                S.pop();
                sum = front / back;
                S.push(sum);
            }
            else
            {
                int num;
                stringstream ss(tokens[i]);
                ss >> num;
                S.push(num);
            }
        }
        return S.top();
    }
};
