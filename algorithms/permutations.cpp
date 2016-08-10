class Solution {
public:
    void help(vector<int>& nums,vector<vector<int>>& result,int level) {
        if(level==nums.size()-1) {
            result.push_back(nums);
            return;
        }
        for(int i=level;i<nums.size();++i)  
        {
            swap(nums[level],nums[i]);
            help(nums,result,level+1);
            swap(nums[level],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<1) return vector<vector<int>>();
        vector<vector<int>> result;
        //help(nums,result,0);   // 回溯实现
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        while(next_permutation1(nums.begin(),nums.end())) result.push_back(nums);
        return result;
    }
    bool next_permutation1(vector<int>::iterator start,vector<int>::iterator end) {
        if(end-start==1) return false;
        vector<int>::iterator it=end-2;
        while(it!=start&&*it>*(it+1))  --it;  //找到第一次相邻的顺序对
        vector<int>::iterator it1=end-1;
        while(it1!=it&&*it1<*it)  --it1;  // 找到第一个逆序对
        if(it==it1) return false;
        int t=*it;
        *it=*it1;
        *it1=t;
        sort(it+1,end);
        return true;
    }
};