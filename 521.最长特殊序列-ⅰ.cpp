/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
//如果a，b的长度相等且内容相等，则证明没有特殊子序列，若不相等则较长的那个是特殊序列
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : a.size() > b.size() ? a.size() : b.size();
    }
};
