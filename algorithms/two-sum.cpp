class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int start=0,end;
        while(start<nums.size()){
            end=start+1;
            while(end<nums.size()){
                if(target==nums[start]+nums[end]){
                    result.push_back(start);
                    result.push_back(end);
                    return result;
                }
                ++end;
            }
            ++start;
        }
        return result;
    }
};