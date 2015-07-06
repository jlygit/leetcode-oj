class Solution {
public:
	int findMin(vector<int> &num) {
		int left=0,right=num.size()-1;
		while(left<=right) {
			int mid=(left+right)/2;
			int lmid=mid==0 ? numeric_limits<int>::max() : num[mid-1];    //找到中间元素的左边元素
			int rmid=mid==num.size()-1 ? numeric_limits<int>::max() : num[mid+1];   //找到中间元素的右边元素
			int mmid=num[mid];
			if(mmid<=lmid&&mmid<=rmid)    return mmid;   //返回找到最小解
			if(mmid>=num[0]) left=mid+1;    // 折半 取右半
			else right=mid-1;            // 折半   取左半
		}
		return num[0];  //没在中间找到最小  即返回最左边最小的
	}
};

class Solution {
public:
	int findMin(vector<int> &num) {
		for(int i=1;i<num.size();i++)
			if(num[i]<num[i-1]) return num[i];
		return num[0];  //没在中间找到最小  即返回最左边最小的
	}
};

