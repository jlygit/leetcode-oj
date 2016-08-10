class Solution {
public:
//读字符的过程中，把字符存到stack里，当发现stack之前存的字符中比当前字符大而且频率还大于0就可以把那个字符pop出去。
//类似这种题目都可以用stack解决。基本思想就是在一定的限制条件下pop出比当前选择差的元素。
    string removeDuplicateLetters(string s) {
        // 哈希表
        if(s.size()<1) return s;
        int count[26]={0},visited[26]={0};
        for(int i=0;i<s.size();++i) ++count[s[i]-'a'];  // 统计每个字母出现的次数
        stack<char> S; 
        for(int i=0;i<s.size();++i) {
            --count[s[i]-'a'];
            if(visited[s[i]-'a']) continue;
            // pop出stack当中比当前字符大但后面还存在的的字符
            while (!S.empty()&&S.top()>s[i]&&count[S.top()-'a']>0) {
                visited[S.top()-'a'] = false;
                S.pop();
            }
            // 访问当前字符
            S.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        // 构造结果
        s="";
        while(!S.empty()) {
            s+=S.top();
            S.pop();
        }
        reverse(s.begin(),s.end()); // 逆转
        return s;
    }
};