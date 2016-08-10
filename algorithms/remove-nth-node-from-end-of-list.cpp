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
        if(!head) return head;
        ListNode *p1=head,*p2=head,*p3;
        while(p2&&--n) 
            p2=p2->next;
        if(p2&&p2->next) {https://leetcode.com/problems/merge-sorted-arrayhttps://leetcode.com/problems/move-zeroes
            while(p2->next) {
                p3=p1;
                p1=p1->next;https://leetcode.com/problems/swap-nodes-in-pairs
                p2=p2->next;
            }
            p3->next=p1->next;
            delete p1;
        } else {
            head=head->next,delete p1;
        }
        return head;
    }
};