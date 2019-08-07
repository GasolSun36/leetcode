/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
/*
思路：遇到数字就放入栈中，遇到D就将栈顶元素*2，遇到C就将栈顶元素移除，
遇到+就将栈顶两个元素的和放入栈顶（两个元素保持不变）
 */
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> S;
        int add = 0;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "+")
            {
                int top = S.top();
                S.pop();
                int temp=top+S.top();
                S.push(top);
                S.push(temp);
            }
            else if (ops[i] == "D")
            {
                S.push(S.top()*2);
            }
            else if (ops[i] == "C")
            {
                S.pop();
            }
            else
            { //ops[i]为数字
                S.push(stoi(ops[i]));//stoi:string to int        
            }
        }
        while (!S.empty())
        {
            int temp = S.top();
            S.pop();
            add += temp;
        }
        return add;
    }
};
