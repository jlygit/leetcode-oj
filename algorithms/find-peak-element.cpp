#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int left=0;
		int right=num.size()-1;
		while(left<=right) {  // 折半查找 
			int mid=(left+right)/2;   //  取中间元素 
			long long t1=mid==0 ? LLONG_MIN : num[mid-1];  // 临时保存中间元素的左邻居的值  
			long long t2=mid==num.size()-1 ? LLONG_MIN : num[mid+1];  // 临时保存中间元素的右邻居的值 
			long long t=num[mid];            // 中间元素的值 
			if(t>t1&&t>t2) return mid;  // 符合要求返回 
			else if(t<t2) left=mid+1;   // 右半查找 
			else if(t<t1) right=mid-1;  // 左半查找 
		}
	}
};
int main()
{
  vector<int> num;
  num.push_back(1);
  num.push_back(2);
  num.push_back(3);
  num.push_back(1);
  Solution s;
  cout<<s.findPeakElement(num)<<endl;
  system(“pause”);
}

