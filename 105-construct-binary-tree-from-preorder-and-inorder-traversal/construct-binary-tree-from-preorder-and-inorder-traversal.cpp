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

TreeNode* rec(int pre_st,int pre_end,vector<int>&pre,int in_st,int in_end,vector<int>&in,map<int,int>&mp){

    if(pre_st>pre_end || in_st>in_end )return NULL;

    TreeNode* root = new TreeNode(pre[pre_st]);
    int pos=mp[pre[pre_st]]; 
    int nums_left=pos-in_st;
    root->left=rec(pre_st+1,pre_st+nums_left,pre,in_st,pos-1,in,mp);
    root->right=rec(pre_st+1+nums_left,pre_end,pre,pos+1,in_end,in,mp);
    return root;

    
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

        map<int,int>mp;
        int n=pre.size();
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }

        return rec(0,n-1,pre,0,n-1,in,mp);
        
    }
};