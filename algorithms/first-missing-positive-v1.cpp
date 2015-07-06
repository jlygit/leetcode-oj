class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		int tag[n+1];
		for(int i=1;i<=n;i++) tag[i]=0;
		for(int i=0;i<n;i++)
			if(A[i]>0) tag[A[i]]++;
		for(int i=1;i<=n;i++)
			if(tag[i]==0) return i;
		return n+1;
	}
};

