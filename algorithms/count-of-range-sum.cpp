class Solution {
public:
    int lo,hi;
    int ret=0;
    void msort(vector<long long>& A,int x,int y,vector<long long>& T) {
        if (y-x<=1) {
            if (A[x]>=lo&&A[x]<=hi) ret++;
            return;
        }
        int mid=x+(y-x)/2;

        msort(A,x,mid,T);
        msort(A,mid,y,T);
        int p=x,q=mid,it=x;
        int j1=x,j2=x;
        for (int i=mid;i<y;i++) {
            while (j1<mid&&A[i]-A[j1]>=lo)
                j1++;
            while (j2<mid&&A[i]-A[j2]>hi)
                j2++;
            ret+=j1-j2;
        }
        while (p<mid||q<y) {
            if (q>=y||(p<mid&&A[p]<=A[q]))
                T[it++]=A[p++];
            else
                T[it++]=A[q++];
        }
        for (int i=x; i<y; i++)
            A[i]=T[i];
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size()==0) return 0;
        ret=0;
        lo=lower,hi=upper;
        vector<long long> temp(nums.size(),0);
        vector<long long> vec;
        vec.push_back(nums[0]);
        for (int i=1;i<nums.size();i++)
            vec.push_back(nums[i]+vec[i-1]);
        msort(vec,0,vec.size(),temp);
        return ret;
    }
};