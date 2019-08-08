/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
/*
我之前的思路：在最后获取最小值一步的时候使用一个栈，还有一个min变量储存遍历S时的最小值，
遍历S造成不可逆的伤害以后将S弹出的元素放入另一个栈中，然后最后再由另一个栈返回到原栈
最后一个测试点未通过超时了
借鉴思路：使用全局辅助栈temp，当S.push时,只有当temp为空或者temp的栈顶元素比x要大时，
将x放入temp中，也就是temp中保留了当前相对小的元素
 */
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> S;
    stack<int> temp; //辅助栈
    MinStack()
    {
    }

    void push(int x)
    {
        S.push(x);
        if (temp.empty())
        {
            temp.push(x);
        }
        else
        {
            if (x <= temp.top())
            {
                temp.push(x);
            }
        }
    }

    void pop()
    {
        if (temp.top()==S.top())
        {
            temp.pop();
        }
        
        S.pop();
    }

    int top()
    {
        return S.top();
    }

    int getMin()
    {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
