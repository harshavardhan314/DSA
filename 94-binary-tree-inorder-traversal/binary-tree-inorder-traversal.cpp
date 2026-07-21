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

void rec(TreeNode* root,vector<int>&res){
    if(root==NULL)return;
    rec(root->left,res);
    res.push_back(root->val);
    rec(root->right,res);

}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        rec(root,res);
        return res;

        
    }
};