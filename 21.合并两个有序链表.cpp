/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l=new ListNode(0);//新建一个带头结点的链表头指针
        ListNode* head=l;//用head指向他,head用于改变，l用于返回(return)
        while (l1!=NULL&&l2!=NULL)//依次遍历l1和l2将小的元素添加到l中
        {
            if (l1->val<=l2->val){
                head->next=new ListNode(l1->val);
                head=head->next;
                l1=l1->next;
                continue;
            }
            else {
                head->next=new ListNode(l2->val);
                head=head->next;
                l2=l2->next;
                continue;
            }            
        }
        //出来时判断哪个链表是遍历完的，如果都遍历完则返回l，否则直接将没有遍历完的链表添加到l之后
        if (l1!=NULL){
            while (l1)
            {
                head->next=new ListNode(l1->val);
                head=head->next;
                l1=l1->next;
            }            
        }
        if (l2!=NULL){
            while (l2)
            {
                head->next=new ListNode(l2->val);
                head=head->next;
                l2=l2->next;
            }            
        }
        return l->next;     
    }
};

