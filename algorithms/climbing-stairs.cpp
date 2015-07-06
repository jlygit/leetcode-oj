class Solution {
public:
	int climbStairs(int n) {
		int a[n+1];   //保留各个状态
		a[0]=1;
		a[1]=1;
		for(int i=2;i<=n;i++)
			a[i]=a[i-1]+a[i-2]; // 得到新状态
		return a[n];
	}
};

class Solution {
public:
	int climbStairs(int n) {
		int t1=1,t2=1;
		for(int i=2;i<=n;i++) {
			t2=t1+t2;       // 保存最新状态t1+t2
			t1=t2-t1;       // 保存相对最新状态的上一个状态  也就是上一个t2
		}
		return t2;
	}
};

