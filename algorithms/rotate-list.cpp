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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL) return head;
        int n=0;
        ListNode* cur=head;
        while(cur) {
            ++n;
            cur=cur->next;
        }
        k%=n;
        ListNode* fast=head,*slow=head;
        while(k--) fast=fast->next;
        while(fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        // 此时slow指向需要旋转节点的上一个节点 fast指向最后一个节点
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};