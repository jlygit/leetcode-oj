class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j,k=0;
        for(i=0;i<nums.size()-k;) 
            if(nums[i]==0)
            {
                for(j=i+1;j<nums.size()-k;++j)
                    swap(nums[j-1],nums[j]);
                ++k;
            }else ++i;
    }
};