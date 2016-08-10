class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n==0) return 0;
        int res=0;
        unsigned int mask=0x80000000;  //32位 最高位为1
        //下面找出n的最高为1的位
        while(mask&n==0) mask>>=1;  // 只要为0 就 右移
        while(mask) {
            if((mask&m)==(mask&n)) res|=(mask&m);  // 相同的位 则为结果
            else return res;
            mask>>=1;
        }
        return res;
    }
};