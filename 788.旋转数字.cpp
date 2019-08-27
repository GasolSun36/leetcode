/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */
/*
理解题意：我之前认为是旋转，即（118旋转后是811），实际上题目认为（118旋转之后也是118）
即原地旋转
那么如果这个数的所有位里面不存在3,4,7且存在2,5,6,9的其中一个或多个，那么这个数就是
好数，存在3，4,7直接break掉
*/

class Solution
{
public:
    int rotatedDigits(int N)
    {
        int n;
        bool flag;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            n = i;
            flag = false;
            while (n > 0)
            {
                int temp = n % 10;
                n /= 10;
                if (temp == 3 || temp == 4 || temp == 7) //存在3,4,7不可能是好数
                {
                    flag = false;
                    break;
                }
                if (temp == 2 || temp == 5 || temp == 6 || temp == 9) //存在2,4,6,9的其中一个，有可能是好数，需要继续遍历
                {
                    flag = true;
                }
                //这里省略了如果是1,8的话，什么都不做
                //因为如果这个数只有1和8，那么按照flag默认是false的话它不算好数
                //如果这个数不光只有1和8，也有2,5，6,9，那么它就是好数，在判断
                //2,5,6,9是否存在的if条件中将flag置为true了
            }
            if (flag)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
