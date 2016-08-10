class Solution {
public://先对数组排个序。枚举第一个数，然后设两个指针，在第一个数的后半段开始王中间收缩，if sum > target则右指针往左移， if sum < target则左指针往右移。排序O(nlogn) + 查找O(n^2) = O(n^2)
    void quicksort(vector<int>& nums,int start,int end) { // 快排
    	if(start>=end) return ;
    	int i=start,j=end,t=nums[start];  // 将基准挖出形成一个坑 
    	while(i<j) {
    		while(nums[j]>=t&&j>i) --j;  // 找到右边第一个小于基准的值 
    		if(j>i) nums[i++]=nums[j];   // 填坑   这时j位置为坑 
    		while(nums[i]<t&&i<j) ++i;  // 找到左边第一个大于分基准的值
    		if(i<j)	nums[j--]=nums[i];	// 填坑 这时i为坑 
    	}
    	nums[i]=t;   // 基准   基准左边做快排  右边做快排 
    	quicksort(nums,start,i-1);quicksort(nums,i+1,end);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        //sort(nums.begin(),nums.end());
        quicksort(nums,0,nums.size()-1);
        int i=0,j,k,sum,result;
        int min=INT_MAX;
        while(i<nums.size()){
            j=i+1;k=nums.size()-1; // 两边的指针
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<min) {
                    min=abs(sum-target);
                    result=sum;
                }
                if(sum>target) --k;
                else ++j;
            }
 
            ++i;
        }
        return result;
    }
};