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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL||m==n) return head;
        ListNode *pre=NULL,*cur,*next;
        cur=head;
        n-=m;
        while(--m) {
            pre=cur;cur=cur->next;  //p1为前驱 p2为第m个节点
        }
        while(n--) { 
            //将next 独立出来
            next=cur->next;  
            cur->next=next->next;  
            
            // 在m位置插入next
            if(pre)
            {
                next->next=pre->next;  
                pre->next=next;
            } else {
                //头结点处理
                next->next=head;
                head=next;
            }
        }
        return head;
    }
};