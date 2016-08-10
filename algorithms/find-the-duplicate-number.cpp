class Solution {
public:
    void sort1(vector<int>& nums, int i,int j)
    {
        if(i>=j) return ;
        int t=nums[i],start=i,end=j;  // 坑
        while(start<end) {
            while(nums[end]>=t&&end>start) --end;
            if(end>start) nums[start]=nums[end];  // 换坑
            while(nums[start]<t&&end>start) ++start;
            if(end>start) nums[end]=nums[start];
        }
        nums[start]=t;  // 中间量
        sort1(nums,i,start-1);sort1(nums,start+1,j);
    }
    int findDuplicate(vector<int>& nums) {
        sort1(nums,0,nums.size()-1);
        for(int i=0;i<nums.size()-1;++i)
            if(nums[i]==nums[i+1])
                return nums[i];
        return 0;
    }
};