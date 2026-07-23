/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void ser(TreeNode* root , string& s){
        if(!root){
            s+="N,";
            return;
        }
        s+=to_string(root->val)+",";
        ser(root->left,s);
        ser(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        ser(root,s);
        return s;
    }

    TreeNode* deser(stringstream& ss){
        string val ;
        getline(ss,val,',');
        if(val=="N"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deser(ss);
        node->right = deser(ss);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deser(ss);
        
    }
};
