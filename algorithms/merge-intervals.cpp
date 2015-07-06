class Solution {
public:
    static bool com(const Interval& i1,const Interval& i2) // 比较开始元素的大
    {
        return i1.start<i2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size()==0) return result;
        sort(intervals.begin(),intervals.end(),com);
        int i=0;
        result.push_back(intervals[i++]);
        while(i!=intervals.size()) {
            if(result[result.size()-1].end>=intervals[i].start) {
                result[result.size()-1].end=max(result[result.size()-1].end,intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
            i++;
        }
        return result;
    }
};
