

 class Solution
 {
 public:
     bool isScramble(string s1, string s2)
     {
         if(s1.size() == 0)
             return true;
         // dp[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为Scramble String
         vector<vector<vector<bool> > > dp(s1.size(), 
             vector<vector<bool> >(s2.size(), 
             vector<bool>(s1.size() + 1, false)));
         for(int i = 0; i < s1.size(); ++ i)
             for(int j = 0; j < s2.size(); ++ j)
                 dp[i][j][1] = s1[i] == s2[j];
         
         for(int len = 2; len <= s1.size(); ++ len)
             for(int i = 0; i < s1.size() - len + 1; ++ i)
                 for(int j = 0; j < s2.size() - len + 1; ++ j)
                     for(int k = 1; k < len; ++ k)
                         dp[i][j][len] = dp[i][j][len] || 
                                         dp[i][j][k] && dp[i + k][j + k][len - k] || 
                                         dp[i][j + len - k][k] && dp[i + k][j][len - k];
         
         return dp[0][0][s1.size()];
     }
 };

