class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2||s.size()<2) return s;
        vector<vector<char> > temp(numRows);
        int i=0,rows=0;
        bool flag=true;
        string result("");
        while(i<s.size()){
            temp[rows].push_back(s[i++]);
            if(flag)
                {
                    ++rows;
                    if(rows==numRows) {
                        rows-=2;
                        flag=!flag;
                    }
                }
            else
                {
                    --rows;
                    if(rows==-1) {
                        rows+=2;
                        flag=!flag;
                    }
                }
        }
        i=0;
        while(i<numRows){
            copy(temp[i].begin(),temp[i].end(),back_inserter(result));
            ++i;
        }
        return result;
    }
};