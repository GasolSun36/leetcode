/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */
/*
我的思路是遇到左括号放进去，遇到右括号就从栈顶拿一个左括号，并且判断栈是否为空
若不为空，则说明不是外层括号，则str+="()"，
若为空，则说明是外层括号，则不进行操作
23 / 59 个通过测试用例
输入：
"(()())(())(()(()))"
输出：
"()()()()()()"
预期：
"()()()()(())"
 */
// class Solution
// {
// public:
//     string removeOuterParentheses(string S)
//     {
//         stack<char> s;
//         string str = "";
//         for (int i = 0; i < S.size(); i++)
//         {
//             if (S[i] == '(')
//             {
//                 s.push(S[i]);
//             }
//             else
//             {
//                 if (s.top() == '(')
//                 {
//                     s.pop();
//                     if (!s.empty())
//                     {
//                         str += "()";
//                     }
//                 }
//             }
//         }
//         return str;
//     }
// };
/*
参考一个老哥的思路：count用来记数，如果遇到左括号，则count必须大于1才可以加入到str中（count大于1表示它不是最外层的括号）
 然后如果遇到右括号，则count必须大于等于1才可以加入到str中（count=0表示最外层的右括号，大于等于1表示不是最外层的右括号）
 count=0时说明一组左右括号已经平衡，即左括号数量等于右括号数量
 */
class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string str = "";
        int count = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '('){
                count++;
                if (count > 1)
                    str += S[i];
            }
            else{
                count--;
                if (count >= 1)
                    str += S[i];
            }
        }
        return str;
    }
};
