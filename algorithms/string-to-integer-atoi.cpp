class Solution {
public:
    int myAtoi(string str) {
        int flag=1,i=0,result=0,temp;
        // 清楚前置空
        while(i<str.size()&&str[i]==' ') 
            str.erase(i,1);
        
        if(str.size()<1) return 0;
        //查看第一位情况
        if(str[0]=='-'){
            flag=-1;
            ++i;
        }
        if(str[0]=='+')
            ++i;
        
        while(i<str.size()){
            if(str[i]>='0'&&str[i]<='9') {
                temp=result;
                result=result*10+static_cast<int>(str[i]-'0');
                if(temp>result/10){
                    // 溢出
                    if(flag==1) return 2147483647;
                    else return -2147483648;
                }
            }
            else  
                break;
            ++i;
        }
        return result*flag;
    }
};