/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool rec(TreeNode* root, vector<TreeNode*>&path,TreeNode* req){

    path.push_back(root);
    if(root->val==req->val){
        return true;
    }
    if(root->left){
        bool left=rec(root->left,path,req);
        if(left==true)return true;
        else{
            path.pop_back();
        }
    }
    if(root->right){
        bool right=rec(root->right,path,req);
        if(right)return true;
        else path.pop_back();
    }
    
    return false;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>path1,path2;

        rec(root,path1,p);
        rec(root,path2,q);

       int n=path1.size();
       int m=path2.size();
       TreeNode* ans=NULL;
       for(int i=0;i<min(n,m);i++){
        if(path1[i]->val==path2[i]->val)ans=path1[i];
        
       }

        return ans;
        
    }
};