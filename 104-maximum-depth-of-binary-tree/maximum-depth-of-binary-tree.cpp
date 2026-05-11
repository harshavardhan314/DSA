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


int rec(TreeNode* node){
    if(node==NULL){
        return 0;
    }
    int left=1+rec(node->left);
    int right=1+rec(node->right);
    return max(left,right);
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return rec(root);
        
    }
};