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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* pre,*cur=head;
        while(cur) {//遍历链表
            if(cur->val==val) {
                // 找到需要删除的地方了
                if(cur==head)  // 如果是头结点 
                {
                    head=head->next;
                    delete cur;
                    cur=head;
                } else {
                    // 不是头结点 那么pre就是有效的了
                    pre->next=cur->next;
                    delete cur;
                    cur=pre->next;
                }
            } else {  // 没好到  就下一个了
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};