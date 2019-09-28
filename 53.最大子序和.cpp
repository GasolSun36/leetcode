class Solution
{
public:
    int dp[100001];//数组开大些就不会有runtime写入错误了
    int maxSubArray(vector<int> &nums)
    {
        dp[0] = nums[0];
        int nmax = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if (dp[i] > nmax)
            {
                nmax = dp[i];
            }
        }
        return nmax;
    }
};