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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty()){
            int sz=q.size();
            
            long long st=q.front().second;
            long long end=q.back().second;
            ans=max(ans,end-st+1);
            for(int i=0;i<sz;i++){
                auto[Node,val]=q.front();
                // every time subtract the min_idx to get rid of the overflow..
                
                long long idx=val-st;
                q.pop();
                if(Node->left){
                    q.push({Node->left,2LL*idx+1});
                }
                if(Node->right){
                    q.push({Node->right,2LL*idx+2});
                }

            }
            
        }
        return (int)ans;
        
    }
};