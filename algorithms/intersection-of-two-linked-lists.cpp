class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;     // 临时保存 不改变原来链表
        if(a==NULL||b==NULL) return NULL;
        int an=1,bn=1;                  // 保存链表长度
        while(a->next) {                // 计算headA的长度
            an++;
            a=a->next;
        }
        while(b->next) {                // 计算headB的长度
            bn++;
            b=b->next;
        }
        if(a!=b) return NULL;           // 没有交叉点 如果有交叉点  最后一个元素一定是共同的
        a=headA;
        b=headB;
        int dif=an>bn ? an-bn : bn-an;  // 计算长度差值
        if(an>bn) {                     // 跳过差值 使得两个链表剩余部分长度相等
            while(dif–) a=a->next;
        } else {
            while(dif–) b=b->next;
        }
        while(a!=b) {                   // 寻找交叉点
            a=a->next;
            b=b->next;
        }
        return a;
    }
};
