/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代方法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        ListNode* pre=NULL;//用pre记录当前节点（cur）的前一个结点
        if (!head||!head->next)
        {
            return head;
        }
        while (cur!=NULL)
        {
            ListNode* temp=cur->next;//用temp变量记录cur的后一个结点
            cur->next=pre;//反转链表，当前结点指向其上一个结点（之前必须将当前结点的next赋值给temp不然会丢失next）
            pre=cur;//反转当前结点成功后，为反转后续结点做准备，当前结点就变成了之前的结点pre
            cur=temp;//将当前结点赋值为下一结点进行迭代。
        }
        return pre;//跳出循环时cur指向原链表最后一项的next即null，pre就是原链表的最后一个结点即新链表的第一个结点        
    }
};
//递归方法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head||!head->next)
        {
            return head;
        }
        ListNode* p=reverseList(head->next);//将当前结点的后续反转
        head->next->next=head;//当前结点的后一结点的next指向自己
        head->next=NULL;//别忘了更新当前结点的next为空
    }
};
