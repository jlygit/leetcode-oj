class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        // 动态规划
        int i=1,start=0,max=nums[0],sum=nums[0];
        while(i<nums.size()) {
            if(max<sum) max=sum;
            while(sum<0) {
                ++start;
                sum-=nums[start-1];
            } 
            sum+=nums[i];
            ++i;
        }
        return max>sum?max:sum;
    }
    // 分治法
    int maxSubArray(vector<int>& nums,int start,int end) {
        if(start==end) return nums[end];
        int i=start,j=end,m=(start+end)/2;
        int leftmax=maxSubArray(nums,start,m),rightmax=maxSubArray(nums,m+1,end);
        int sum1=0,sum2=0,max1=numeric_limits<int>::min(),max2=max1;
        for(int i=m;i>=start;--i)
        {
            sum1+=nums[i];
            if(sum1>max1) max1=sum1;
        }
        for(int i=m+1;i<=end;++i)
        {
            sum2+=nums[i];
            if(sum2>max2) max2=sum2;
        }
        return max(max(leftmax,rightmax),max1+max2);
    }
};