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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>>();
        queue<TreeNode*> s;   // 双端队列
        s.push(root); //当前节点结束标志
        vector<vector<int>> v;
        TreeNode* p;
        while(!s.empty()) {
            s.push(NULL);  // 当层的结束标志
            p=s.front();// 当层第一个节点
            vector<int> temp; //存储当前访问结果
            while(p!=NULL) { //访问当前层  如果没到结束标志 则开始访问 
                temp.push_back(p->val);
                if(p->left)
                s.push(p->left);
                if(p->right)
                s.push(p->right);
                s.pop();
                p=s.front();
            }
            s.pop();  // 删除当层的结束标志
            v.push_back(temp);  // 当层的结果 存储
        }
        for(int i=1;i<v.size();i+=2) reverse(v[i].begin(),v[i].end());
        return v;
    }
    
};