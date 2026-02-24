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

int rec(TreeNode*root,int curr_sum){
    if(root==NULL)return 0;
    curr_sum=curr_sum*2+ root->val;
    if(root->left==NULL && root->right==NULL)return curr_sum;
    int left=rec(root->left,curr_sum);
    int right=rec(root->right,curr_sum);
    return left+right;
}
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return rec(root,0);
    }
};