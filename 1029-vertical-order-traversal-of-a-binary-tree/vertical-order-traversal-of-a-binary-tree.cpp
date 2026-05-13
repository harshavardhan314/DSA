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

void rec(TreeNode* root, int row, int col,map<int,vector<pair<int,int>>>&mp){
    mp[col].push_back({row,root->val});
    if(root->left){
        rec(root->left,row+1,col-1,mp);
    }
    if(root->right){
        rec(root->right,row+1,col+1,mp);
    }
    return;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {


        map<int,vector<pair<int,int>>>mp;
        rec(root,0,0,mp);
        vector<vector<int>>ans;
        for(auto it:mp){

            vector<int>t;
            vector<pair<int,int>>temp=it.second;
            sort(temp.begin(),temp.end());
            for(auto i:temp){
                t.push_back(i.second);
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};