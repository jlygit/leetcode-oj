class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;   // 特殊情况
        if(x+y<z) return false;  // 特殊情况
        // 理论：两个瓶子能够量的水是其最大公约数的倍数
        // 求最大公约数
        int t;
        if(x>y) swap(x,y);
        while(x) {
            t=y%x;
            if(t>=x) y=t;
            else {
                y=x;x=t;
            }
        }
        // 查看z是否为最大公约数的倍数
        return z>=y&&z%y==0;
    }
};