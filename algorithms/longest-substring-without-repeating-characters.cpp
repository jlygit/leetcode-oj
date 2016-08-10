class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        int max=0,start=0,end=0;
        vector<int> hash_table(256,-1);
        while(end<s.size()) {
            if(hash_table[hash_fun(s[end])]<0)  hash_table[hash_fun(s[end])]=end;  // 记录位置
            else {
                // 已经存在了分两种情况 第一种是在start之后 就是有效 第一种是在start之前就是 无效
                if(hash_table[hash_fun(s[end])]>=start) {
                    // 找到重复的了开始重置最大值
                    if(max<end-start) max=end-start;
                    start=hash_table[hash_fun(s[end])]+1;   // 更新起始索引
                }
                hash_table[hash_fun(s[end])]=end;  //更新最近的索引
            }
            ++end;
        }
        return max>end-start?max:end-start;
    }
    int hash_fun(char c){
        return static_cast<int>(c);
    }
};