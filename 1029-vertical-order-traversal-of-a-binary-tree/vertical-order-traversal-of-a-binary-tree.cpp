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
vector<vector<int>> level_order(TreeNode*root){

    vector<pair<int,int>>temp;
    queue<pair<int,TreeNode*>>q;
    map<int,multiset<pair<int,int>>>mp;
    q.push({0,root});
    int level=0;
    while(q.size()>0){
        int s=q.size();
        for(int i=0;i<s;i++){
            int col=q.front().first;
            TreeNode* node=q.front().second;
            q.pop();
            if(node==NULL){
                continue;
            }
            mp[col].insert({level,node->val});
            q.push({col-1,node->left});
            q.push({col+1,node->right});
            
        }
        level++;
    }
    vector<vector<int>>res;
    for(auto it:mp){
        
        
        vector<int>t;
        multiset<pair<int,int>>values=it.second;
        for(auto itr:values){
            t.push_back(itr.second);
        }
        
        
        res.push_back(t);
    }
    return res;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return level_order(root);
    }
};