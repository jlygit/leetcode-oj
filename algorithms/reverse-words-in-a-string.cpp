class Solution {
public:
	void swap(char* c1,char* c2) {
		char c;
		c=*c1;
		*c1=*c2;
		*c2=c;
	}
	void reverse(string &s,int i,int j) {  //反转字符串s的i到j之间的子串 
		  while(i<j)  swap(&s[i++],&s[j--]);
	}
	void reverseWords(string &s) {
			while(isspace(s[0]))    //如果前导空白字符 则删除
				s.erase(0,1);       //删除空白字符  删除位置0开始的1个字符
			int i=0;
			while(i<s.size()) {      // 删除中间连续空白字符  
				if(isspace(s[i])&&isspace(s[i+1]))
					 s.erase(i+1,1);
				else i++;
			}
			while(isspace(s[s.size()-1]))    //如果后导空白字符 则删除
				s.erase(s.size()-1,1);       //删除空白字符  删除位置0开始的1个字符
			reverse(s,0,s.size()-1);  //整个字符串逆转
			i=0;
			while(i<s.size()) {                //单个单词进行逆转 
				int j=i;
				while(j!=s.size()&&!isspace(s[j])) j++;    //找到单词分割点 也就是空白字符 
				reverse(s,i,j-1);
				i=j+1;
			}
	}
};

