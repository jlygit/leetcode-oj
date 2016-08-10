class Solution {
public:
    bool isValidSerialization(string preorder) {
        while(true) {
            int i=preorder.find(",#,#");
            if(i==preorder.npos)
                break;
            int j=i-1;
            while(j>=0&&preorder[j]!=',') --j;
            if(j==0) {
                // 首
                string temp=preorder.substr(0,i-1);
                if(temp.size()>1||temp>=string("0")&&temp<=string("9")) preorder.erase(0,i+2);
                else break;
            } else {
                string temp=preorder.substr(j+1,i-1-j);
                if(temp.size()>1||temp>=string("0")&&temp<=string("9")) preorder.erase(j+1,i+2-j);
                else break;
            }
        }
        return preorder==string("#");
    }
};