class Solution {
public:
    bool ispalindrome(string s,int j) {
        int i=0;
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            ++i;--j;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.size()<1) return vector<vector<string>>();
        vector<vector<string>> result;
        for(int i=0;i<s.size();++i){
            if(ispalindrome(s,i)) // 前部分是回文
            {
                if(i==s.size()-1)  // 到最后了 
                {
                   vector<string> v;
                   v.push_back(s);
                   result.push_back(v);
                } else {
                    // 没有最后  就需要递归了
                    vector<vector<string>> temp=partition(s.substr(i+1));
                    for(int j=0;j<temp.size();++j) temp[j].insert(temp[j].begin(),s.substr(0,i+1));
                    copy(temp.begin(),temp.end(),back_inserter(result));  // 将返回加入结果中
                }
            }
        }
        return result;
    }
};