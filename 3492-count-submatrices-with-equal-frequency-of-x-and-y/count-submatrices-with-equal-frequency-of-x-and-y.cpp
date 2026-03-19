vector<vector<int>>precompute(vector<vector<char>>& grid,char req){

    int n=grid.size();
    int m=grid[0].size();
        

    vector<vector<int>>pre(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==req)pre[i][j]+=1;
                if(i>0)pre[i][j]+=pre[i-1][j];
                if(j>0)pre[i][j]+=pre[i][j-1];
                if(i>0 && j>0)pre[i][j]-=pre[i-1][j-1];



            }
        }
    
    return pre;
}

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>pre_x(n,vector<int>(m,0));
        vector<vector<int>>pre_y(n,vector<int>(m,0));
        pre_x=precompute(grid,'X');
        pre_y=precompute(grid,'Y');

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(pre_x[i][j]==pre_y[i][j] && pre_x[i][j]>0){
                    ans++;

                }



            }
        }
        return ans;
        
    }
};