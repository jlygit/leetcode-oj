class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int result=1,flag=0;   //0代表只出现一次
        
        for(int i=1;i<nums.size();++i) {
            if(nums[i]==nums[i-1]&&!flag) {  // 如果相等 并且只出现一次 那么就改状态
                flag=1;
                ++result;
            }
            else if(nums[i]!=nums[i-1]) {
                ++result;
                flag=0;
            } else if(flag){
                nums.erase(find(nums.begin(),nums.end(),nums[i]));
                --i;
            }
        }
        return result;
    }
};