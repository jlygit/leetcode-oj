class MedianFinder {
public:
    struct mylist {  // 可以用multiset实现 用一个迭代器指向中间元素 采用++  -- 进行增量  或用两个堆priority_queue实现一大大堆一个小堆
      int val;
      mylist* next;
      mylist(int val):val(val),next(NULL){}
    };
    mylist *head;
    mylist *m1,*m2;  // 指向中间节点
    MedianFinder():head(NULL),m1(NULL),m2(NULL) {
        if(!head) head=new mylist(0); //头结点  不用管
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if(!m1) {  // 链表为空
            m1=new mylist(num);  //一个中间节点
            head->next=m1;
        } else if(m2) {   // 两个中间节点时
            // 有两个中间节点的时候 比较 分三种情况
            if(m1->val<=num&&m2->val>=num) {
                // 插入中间
                mylist* temp=new mylist(num); // 开辟内存
                temp->next=m2;
                m1->next=temp;
                m2=NULL;m1=temp;
            } else if(m1->val>num) {
                // 在左边插入
                mylist* cur=head->next,*pre=head;  // 开始遍历节点
                while(cur->val<num)  //找到第一个大于num的节点
                {
                    pre=cur;
                    cur=cur->next; 
                }
                mylist* temp=new mylist(num);
                temp->next=cur;
                pre->next=temp;
                m2=NULL;  //现在只有m1为中间节点
            }else {
                // 在右边插入
                mylist* cur=m2->next,*pre=m2;
                while(cur&&cur->val<num) {
                    pre=cur;
                    cur=cur->next; 
                }
                mylist* temp=new mylist(num);
                temp->next=cur;
                pre->next=temp;
                m1=m2;
                m2=NULL;
            }
        } else {
            // 只有一个中间节点的时候
            if(m1->val>num) {
                // 在左边插入
                mylist* cur=head->next,*pre=head;  // 开始遍历节点
                while(cur->val<num)  //找到第一个大于num的节点
                {
                    pre=cur;
                    cur=cur->next; 
                }
                mylist* temp=new mylist(num);
                temp->next=cur;
                pre->next=temp;
                while(temp->next!=m1) temp=temp->next;
                m1=temp;
                m2=m1->next;
            }else {
                // 在右边插入
                mylist* cur=m1->next,*pre=m1;
                while(cur&&cur->val<num) {
                    pre=cur;
                    cur=cur->next; 
                }
                mylist* temp=new mylist(num);
                temp->next=cur;
                pre->next=temp;
                m2=m1->next;
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(!m1&&!m2) return 0;
        else if(!m2) return m1->val;
        else return static_cast<double>((m1->val+m2->val))/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();