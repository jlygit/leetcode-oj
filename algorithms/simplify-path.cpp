class Solution {
public:
    string simplifyPath(string path) {
        if(path.size()<1) return string("");
        deque<string> s;
        s.push_back(string(1,path[0]));
        path.erase(0,1);
        string temp;
        while(path.size()>0) {
        	int i=path.find('/');
        	if(path.npos==i)
        	{  // 找不到  那么就直接要了 
        		temp=path;
        		path="";
			}
        	else
        	{
        		temp=path.substr(0,i+1);
        		path.erase(0,i+1);
			}
        	if(temp==string("/")) continue;
        	if(temp==string("./")||temp==string(".")) ;
        	else if(temp==string("../")||temp==string("..")) 
        	{
        		if(s.back()!=string("/")) s.pop_back();
			} else 
				s.push_back(temp);	
        }
        while(!s.empty()) {
            path+=s.front();
            s.pop_front();
        }
        if(path.size()>1&&path[path.size()-1]=='/') path.erase(path.size()-1);
        return path;
    }
};