class Solution {
public:
	int toint(string s) {  //将字符串转换为整数
		int d=0;
		int i=0;
		while(s[i]!=’\0′) {
		   d=d*10+(s[i++]-’0′);      // 转化
		}
		return d;
	}
	int compareVersion(string version1, string version2) {
		int v1,v2;
		int v1pointpos=version1.find(‘.’),v2pointpos=version2.find(‘.’);
		v1=toint(v1pointpos!=version1.npos ? version1.substr(0,v1pointpos-0) : version1);
		v2=toint(v2pointpos!=version2.npos ? version2.substr(0,v2pointpos-0) : version2);
		if(v1==v2&&(v1pointpos!=version1.npos||v2pointpos!=version2.npos)) {  //调用自己进行递归处理
		   version1=v1pointpos!=version1.npos ? version1.substr(v1pointpos+1,version1.size()-1-v1pointpos) : “0″;
		   version2=v2pointpos!=version2.npos ? version2.substr(v2pointpos+1,version2.size()-1-v2pointpos) : “0″;
		   return compareVersion(version1,version2);
		} else
		   return v1>v2 ? 1 : v1<v2 ? -1 : 0;
	}
};
