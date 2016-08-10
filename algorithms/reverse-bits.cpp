class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=32;
        uint32_t result=0;
        while(i--) {
            result<<=1;
            result+=(n&0x1);
            n>>=1;
        }
        return result;
    }
};