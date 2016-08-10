class Solution {
public:
    bool isvalid(string s) {
        int count=0;
        for(int i=0;i<s.size();++i)
            if(s[i]=='(') ++count;
            else if(s[i]==')')
            {
                if(count==0) return false;
                --count;
            }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        // 使用queue bfs搜索  BFS遍历解空间树。层次依次为删除0个元素，1个元素，2个元素。。。
        unordered_map<string,int> visited;  // 标记分割后的字符串是否已经访问过
        ++visited[s];
        vector<string> result;
        queue<string> Q;
        Q.push(s);
        bool found=false;//因为要找消除最小括号数目的字符串 如果找到了 就不用继续删除括号了
        while(!Q.empty()) {
            s=Q.front();Q.pop();
            if(isvalid(s)) {
                found=true;
                result.push_back(s);
            }
            if(found) continue;
            // 下面是还没有找打的那么就消除某个括号 进行宽度优先访问
            for(int i=0;i<s.size();++i) {
                if(s[i]!='('&&s[i]!=')') continue;
                string temp=s.substr(0,i)+s.substr(i+1);
                if(visited.find(temp)==visited.end())  // 还没有加入访问队列的
                {
                    Q.push(temp);  // 加入待访问的队列中
                    ++visited[temp];
                }
            }
        }
        /* dfs访问
        vector<string> result;
        string path;
        dfs(s,0,path,0,0,result);*/
        return result;
    }
    void dfs(const string& s,int index, string& path,int lnum,int rnum, vector<string>& result) {
        //index为当前访问的层，也就是s的索引  path为当前访问的s结果  lnum为path中(的个数  rnum为path)的个数  
        if(rnum>lnum) return;  // 剪枝
        if(index==s.size()) {  // 最后一层  
            if(lnum==rnum&&(result.empty()||result[0].size()==path.size())) // 对当前结果长度最大的筛选  更小的不可能为解 因为要删除最小的括号
                result.push_back(path);
            return ;
        }
        if(!result.empty()&&path.size()+s.size()-index<result[0].size()) return;  // 剪枝  要找长度最大的
        
        //开始向下层访问
        char c=s[index];
        path.push_back(c);
        if(c!='('&&c!=')') {
            //其他字符
            dfs(s,index+1,path,lnum,rnum,result);
        } else if(c=='(') {
            // 左括号那么lnum+1
            dfs(s,index+1,path,lnum+1,rnum,result);
        }else {
            // 右括号那么rnum+1
            dfs(s,index+1,path,lnum,rnum+1,result);
        }
        
        // 回溯到上层
        path.pop_back();
        if(c=='('||c==')')  // 只有括号才回溯了
        {
            // 括号 则跳过紧接着的当前括号
            while(s[index]==c) ++index;
            dfs(s,index,path,lnum,rnum,result);
        }
    }
};