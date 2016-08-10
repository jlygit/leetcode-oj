class Solution {
public:
    double findk(vector<int>& nums1, vector<int>& nums2,int k) {
        int s1=0,s2=0,m1,m2;
         while(true){
            if(s2>=nums2.size())return nums1[s1+k-1];
            if(s1>=nums1.size())return nums2[s2+k-1];
            if(k==1)
            {
                return min(nums1[s1],nums2[s2]);
            }
            if(nums1.size()-s1>nums2.size()-s2){
                m2=min(k/2,static_cast<int>(nums2.size())-s2);
                m1=k-m2;
                if(nums1[s1+m1-1]>=nums2[s2+m2-1]){
                    s2+=m2;
                    k-=m2;
                }else{
                    s1+=m1;
                    k-=m1;
                }
            } else {
                m1=min(k/2,static_cast<int>(nums1.size())-s1);
                m2=k-m1;
                if(nums1[s1+m1-1]>=nums2[s2+m2-1]){
                    s2+=m2;
                    k-=m2;
                }else{
                    s1+=m1;
                    k-=m1;
                }
            }
            
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int nums=nums1.size()+nums2.size();
       if(nums&0x01)
           return findk(nums1,nums2,(nums+1)/2);
       else
           return (findk(nums1,nums2,(nums+1)/2)+findk(nums1,nums2,(nums+2)/2))/2;
    }
};