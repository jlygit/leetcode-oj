class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1) return false;
        int i=0,j1=0,j2=0,i1=0,i2=0;
        while(j1<matrix[0].size()&&matrix[0][j1]<=target) ++j1;  // 找到右边界
        while(j2<matrix.size()&&matrix[j2][0]<=target) ++j2;  // 找到下边界
        while(i1<matrix.size()&&j1>0&&matrix[i1][j1-1]<target) ++i1;
        while(i2<matrix[0].size()&&j2>0&&matrix[j2-1][i2]<target) ++i2;
        for(;i1<j2;++i1) 
            for(i=i2;i<j1;++i)
                if(matrix[i1][i]==target) return true;
        return false;
    }
};