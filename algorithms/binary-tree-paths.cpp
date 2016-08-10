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
    vector<string> DFS(TreeNode* node) {
        vector<string> res;
        if(!node->left&&!node->right)   //叶子
            res.push_back(to_string(node->val));
        else {
            if(node->left)  // 
                for(auto s : DFS(node->left))
                    res.push_back(to_string(node->val)+"->"+s);
            if(node->right)  
                for(auto s:DFS(node->right))
                    res.push_back(to_string(node->val)+"->"+s);
        }
        return res;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        return DFS(root);
    }
};