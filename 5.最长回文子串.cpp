/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
/*
跟PAT的题目差不多，只不过PAT要求的是最长回文子串的长度，而leetcode让求最长回文子串本身
在原基础上改成每当cnt比当前str的值大时就更新str，（除了第一个，因为第一个是只有一个字符，
如果cnt大于等于它的话就更新，以便后续就直接加上s[i+1]了）
(举个例子，abb，如果第一个字符是a，str为a，发现a不等于b，则继续。然后此时轮到b的时候cnt等于str.size()，
然后再更新str得str等于b，这样当b发现b跟后面的b相等时，不需要重置str，直接加上s[i+1]即得bb)
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int dp[1000][1000] = {0};
        int cnt = 1;
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
            cnt = 1;
            if (cnt >= str.size())
            {
                str.clear();
                str += s[i];
            }
            if (s[i] == s[i + 1] && i < s.size() - 1)
            {
                dp[i][i + 1] = 1;
                cnt = 2;
                if (cnt > str.size())
                {
                    str += s[i + 1];
                }
            }
        }
        for (int L = 3; L <= s.size(); L++)
        {
            for (int i = 0; i < s.size() - L + 1; i++)
            {
                int temp = i + L - 1;
                if (s[i] == s[temp] && dp[i + 1][temp - 1] == 1)
                {
                    cnt = L;
                    dp[i][temp] = 1;
                    if (cnt > str.size())
                    {
                        str.clear();
                        for (int m = i; m <= temp; m++)
                        {
                            str += s[m];
                        }
                    }
                }
            }
        }
        return str;
    }
};
