class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int sLen = s.length(), pLen = p.length();
        int match[pLen+1][sLen+1];
        memset(match, 0, sizeof(int)*(pLen+1)*(sLen+1));
        match[0][0] = 1;
        for(int i = 2; i <= pLen; i += 2)
            if(p[i-1] == '*') match[i][0] = 1; else break;
        for(int i = 1; i <= pLen; ++i)
        {
            if(p[i-1] == '*')
                for(int j = 1; j <= sLen; ++j)
                    match[i][j] = match[i-2][j] || ((p[i-2]=='.' || p[i-2]==s[j-1]) && match[i][j-1]);
            else
                for(int j = 1; j <= sLen; ++j)
                    match[i][j] = match[i-1][j-1] && (p[i-1]=='.' || p[i-1]==s[j-1]);
        }
        return match[pLen][sLen];
    }
};