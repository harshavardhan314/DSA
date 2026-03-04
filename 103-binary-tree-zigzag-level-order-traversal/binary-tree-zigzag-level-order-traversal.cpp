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

    vector<vector<int>>order;
    queue<TreeNode*>q;
    q.push(root);
    int cnt=0;
    while(q.size()>0){
        int s=q.size();
        vector<int>temp;
        for(int i=0;i<s;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                continue;
            }
            temp.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
            
        }
        if(cnt&1){
            reverse(temp.begin(),temp.end());
        }
        cnt++;
        if(temp.size()>0)
        order.push_back(temp);

    }
    return order;
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return level_order(root);
        
    }
};