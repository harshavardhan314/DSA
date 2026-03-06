/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode*root,vector<TreeNode*>&path,TreeNode* target){
    if(!root)return false;
    path.push_back(root);
    if(root->val==target->val)return true;
    
    bool left=find(root->left,path,target);
    bool right= find(root->right,path,target);
    if(left || right)return true;
    path.pop_back();
    return false;

}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>path1,path2;
        find(root,path1,p);
        find(root,path2,q);
        int i=0,j=0;
        TreeNode* ans;
        while(i<path1.size() && j<path2.size()){
            if(path1[i]->val==path2[i]->val){
                ans=path1[i];
            }
            else
            break;
            i++;
            j++;
        }
        return ans;

        
    }
};