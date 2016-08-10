class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int x=a^b; // 位异或实现不进位的位加
            int y=(a&b)<<1; // 位与  右移1 实现进位
            a=x,b=y;
        }
        return a;
    }
};