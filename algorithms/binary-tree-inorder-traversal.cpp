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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return vector<int>();
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur;
        vector<int> result;
        while(!s.empty()) {
            cur=s.top();
            while(cur) {
                s.push(cur->left);
                cur=cur->left;
            }
            s.pop();
            if(!s.empty()) {
                cur=s.top();s.pop();
                result.push_back(cur->val);
                s.push(cur->right);
            }
            // null 3
        }
        return result;
    }
};