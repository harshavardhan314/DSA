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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        int max_level=1;
        int level_sum=INT_MIN;
        while (q.size()>0)
        {
            int s=q.size();
            int temp=0;
            while(s>0)
            {
                temp+=q.front()->val;
                if (q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
                s--;
            }
            if(temp>level_sum)
            {
                max_level=level;
                level_sum=temp;
            }
            level++;
        }
        return max_level;

        
    }
};