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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        TreeNode* cur;
        queue<TreeNode*> Q;
        Q.push(root);
        int temp;
        vector<int> result;
        while(!Q.empty()) {
            Q.push(NULL);  //每层的结束标志
            cur=Q.front();  // 每层的第一个节点
            Q.pop();
            while(cur) {
                temp=cur->val;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                cur=Q.front(),Q.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
};