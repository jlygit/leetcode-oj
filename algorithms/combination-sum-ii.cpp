class Solution {
public:
	// level代表当前树的层  从0开始  temp一个有效结果缓存  result 所有结果缓存 
    void sum_backtrace(vector<int>& candidates,int target,int level,vector<int>& temp,vector<vector<int>>& result) {
        if(target==0)   //停止条件
            result.push_back(temp);
        else {
        	// 找到合适子树进行回溯
	        for(int i=level;i<candidates.size()&&candidates[i]<=target;++i) {
	        	if(i!=level&&candidates[i]==candidates[i-1]) continue; // 控制不重复 
	            temp.push_back(candidates[i]);
	            sum_backtrace(candidates,target-candidates[i],i+1,temp,result);  // 下一层
	            temp.pop_back();
	        }
		}
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int>temp;
        sum_backtrace(candidates,target,0,temp,result);
        return result;
    }
};