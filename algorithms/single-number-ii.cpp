class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0,count;
        for(int i=0;i<32;++i) // 对int的每位进行统计  一定回事3N  或3N+1  那么对于3N+1的求和就是所求
        {
            count=0;
            int bit=1<<i;
            for(int j=0;j<nums.size();++j)
                if(nums[j]&bit)
                    ++count;
            if(count%3) result|=bit;
        }
        return result;
    }
};