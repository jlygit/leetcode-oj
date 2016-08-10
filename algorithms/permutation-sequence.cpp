class Solution {
public:
    int getcount(int n) {
        if(n==1) return n;
        return n*getcount(n-1);
    }
    void getPermutation(int& k,string& path,string& result) {
        if(k==0) return;
        if(path.size()==1) {
            result+=path[0];return;
        }
        int n=getcount(path.size()-1);
        int skip=(k-1)/n;  //跳过部分
        k=k-skip*n;
        result+=path[skip];
        path.erase(skip,1);
        getPermutation(k,path,result);
    }
    string getPermutation(int n, int k) {
        string path(""),result("");
        for(int i=1;i<=n;++i) path+=static_cast<char>('0'+i);
        getPermutation(k,path,result);
        return result;
    }
};