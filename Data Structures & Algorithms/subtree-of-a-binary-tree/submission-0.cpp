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

class Solution {
public:
    bool trav(TreeNode* root , TreeNode* sub){
        if(!root && !sub)return true;
        if(!root || !sub)return false;

        if(root->val!=sub->val)return false;

        return trav(root->left,sub->left) && trav(root->right,sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;

        if(trav(root,subRoot)==true)return true;

        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
