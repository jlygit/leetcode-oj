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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;  // 特殊情况记得检查
        ListNode* prev=head,*next=prev->next;
        while(next){  // 循环记得向前
           if(next->val==prev->val) {  
               //找到相等的节点 则删除
               prev->next=next->next;
               next=prev->next;
           } else
           {
               prev=next;
               next=next->next;
           }
        }
        
        return head;
    }
};