class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long A=long(numerator);
        long B=long(denominator);
        string res="";
        if(A==B)    return {"1"};
        bool sign =((A>=0) ^ (B>=0));  // 判断符号 如果一真一假
        if(sign && A!=0)  res+="-";
        long diff=0;
        bool pointer=false;
        unordered_map<long, int>map;  // 用以判断是否出现循环
        A=labs(A),B=labs(B);
        while(1){
            res+= to_string(A/B);
            diff=A%B;
            if(diff==0)return res;
            if(diff < B && !pointer){
                    res+=".";
                    pointer=true;
            }
            A=diff * 10;
            if(map.find(diff)!=map.end())break;  // 出现循环了
            else map[diff]=res.length();    // 记录当前位置
        }
        res.insert(map[diff],"(");
        res+=")";
        return res;
    }
};