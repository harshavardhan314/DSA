/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 TreeNode* rec(TreeNode*root,TreeNode* p,TreeNode* q){

    if(root==NULL || root->val==p->val || root->val==q->val)return root;

    TreeNode* left=rec(root->left,p,q);
    TreeNode* right=rec(root->right,p,q);

    if(left==NULL)return right;
    else if(right==NULL)return left;
    else return root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        return rec(root,p,q);
    }
};