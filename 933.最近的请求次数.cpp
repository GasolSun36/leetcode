/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */
/*
思路：就将t放入队列中，判断队列头元素是否在区间内，若不在区间内，则删除
最后返回队列的长度
 */
class RecentCounter
{
public:
    queue<int> Q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        Q.push(t);
        while (Q.front()<t-3000)
        {
            Q.pop();
        }
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
