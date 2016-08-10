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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> S;
        S.push(root);
        TreeNode* p,*head=new TreeNode(0),*cur=head;
        while(!S.empty()) {
            p=S.top(),S.pop();
            if(p&&p->right) S.push(p->right);
            if(p&&p->left) S.push(p->left);
            p->left=NULL,cur->right=p,cur=p;
        }
        root=head->right;
    }
};