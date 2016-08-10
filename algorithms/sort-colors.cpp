class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sum[3];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<nums.size();++i) ++sum[nums[i]];
        for(int i=0;i<sum[0];++i) nums[i]=0;
        for(int i=sum[0];i<sum[0]+sum[1];++i) nums[i]=1;
        for(int i=sum[0]+sum[1];i<sum[0]+sum[1]+sum[2];++i) nums[i]=2;
    }
};