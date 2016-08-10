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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode*> S;
        TreeNode* cur=root;
        while(cur||!S.empty()) {
            while(cur) {
                result.push_back(cur->val);
                S.push(cur);
                cur=cur->left;
            }
            if(!S.empty()) {
                cur=S.top();
                S.pop();
                cur=cur->right;
            }
        }
        return result;
    }
};