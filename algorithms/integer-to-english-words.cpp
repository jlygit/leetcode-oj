class Solution {
public:
    string help(int num) {
        string temp[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
		"Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string temp1[]={"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        int i,j,k;  // 个位  十位  百位 
        i=num%100;
        k=num/=100;
        if(i==0) 
        {
        	if(k==0) return "";
        	return temp[k]+" Hundred";
		}
		if(i<20){
			if(k==0) return temp[i];
			return temp[k]+" Hundred "+temp[i];
		}
		// 大于20的另算 
        j=i/10; i%=10;
        if(i==0) {
            if(k==0) return temp1[j];
            return temp[k]+" Hundred "+temp1[j];
        }
        if(k==0) return temp1[j]+" "+temp[i];
        return temp[k]+" Hundred "+temp1[j]+" "+temp[i];
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string result="";
        string temp[]={""," Thousand "," Million "," Billion "};
        int i=0;
        while(num) {
            int t=num%1000;
            num/=1000;
            if(t)
                result=help(t)+temp[i]+result;
            ++i;
        }
        while(result[result.size()-1]==' ') result.erase(result.size()-1);
        return  result;
    }
};