//解法1
//#include <iostream>
//#include <stack>
//#include<cmath>
//using namespace std;
//class MinStack {
//	typedef struct X{
//			int x;
//					int minx;
//							X(int x,int minx):x(x),minx(minx){}  //构造函数    
//								}minX;
//								public:
//									void push(int x) {
//											int minx=S.empty() ? x : min(x,S.top().minx); // 最小元素 
//													S.push(minX(x,minx));
//														}
//															void pop() {
//																	S.pop();
//																		}
//																			int top() {
//																					return S.top().x;
//																						}
//																							int getMin() {
//																									return S.top().minx;
//																										}
//																										private:
//																											stack<minX> S;
//																											};
//																											int main()
//																											{
//																											  MinStack S1;
//																											    int a[]={12,5,6,41,10,1,16};
//																											      for(int i=0;i<7;i++)
//																											        {
//																											        	S1.push(a[i]);
//																											        		cout<<“top=”<<S1.top()<<”  min=”<<S1.getMin()<<endl;
//																											        			if(i==1) S1.pop();
//																											        			  }
//																											        			    system(“pause”);
//																											        			    }
//
//																											        			    //解法2
//																											        			    #include <iostream>
//																											        			    #include <stack>
//																											        			    using namespace std;
//																											        			    class MinStack {
//																											        			    	typedef struct X{
//																											        			    			int min;
//																											        			    					int count;
//																											        			    							X(int min,int count):min(min),count(count){}  //构造函数       
//																											        			    								}minX;
//																											        			    								public:
//																											        			    									void push(int x) {
//																											        			    											S.push(x);
//																											        			    													if(minS.empty()|| minS.top().min>x) { // 空栈 或 最小值出现 
//																											        			    															   minS.push(minX(x,1));
//																											        			    															   		} else if(minS.top().min==x){  // 等于最小值 
//																											        			    															   				   minS.top().count++;
//																											        			    															   				   		}
//																											        			    															   				   			}
//																											        			    															   				   				void pop() {
//																											        			    															   				   						if(S.top()==minS.top().min)
//																											        			    															   				   									if(minS.top().count>1)
//																											        			    															   				   												  minS.top().count–;
//																											        			    															   				   												  			else
//																											        			    															   				   												  						  minS.pop();
//																											        			    															   				   												  						  		S.pop();
//																											        			    															   				   												  						  			}
//																											        			    															   				   												  						  				int top() {
//																											        			    															   				   												  						  						return S.top();
//																											        			    															   				   												  						  							}
//																											        			    															   				   												  						  								int getMin() {
//																											        			    															   				   												  						  										return minS.top().min;
//																											        			    															   				   												  						  											}
//																											        			    															   				   												  						  											private:
//																											        			    															   				   												  						  												stack<int> S;
//																											        			    															   				   												  						  													stack<minX> minS;
//																											        			    															   				   												  						  													};
//																											        			    															   				   												  						  													int main()
//																											        			    															   				   												  						  													{
//																											        			    															   				   												  						  													  MinStack S1;
//																											        			    															   				   												  						  													    int a[]={12,5,6,8,10,1,16};
//																											        			    															   				   												  						  													      for(int i=0;i<7;i++)
//																											        			    															   				   												  						  													        {
//																											        			    															   				   												  						  													        	S1.push(a[i]);
//																											        			    															   				   												  						  													        		cout<<“top=”<<S1.top()<<”  min=”<<S1.getMin()<<endl;
//																											        			    															   				   												  						  													        			if(i==1) S1.pop();
//																											        			    															   				   												  						  													        			  }
//																											        			    															   				   												  						  													        			    system(“pause”);
//																											        			    															   				   												  						  													        			    }
//
