class Solution {
public:
    int numDecodings(string s) {
        if(s.size()<1||s[0]=='0') return 0;
        int result[s.size()+1];
        result[0]=1;result[1]=1;
        int i=1;
        while(++i<=s.size()) {  //i表示第i个字符
            // 特殊情况
            if(s[i-1]=='0') {  //X0形式  只能是10  20 有效 
                if(s[i-2]!='2'&&s[i-2]!='1') return 0;
                else result[i]=result[i-2];  //10 20 就是表示固定编码了 不能分 所以分法跟上上个相同 
            } else {  // 一般情况
                result[i]=result[i-1];
                // 不是数字0 则要判断之前是不是是数字
                if(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<'7') result[i]+=result[i-2];  // 0X形式 所以分法跟上一个相同
            }
        }
       return result[s.size()];
    }
};