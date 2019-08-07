/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
/*
题意：找到nums1中每个数字对应在nums2中的后续最大值（题目给的例子让人容易理解为第一个数）
实际上nums1= [1,3]和 nums2=[3,1,7]时应该结果为[7,7]
将右侧所有的大小对应关系做成哈希表，然后从nums1中查找，若有则输出，没有则输出-1
 */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int num;
        map<int, int> P;
        stack<int> S;
        for (int i = 0; i < nums1.size(); i++)
        {
            P[nums1[i]] = -1;
        }
        if (nums2.size() >= 1)//nums2的大小要比1要大，否则返回空vector
        {
            S.push(nums2[0]);
        }
        for (int i = 1; i < nums2.size(); i++)
        {
            while(!S.empty() && nums2[i] > S.top()) //如果nums2[i]>S.top(),说明找到了下一个大的元素，则向哈希表中添加数据,并且这里一定要是while，因为可能栈顶元素拿走后此时栈顶元素依旧比nums2[i]要小，则向哈希表中继续添加
            {
                num = S.top();
                S.pop();
                P[num] = nums2[i];
            }
            S.push(nums2[i]); //把当前的元素放入栈中，继续遍历
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = P[nums1[i]];//如果哈希表中有记录，则是下一个更大的元素，否则就是-1即该元素后面没有更大的元素
        }
        return nums1;
    }
};
