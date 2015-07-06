class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i=0;
		int j=i+1;
		while(j<n) {  // 基本思想：i之前的已经是无重复元素序列  j之后寻找无重复值加入i之前序列
			while(j!=n&&A[j]==A[i]) j++;  // 找到第一个不等于A[i]的后续元素
			if(j!=n)
				A[++i]=A[j++];  // 加入无序序列
		}
		return n>0 ? i+1 : 0;
	}
};

