class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
                if(exist(board,i,j,0,word))
                    return true;
        return false;
    }
    bool exist(vector<vector<char> > &board,int i,int j,int level, string word) {
        if(level==word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||word[level]!=board[i][j])
            return false;
        board[i][j]^=128;   // 因为字母范围为0-127  所以将128跟起异或 最高位变为1  这样下次就不会被再次访问了
        bool flag=exist(board,i-1,j,level+1,word)||exist(board,i+1,j,level+1,word)||exist(board,i,j-1,level+1,word)||exist(board,i,j+1,level+1,word);
        board[i][j]^=128;   // 恢复
        return flag;
    }
};