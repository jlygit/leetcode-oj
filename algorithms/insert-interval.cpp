class Solution {
public:
	bool judecross(const Interval& i1,Interval& i2) {  // 判断两区是否相交  相返回真
		return !(i1.end<i2.start||i1.start>i2.end);
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;   // 存储结果
		vector<Interval>::iterator i=intervals.begin();     //迭代器
		while(i!=intervals.end()&&!judecross(*i,newInterval)) {  // 跳出不相交区间 
			result.push_back(*i++);   //不相交可直接插入
		}
		if(i==intervals.end()) {     // 没有相的区间  一个也没有 直接插入
			i=result.begin();
			while(i!=result.end()&&i->start<newInterval.start)  // 查找插入位
				i++;
			if(i==result.end())                                 // 向量尾插入
				result.push_back(newInterval);
			else                                                //任意点插
				result.insert(i,newInterval);
			return result;
		}
		//有相交区间时  开始合并
		//		newInterval.start=newInterval.start<i->start ? newInterval.start : i->start;    //取相交首元素
		//				while((++i)!=intervals.end()&&judecross(*i,newInterval)) ;                      // 跳过相交部分
		//						newInterval.end=newInterval.end>(i-1)->end ? newInterval.end : (i-1)->end;      //取相交尾元素
		//								result.push_back(newInterval);
		//										while(i!=intervals.end())  // 插入剩区间
		//													result.push_back(*i++);
		//															return result;
		//																}
		//																};
		//
		//
		//																vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		//																	vector<Interval> ret;
		//																		int i,n=intervals.size();
		//																			Interval mergeInterval = newInterval;
		//																				for(i=0;i<n;i++){
		//																						if(newInterval.start>intervals[i].end)
		//																									ret.push_back(intervals[i]);
		//																											else if(newInterval.end<intervals[i].start)
		//																														break;
		//																																else
		//																																			mergeInterval = Interval(min(mergeInterval.start,intervals[i].start)
		//																																						,max(mergeInterval.end,intervals[i].end));
		//																																							}
		//																																								ret.push_back(mergeInterval);
		//																																									for(;i<n;i++)
		//																																											ret.push_back(intervals[i]);
		//																																												return ret;
		//																																												}
		//
