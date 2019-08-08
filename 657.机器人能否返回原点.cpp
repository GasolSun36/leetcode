/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int u = 0, d = 0, l = 0, r = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'U')
            {
                u++;
            }
            else if (moves[i] == 'D')
            {
                d++;
            }
            else if (moves[i] == 'L')
            {
                l++;
            }
            else
                r++;
        }
        if (u != d || l != r)
        {
            return false;
        }
        return true;
    }
};
