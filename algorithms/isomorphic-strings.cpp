class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //哈希 
        if(s.size()!=t.size()) return false;
        char hashtable[256];  // 最多是256个字符
        
        // s->t的映射
        for(int i=0;i<256;++i) hashtable[i]='\0';
        for(int i=0;i<s.size();++i) {
            if(hashtable[static_cast<int>(s[i])]=='\0') // 第一次出现 则存储映射
                hashtable[static_cast<int>(s[i])]=t[i];   // 这样就可以将s[i]与t[i]映射起来了
            else if(hashtable[static_cast<int>(s[i])]!=t[i])
                return false;
        }
        
        // t->s的映射
        for(int i=0;i<256;++i) hashtable[i]='\0';
        for(int i=0;i<t.size();++i) {
            if(hashtable[static_cast<int>(t[i])]=='\0') // 第一次出现 则存储映射
                hashtable[static_cast<int>(t[i])]=s[i];   // 这样就可以将s[i]与t[i]映射起来了
            else if(hashtable[static_cast<int>(t[i])]!=s[i])
                return false;
        }
        return true;
    }
};