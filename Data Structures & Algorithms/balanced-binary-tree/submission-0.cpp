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
    bool bal = true;
    int trav ( TreeNode* root){
        if(root==NULL)return 0;

        int left = trav(root->left);
        int right = trav(root->right);

        if(abs(left-right)>1)bal = false;

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        trav(root);
        return bal;    
    }
};
