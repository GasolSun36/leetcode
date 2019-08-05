/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur;
        ListNode* pre;
        ListNode* dummy=new ListNode(0);//设立头结点
        dummy->next=head;
        pre=dummy;//令pre从头结点开始（防止从第一个结点开始反转的例子）       
        for (int i = 0; i <m-1; i++)
        {
            pre=pre->next;//找到要反转结点的前面的结点
        }
        cur=pre->next;//cur为第一个要反转的结点
        /*
        思路是将反转开始的第一个点之后的所有点依次插入到反转开始的第一个点之前的点的next（比如12345，cur为2，temp就是3，那就是3要插入到1的next，2向后移一位，2之后的点就是4，再将4移到1的next，以此类推）
        1 -> 2 -> 3 -> 4 -> 5 -> NULL
        1 -> 3 -> 2 -> 4 -> 5 -> NULL
        1 -> 4 -> 3 -> 2 -> 5 -> NULL
        注意的是，在此期间pre没有动一直是刚开始反转结点的前面的结点，而cur节点也一直没有变，变的是cur后面的节点，因为每次都是cur后面的结点向前插入，而cur不断向后移（本例中pre一直是1，cur一直是2）
         */
        while (m<n)
        {
            ListNode* temp=cur->next;//令temp为cur的后一个即要插入的点
            cur->next=temp->next;//令cur连接要插入点的后面的点，因为插入的点要到前面去了，需要将链表连起来
            temp->next=pre->next;//后两步就是将temp节点插入到pre后面的操作，先将temp的next指向pre的next
            pre->next=temp;//然后将pre的next指向temp
            n--;//循环进行m-n次
        }
        return dummy->next;//返回第一个结点即头结点的下一个结点         
    }
};

