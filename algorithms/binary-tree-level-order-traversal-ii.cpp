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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> Q;
        Q.push(root);   // 第一层
        int levelnums;  // 当前层的节点个数
        TreeNode* p;   // 访问节点
        while(!Q.empty()) {
            levelnums=Q.size();  // 当前层的节点个数  
            vector<int> v;
            while(levelnums--) {  // 逐一访问并将左右子节点加入队列（下一层的节点）
                p=Q.front();Q.pop();
                v.push_back(p->val);
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            result.push_back(v);  // 当前层的节点值
        }
        reverse(result.begin(),result.end());
        return result;
    }
};