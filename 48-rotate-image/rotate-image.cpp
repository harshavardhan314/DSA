class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        int col=0;
        for(int i=n-1;i>=0;i--){
            vector<int>temp=matrix[i];
            for(int j=0;j<n;j++){
                res[j][col]=temp[j];
            }
            col++;
        }
        matrix=res;

    }
};