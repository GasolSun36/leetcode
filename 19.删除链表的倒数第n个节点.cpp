/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* low=head;
        if (!head||!head->next)
        {
            return NULL;
        }
        for (int i = 0; i < n; i++)
        {
            fast=fast->next;
        }
        if (!fast)//如果链表只有一个元素删除一个元素即[1] 1的情况，!fast->next不过
        {
            return head->next;
        }
        else{
            while (fast->next)
            {
                fast=fast->next;
                low=low->next;
            }
            low->next=low->next->next;
            return head;          
        }                     
    }             
        
};

