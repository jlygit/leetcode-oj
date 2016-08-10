class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1||matrix[0].size()<1) return false;
        int row=0;
        while(row<matrix.size()) {
            if(matrix[row][matrix[row].size()-1]>=target)  break;  //找到所在行
            ++row;
        }
        if(row<matrix.size()) {
            int i=0,j=matrix[row].size()-1,m;
            while(i<=j) {
                m=(i+j)/2;
                if(matrix[row][m]==target) return true;
                if(matrix[row][m]<target) i=m+1;
                else j=m-1;
            }
        }
        return false;
    }
};