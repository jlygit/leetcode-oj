class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<1) return vector<int>(1,0);
        vector<int> result(pow(2,n));
        result[0]=0,result[1]=1;
        int i=1,index=2;
        while(i<n) {
            // 构造格雷码
            int off=1<<i;
            for(int j=0;j<index;++j)
                result[index+j]=result[index-j-1]+off;
            index*=2;
            ++i;
        }
        return result;
    }
};