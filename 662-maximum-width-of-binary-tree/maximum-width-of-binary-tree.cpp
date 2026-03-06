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

int solve(TreeNode* root){
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    int min_idx=0;
    int ans=0;
    while(!q.empty()){
        int s=q.size();
        int l,r;
        min_idx=q.front().second;
        for(int i=0;i<s;i++){
            TreeNode* node=q.front().first;
            long long  idx=q.front().second - min_idx;
            q.pop();
            if(i==0)l=idx;
            if(i==s-1)r=idx;
            if(node->left)
            q.push({node->left,idx*2+1});
            if(node->right)
            q.push({node->right,idx*2+2});
           
        }
        
        ans=max(ans,r-l+1);
    }
    return ans;
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
        
    }
};