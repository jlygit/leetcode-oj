class Solution {
public:
    int numSquares(int n) {//动态规划
        if(n<1) return 0;
        vector<int> temp;
        temp.push_back(1);
        int result[n+1];
        result[0]=0;
        for(int i=1;i<=n;++i) {
            int k=i;  // 当前
            if(k>=temp.back()) temp.push_back(pow(temp.size()+1,2)); // 下届
            int min=k;
            for(int j=temp.size()-2;j>=0;--j) 
                if(min>result[k-temp[j]]+1) min=result[k-temp[j]]+1;
            result[i]=min;
        }
        return result[n];
    }
};