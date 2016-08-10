/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* makeBST(vector<int>& nums,int start,int end) {
        if(start>end) return NULL;
        TreeNode* t;
        if(start==end) {
            t=new TreeNode(nums[start]);
        } else {
            int m=(start+end)/2;
            t=new TreeNode(nums[m]);
            t->left=makeBST(nums,start,m-1);
            t->right=makeBST(nums,m+1,end);
        }
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
    }
};