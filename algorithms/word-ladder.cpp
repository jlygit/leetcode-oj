class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.size() == 0 || end.size() == 0) return 0;
        // 想象成一棵树
        queue<string> wordQ;
        wordQ.push(start);
        wordQ.push("");
        int path = 1;
        while(!wordQ.empty())   // 按层搜索 
        {
            string str = wordQ.front();
            wordQ.pop();
            if(str != "")
            {
                int len = str.size();
                for(int i = 0; i < len; i++)
                {
                    char tmp = str[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == tmp) continue;
                        str[i] = c;
                        if(str == end) return path + 1; //如果改变后的单词等于end 返回path+1
                        if(dict.find(str) != dict.end())
                        {
                            wordQ.push(str);
                            dict.erase(str);   //字典内删除这个词 防止反复走
                        }
                    }
                    str[i] = tmp;  //重置回原来的单词
                }
            }
            else if(!wordQ.empty())
            {
                //到达当前层的结尾，并且不是最后一层的结尾
                path++;
                wordQ.push("");
            }
        }
        return 0;
    }
};