/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */
/*
因为只能改变奇数或者偶数位置上的字符使字符串特殊等价，所以创建一个odd和even的string变量
这两个变量存储每个字符串的奇数位置上的和偶数位置上的字符，然后排序后相加，此时如果相等，则证明其特殊等价
最后用set，将其放入，因set唯一性保证set的最后size就是最后输出的个数
*/
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        set<string> S;
        for (int i = 0; i < A.size(); i++)
        {
            string odd = "", even = "";
            for (int j = 0; j < A[i].size(); j++)
            {
                if (j % 2 == 0)
                {
                    odd += A[i][j];
                }
                else
                    even += A[i][j];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            S.insert(odd + even);
        }
        return S.size();
    }
};
