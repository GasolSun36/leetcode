/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
/*
变式动态规划，不需要dp数组，但要求得当前最小值，然后判断prices[i]-nmin
和dp[i-1]哪个大赋值哪个给dp[i]
*/
class Solution
{
public:
    int dp[100001];
    int maxProfit(vector<int> &prices)
    {
        dp[0] = 0;
        int nmax = dp[0];
        int nmin;
        if (prices.size() > 0)
        {
            nmin = prices[0];
        }
        for (int i = 1; i < prices.size(); i++)
        {
            nmin = min(nmin, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - nmin);
            if (dp[i] > nmax)
            {
                nmax = dp[i];
            }
        }
        return nmax;
    }
};
