class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //return increasing(nums,0,nums.size()-1);
        if(nums.size()<3) return false;
        for(int i=1;i<nums.size()-1;++i) {
            if((*find_if(nums.begin(),nums.begin()+i,bind2nd(less<int>(),nums[i])))!=nums[i]&&find_if(nums.begin()+i+1,nums.end(),bind2nd(greater<int>(),nums[i]))!=nums.end())
            return true;
        }
        return false;
    }
};