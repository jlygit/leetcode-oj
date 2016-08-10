class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 位运算 异或 两个相同数字异或为0  0异或一个数字=这个数字
        int result=0,i;
        for(i=0;i<nums.size();++i) result^=nums[i]; // nums列表是缺少一个整数的
        for(i=0;i<=nums.size();++i) result^=i;  // i列表是完整的整数列表
        return result;
    }
};