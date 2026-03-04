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

vector<int> level_order(TreeNode*root){

    vector<int>temp;
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()>0){
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                temp.push_back(1e9);
                continue;
            }
            temp.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
            
        }

    }
    return temp;
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>tree1;
        vector<int>tree2;

        tree1=level_order(p);
        tree2=level_order(q);
       
        return tree1==tree2;
        
    }
};