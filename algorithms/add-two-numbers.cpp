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
        ListNode* result=new ListNode(0),*p=result;   // 注意链表需要一个头部  技巧所在
        int n;
        while(l1!=NULL&&l2!=NULL){
            p->next=new ListNode((l1->val+l2->val)%10);
            p=p->next;
            n=(l1->val+l2->val)/10;
            if(n>0){
                if(l1->next) ++(l1->next->val);
                else
                     l1->next=new ListNode(1);
            }
            l1=l1->next;l2=l2->next;
        }
        while(l1!=NULL){
            n=l1->val/10;
            p->next=new ListNode(l1->val%10);
            p=p->next;
            if(n>0){
                if(l1->next) ++(l1->next->val);
                else
                     l1->next=new ListNode(1);
            }
            l1=l1->next;
        }
        while(l2!=NULL){
            n=l2->val/10;
            p->next=new ListNode(l2->val%10);
            p=p->next;
            if(n>0){
                if(l2->next) ++(l2->next->val);
                else
                     l2->next=new ListNode(1);
            }
            l2=l2->next;
        }
        return result->next;
    }
};