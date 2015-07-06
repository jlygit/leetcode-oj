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
		int v1pos,v2pos;
		while(true) {  // 递归处理
			v1pos=version1.find(‘.’);
			v2pos=version2.find(‘.’);
			v1=toint(v1pos!=version1.npos ? version1.substr(0,v1pos-0) : version1);
			v2=toint(v2pos!=version2.npos ? version2.substr(0,v2pos-0) : version2);
			if((v1==v2)&&(v1pos!=version1.npos||v2pos!=version2.npos)){   // 如果还存在.号  递归处理
				version1=v1pos!=version1.npos ? version1.substr(v1pos+1,version1.size()-1-v1pos) : “0″;
				version2=v2pos!=version2.npos ? version2.substr(v2pos+1,version2.size()-1-v2pos) : “0″;
			} else
				return v1>v2 ? 1 : v1<v2 ? -1 : 0;
		}
	}
};

