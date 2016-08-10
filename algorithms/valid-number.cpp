class Solution {
public:
    bool isNumber(string s) {
        int dotcount=0,ecount=0;
        // 去掉左右空格
        while(s.size()>0&&s[s.size()-1]==' ') s.erase(s.size()-1,1);
        while(s.size()>0&&s[0]==' ') s.erase(0,1);
        if(s.find('e')!=s.npos) {
            string left=s.substr(0,s.find('e')),right=s.substr(s.find('e')+1);
            
            if(left.find('e')!=left.npos||right.find('e')!=right.npos||right.find('.')!=right.npos) return false;
            if(left.size()>0&&(left[0]=='-'||left[0]=='+')) left.erase(0,1);
            if(right.size()>0&&(right[0]=='-'||right[0]=='+')) right.erase(0,1);
            if(left==""||right=="") return false;
            for(int i=0;i<left.size();++i)
                if(left[i]=='.')
                    dotcount++;
                else if(left[i]<'0'||left[i]>'9')
                    return false;
            for(int i=0;i<right.size();++i)
                if(right[i]<'0'||right[i]>'9')
                    return false;
            if(dotcount>1) return false;
            if(dotcount&&left.size()<2) return false;
        }
        else {
            if(s.size()>0&&(s[0]=='-'||s[0]=='+')) s.erase(0,1);
            for(int i=s.size()-1;i>=0;--i)
                if(s[i]=='.')
                    ++dotcount;
                else if(s[i]<'0'||s[i]>'9')
                    return false;
            if(dotcount>1) return false;
            if(dotcount==1&&s.size()<2) return false;
            if(s.size()<1) return false;
        }
        return true;
    }
};