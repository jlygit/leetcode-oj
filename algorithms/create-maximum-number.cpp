class Solution {
public:
    bool compare(const vector<int>& v1,const vector<int>& v2) {// 231  213
        if(v2.size()<1) return true;
        int i=0;
        while(i<v1.size()&&v1[i]==v2[i]) ++i; // 跳过所有相等的元素  找到第一个不相等的元素
        if(i==v1.size()) return false;  // 相等  返回不大于
        if(v1[i]<v2[i]) return false;
        else return true;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0||k>nums1.size()+nums2.size()) return vector<int>();
        vector<int> result;
        int i=0;
        while(i<=k) {
            int j=k-i;
            // nums1取出i个数字  nums2取出j个数字一共就是k个数字了  然后merge就行了
            vector<int> s1,s2;  // 两个向量模拟栈 
            if(i>0&&nums1.size()>=i) {
                //从nums1入栈  i个 贪心策略
                int n=0;  //9，1，9，8，3，2，需要入4个  6  9 9 8 
                while(n<nums1.size()) {
                    if(s1.size()+nums1.size()-n==i)  // 如果栈中的大小和nums1剩余的大小和==i  那么就全部入栈吧  没得选了
                    {
                        while(n<nums1.size()) s1.push_back(nums1[n++]);
                        break;
                    }
                    if(s1.empty()||s1.back()>=nums1[n]) s1.push_back(nums1[n++]); 
                    else s1.pop_back();
                }
                while(s1.size()>i) s1.pop_back();  // 将多余的出栈
                //cout<<"s1:";copy(s1.begin(),s1.end(),ostream_iterator<int>(cout," "));cout<<endl;
            }
            if(j>0&&nums2.size()>=j) {
                //从nums1入栈  i个 贪心策略
                int n=0;  //9，1，2,5，8，3，需要入5个  6  9 9 8 
                while(n<nums2.size()) {
                    if(s2.size()+nums2.size()-n==j)  // 如果栈中的大小和nums1剩余的大小和==i  那么就全部入栈吧  没得选了
                    {
                        while(n<nums2.size()) s2.push_back(nums2[n++]);
                        
                        break;
                    }
                    if(s2.empty()||s2.back()>=nums2[n]) s2.push_back(nums2[n++]); 
                    else s2.pop_back();
                }
                while(s2.size()>j) s2.pop_back();  // 将多余的出栈
            }
            if(s1.size()+s2.size()==k) {
                // 有效的组合  就开始merge了
                vector<int> temp;
                int n1=0,n2=0;
                while(s1.size()&&s2.size()) {
                    if(s1<s2) 
                    {
                        temp.push_back(s2[0]);
                        s2.erase(s2.begin());
                    }
                	else 
                    {
                        temp.push_back(s1[0]);
                        s1.erase(s1.begin());
                    }
                }
                while(s1.size()) {
                        temp.push_back(s1[0]);
                        s1.erase(s1.begin());
                    }
                while(s2.size())  {
                        temp.push_back(s2[0]);
                        s2.erase(s2.begin());
                    }
                //开始跟之前的结果比较 保留最大的了
                if(temp>result) result=temp;
            }
            ++i;
        }
        return result;
    }
};