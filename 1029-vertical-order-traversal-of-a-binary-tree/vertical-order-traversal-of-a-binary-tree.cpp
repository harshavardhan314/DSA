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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            TreeNode* node=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            mp[col][row].insert(node->val);
            if(node->left) q.push({node->left,{row+1,col-1}});
            if(node->right) q.push({node->right,{row+1,col+1}});
        }

        vector<vector<int>>res;
        for(auto it:mp){
            
            map<int,multiset<int>>curr=it.second;
             vector<int>level;
            for(auto i:curr){
               
                for(auto val:i.second){
                    level.push_back(val);
                }
                
            }
            res.push_back(level);
            
        }
        return res;
    }
};