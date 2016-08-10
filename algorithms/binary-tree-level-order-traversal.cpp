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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>>();
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* cur;
        while(!Q.empty()) {
            Q.push(NULL);  //NULL为层截止符
            cur=Q.front();
            Q.pop();
            vector<int> temp;
            while(cur) {
                temp.push_back(cur->val);  //访问节点
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                cur=Q.front();
                Q.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
};