class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>temp=mat;
        
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<k;i++){
            vector<vector<int>>curr;
            for(int i=0;i<n;i++){
                vector<int>row_vals;
                if(i%2==0){
                    for(int j=1;j<m;j++)row_vals.push_back(mat[i][j]);
                    row_vals.push_back(mat[i][0]);
                }
                else{
                    row_vals.push_back(mat[i][m-1]);
                    for(int j=0;j<m-1;j++)row_vals.push_back(mat[i][j]);
                }

                curr.push_back(row_vals);

            }
            mat=curr;

        }
        return mat==temp;
        
    }
};