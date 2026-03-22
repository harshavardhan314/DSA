vector<vector<int>> rotate(vector<vector<int>>&mat){
    vector<vector<int>>res;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<m;i++){
        vector<int>curr_col;
        for(int j=0;j<n;j++){
            curr_col.push_back(mat[j][i]);
        }
        reverse(curr_col.begin(),curr_col.end());
        res.push_back(curr_col);

    }
    return res;

}
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>>temp=mat;
        for(int i=0;i<4;i++){
            
            if(temp==target)return true;
            temp=rotate(temp);
        }
        return false;
    }
};