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
bool rec(TreeNode* p, TreeNode *q){
    if(p==NULL && q==NULL)return true;
    if(p==NULL && q!=NULL || q==NULL && p!=NULL)return false;
    if(p->val!=q->val)return false;
    bool left=rec(p->left,q->left);
    bool right=rec(p->right,q->right);
    return left&&right;
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        return rec(p,q);
    }
};