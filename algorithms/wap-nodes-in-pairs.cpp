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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *p1=head,*p2=head->next;
        p1->next=p2->next;p2->next=p1;head=p2;
        while(p1->next&&p1->next->next) {
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p2->next->next;
            p1->next->next=p2;
            p1=p2;
        }
        return head;
    }
};