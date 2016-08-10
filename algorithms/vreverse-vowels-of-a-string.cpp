class Solution {
public:
    bool isvowels(char c) {
        return c=='a'||c=='A'||c=='e'||c=='E'||c=='o'||c=='O'||c=='u'||c=='U'||c=='i'||c=='I';
    }
    string reverseVowels(string s) {
       int a[26];
       memset(a,0,sizeof(a));
       a['a'-'a']=1;a['e'-'a']=1;a['i'-'a']=1;a['o'-'a']=1;a['u'-'a']=1;
       int i=0,j=s.size()-1;
       while(i<j) {
           while(!isvowels(s[i])&&i<j) ++i;
           while(!isvowels(s[j])&&i<j) --j;
           if(i<j) {
               swap(s[i],s[j]);
               ++i;--j;
           }
       }
       return s;
    }
};