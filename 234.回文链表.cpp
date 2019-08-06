/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：使用快慢指针，快指针走两步，慢指针走一步，然后快指针到结尾的null时慢指针正好到中点
然后从中点到结尾进行反转，然后再从头指针往后，结尾指针往前进行判断是否相等（详情见ipad）
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;//定义快慢指针
        ListNode* fast=head;
        ListNode* pre=NULL;//定义反转链表的前结点
        if (head==NULL||head->next==NULL){//讨论如果链表为空或链表只有一个结点（快慢结点算法针对链表长度>=2，因为链表长度<2时要进行判断）
            return true;
        }       
        while (fast&&slow)//进行快慢指针找中点
        {
            fast->next==NULL?fast=fast->next:fast=fast->next->next;//如果链表个数为奇数，则fast->next可能为null，所以要进行判断
            slow=slow->next;
        }
        //此时slow位于中点，从slow开始到结尾进行反转
        while (slow!=NULL)//反转链表之后，slow为null，pre为链表的最后一个结点
        {//反转的操作不详细说了
            ListNode* temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;
        }
        while (head&&pre)//head为头指针，pre为指向链表最后一个结点的指针
        {
            if (head->val!=pre->val){
                return false;
            }
            head=head->next;
            pre=pre->next;//当pre走到中点时，pre->next为null，会跳出循环，（奇数时不考虑中点值）           
        }
        return true;       
    }
};

