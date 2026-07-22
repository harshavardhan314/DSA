class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                vp.push_back({i,j});
            }
        }
        for(auto [r,c]:vp){
            for(int i=0;i<m;i++){
                matrix[r][i]=0;
            }
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
        }
        
    }
};