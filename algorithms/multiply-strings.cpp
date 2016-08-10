class Solution {
public:
    void addzeor(string &s,int n) {
        if(s.size()<1) return;
        while(n--) s+='0';
    }
    string addstr(string& s1,string& s2) {
    	if(s1.size()<1) return s2;
    	if(s2.size()<1) return s1;
        reverse(s1.begin(),s1.end());reverse(s2.begin(),s2.end());// 反转尾巴对齐
        string result="";
        int i=0,flag=0,t1,t2,t;
        while(i<s1.size()&&i<s2.size()) {
           t1=static_cast<int>(s1[i]-'0'); t2=static_cast<int>(s2[i]-'0');
           t=t1+t2+flag;
           flag=t/10;  // 进位
           t%=10;
           result+=static_cast<char>('0'+t);
           ++i;
        }
        while(i<s1.size()) {
            t1=static_cast<int>(s1[i]-'0');
            t=t1+flag;
            flag=t/10;
            t%=10;
            result+=static_cast<char>('0'+t);
            ++i;
        }
        while(i<s2.size()) {
            t1=static_cast<int>(s2[i]-'0');
            t=t1+flag;
            flag=t/10;
            t%=10;
            result+=static_cast<char>('0'+t);
            ++i;
        }
        if(flag>0) result+='1';
        reverse(result.begin(),result.end());
        return result;
    }
    string multiply(string num1, string num2) {
        if(num1.size()<1||num2.size()<1) return "";
        if(num1.size()==1&&num2.size()==1) {
            int n1=num1[0]-'0';
            int n2=num2[0]-'0';
            int n=n1*n2;
            string s="";
            if(n<10) s+=static_cast<char>(n%10+'0');
            else {
                s+=static_cast<char>(n/10+'0');s+=static_cast<char>(n%10+'0');
            }
            return s;
        }
        // 分而治之
        string s1=num1.substr(0,num1.size()/2),s2=num1.substr(num1.size()/2),s3=num2.substr(0,num2.size()/2),s4=num2.substr(num2.size()/2);
        string t1=multiply(s1,s3),t2=multiply(s1,s4),t3=multiply(s2,s3),t4=multiply(s2,s4);
        addzeor(t1,num1.size()+num2.size()-(num1.size()/2)-(num2.size()/2));
        addzeor(t2,(num1.size()-num1.size()/2));
        addzeor(t3,(num2.size()-num2.size()/2));
        s1=addstr(t1,t2); s2=addstr(t3,t4);
        s1=addstr(s1,s2);
        while(s1.size()>1&&s1[0]=='0') s1.erase(0,1);
        return s1;
    }
};