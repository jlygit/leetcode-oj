class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        int i=nums.size()-2,j;
        bool flag=false;
        while(i>=0&&!flag) {
            //从后往前检查
            j=nums.size()-1;
            while(j>i&&!flag) {
                if(nums[j]>nums[i]) {
                    swap(nums[j],nums[i]);
                    flag=true;
                    sort(nums.begin()+i+1,nums.end());
                } else 
                   --j; 
            }
            --i;
        }
        if(!flag) sort(nums.begin(),nums.end());
    }
};