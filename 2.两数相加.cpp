/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0);//创建一个初始val为0的头结点
        ListNode *cursor =root;//cursor为链表尾结点，初始等于头结点
        int flag=0;//flag为进位数
        while (l1||l2||flag)
        {
            int sum=0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;     
            }
            sum+=flag;
            flag=0;
            if(sum>=10){//如果sum大于10，则需要进位
                sum-=10;
                flag++;
            }
            cursor->next=new ListNode(sum);//让尾指针为新建的结点，结点的值为sum的个位数
            cursor=cursor->next;//尾指针继续指向尾结点
        }  
        return root->next;//注意，root为头结点，所以返回root->next
    }
};

