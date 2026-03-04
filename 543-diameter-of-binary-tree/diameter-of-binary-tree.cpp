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

int find(TreeNode* root,int &ans){
    if(!root)return 0;
    if(!root->left && !root->right)return 1;
    int left=find(root->left,ans);
    int right=find(root->right,ans);
    ans=max(ans,left+right+1);
    return max(left,right)+1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
      
        find(root,ans);
        return max(0,ans-1) ;
    }
};