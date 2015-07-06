class Solution {  
public:  
	int maximumGap(vector<int> &num) {  
		if(num.size()<2) return 0;  
		sort(num.begin(),num.end());  
		int diff=num[1]-num[0];  
		for(int i=2;i<num.size();i++)  
			diff=max(diff,num[i]-num[i-1]);  
		return diff;  
	}  
};  

