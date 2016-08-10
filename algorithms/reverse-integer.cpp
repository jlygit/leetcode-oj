class Solution {
public:
    int reverse(int x) {
        //处理特殊情况
        if(abs(x)<10) return x;
        int flag=1;
        if(x<0)   //处理负数
            flag=-1;
        x*=flag;
        int temp=0,t;
        while(x){
            t=x%10;
            temp=temp*10+t;
            x/=10;
        }
        if(temp%10!=t) return 0;
        return temp*flag;
    }
};