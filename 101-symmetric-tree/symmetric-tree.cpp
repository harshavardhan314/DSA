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

bool issame(TreeNode* root1,TreeNode* root2){
    if(!root1 && !root2)return true;
    if(!root1 || !root2 || root1->val!=root2->val)return false;
    bool left=issame(root1->left,root2->right);
    bool right=issame(root1->right,root2->left);
    return left && right;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return issame(root->left,root->right);


        
    }
};