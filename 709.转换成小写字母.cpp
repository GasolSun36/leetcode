/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
/*
小写字母与大写字母ascii差32，大写字母ascii小，小写字母ascii大
 */
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i]<='Z'&&str[i]>='A')
            {
                str[i]+=32;
            }            
        }       
    }
};

