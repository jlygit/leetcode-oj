class Solution {
public:
    void combine(vector<vector<int>>& result,vector<int>& data,int n, int k,int level)
    {
        if(level==k) {
            vector<int> temp(data.begin(),data.end());
            result.push_back(temp);
            return ;
        }
        for(int i=level+1;i<=n;++i) {
            if(data.empty()||data.back()<i) {  //剪枝
                data.push_back(i);  // 进入下层的状态
                combine(result,data,n,k,level+1);  // 进入下层
                data.pop_back();  // 回复 返回上层
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k>n||n<1||k<1) return result;
        vector<int> data;
        combine(result,data,n,k,0);  // 从第二层开始回溯
        return result;
    }
};