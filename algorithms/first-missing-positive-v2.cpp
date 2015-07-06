class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for(int i=0;i<n;i++)  // 使用A[i]存储A中出现对应的的正整数i+1
			if(A[i]>0&&A[i]<=n&&A[i]!=A[A[i]-1]) {
				swap(A[i],A[A[i]-1]);
				i–;    // 交换之后重新处理交换的新值
			}
		for(int i=0; i<n; i++)   //找打第一个不符合的位置 即为缺失的正整数
			if(A[i]!=i+1) return i+1;
		return n+1;
	}
};

