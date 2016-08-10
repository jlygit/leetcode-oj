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
    vector<TreeNode*> generate(int start,int end) {
        // 生成start-end的二叉搜索树
        vector<TreeNode*> result,left,right;
        if(start==end)  {
            result.push_back(new TreeNode(start));  // 生成树
            return result;
        }
        if(start>end) {
            result.push_back(NULL);  // 生成树
            return result;
        }
        for(int i=start;i<=end;++i) {
            // 假设以i为树根  生成其他树
            left=generate(start,i-1);     // 左边元素的树木
            right=generate(i+1,end);      // 右边元素的树木
            // 合并成为父树
            for(int i1=0;i1<left.size();++i1)
                for(int j=0;j<right.size();++j) {
                    TreeNode* t=new TreeNode(i);  // 生成一颗树根
                    t->left=left[i1];
                    t->right=right[j];
                    result.push_back(t);
                }
        }
        return result;  // 返回所有树
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return vector<TreeNode*>();
        return generate(1,n);
    }
};