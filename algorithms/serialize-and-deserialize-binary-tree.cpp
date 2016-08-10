/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return string("");
        stringstream s;
        s<<root->val;
        return s.str()+"("+serialize(root->left)+")("+serialize(root->right)+")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()<1) return NULL;
        int index=data.find('(');
        string temp=data.substr(0,index);  // 截断
        stringstream s;
        s<<temp; // 输出到stream
        int val;
        s>>val;  // 输入到int
        TreeNode* n=new TreeNode(val);
        int count=1,i;
        for(i=index+1;i<data.size();++i){
            if(data[i]=='(') ++count;
            if(data[i]==')') --count;
            if(count==0)  break;// 找到与第一个(匹配的)
        }
        string t1=data.substr(index+1,i-index-1),t2=data.substr(i+2,data.size()-i-3);
        n->left=deserialize(t1); n->right=deserialize(t2);
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));