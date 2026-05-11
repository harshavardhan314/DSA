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

 void postorder(TreeNode *root,vector<int>&v){
   
    if(root->left!=NULL)postorder(root->left,v);
    if(root->right!=NULL)postorder(root->right,v);
     v.push_back(root->val);
    return;

}
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>v;
        postorder(root,v);
        return v;
    }
};