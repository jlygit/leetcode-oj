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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        ListNode *slow=head,*fast=head,*cross=head;
        while(fast->next&&fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                //相遇  这时候 相遇点到交叉点  和  head到交叉点的距离一定是相等的
                while(cross!=slow) 
                    cross=cross->next,slow=slow->next;
                return cross;  // 返回交叉点
            }
        }
        return NULL;
    }
};