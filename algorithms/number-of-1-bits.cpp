class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n<2) return static_cast<int>(n);
        int sum=0;
        while(n) {
            sum+=(n&1);
            n>>=1;
        }
        return sum;
    }
};