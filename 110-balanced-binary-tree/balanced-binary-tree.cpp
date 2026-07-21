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

int  dfs(TreeNode* root , bool &ans){
    if(root==NULL)return 0;
    int lh=dfs(root->left,ans);
    int  rh=dfs(root->right,ans);
    if(abs(lh-rh)>1){
        ans = ans & false;
    }
    return 1+max(lh,rh);
   
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        dfs(root,ans);
        return ans;
    }
};