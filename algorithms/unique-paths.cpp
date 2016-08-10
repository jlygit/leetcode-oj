class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<2||n<2) return 1;
        int temp[m][n],i,j;
        for(i=0;i<m;++i) temp[i][0]=1;
        for(j=0;j<n;++j) temp[0][j]=1;
        for(i=1;i<m;++i)
            for(j=1;j<n;++j) 
                temp[i][j]=temp[i][j-1]+temp[i-1][j];
        return temp[m-1][n-1];
    }
};