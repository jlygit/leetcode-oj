class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        string result("");
        int index=0,max=-1,t;
        while(index<s.size()){
                t=1;
                while(index-t>=0&&index+t-1<s.size()&&s[index-t]==s[index+t-1]) ++t;  //找出所有回文
                if((t-1)*2>result.size()) result=s.substr(index-t+1,(t-1)*2); //更新最大回文
                
                t=1;
                while(index-t>=0&&index+t<s.size()&&s[index-t]==s[index+t]) ++t;  //找出所有回文
                if((t-1)*2+1>result.size()) result=s.substr(index-t+1,(t-1)*2+1); //更新最大回文
            //遍历一次
            ++index;
        }
        return result;
    }
};