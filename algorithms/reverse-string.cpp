class Solution {
public:
    string reverseString(string s) {
        // 特殊情况
        //if(s.size()<2) return s;
        int i=0,j=s.size()-1;
        while(i<j) {
            swap(s[i++],s[j--]);
        }
        return s;
    }
};