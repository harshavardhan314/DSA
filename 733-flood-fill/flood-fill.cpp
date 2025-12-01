class Solution {
public:
    void rec(int i,int j,vector<vector<int>>&image,int req,vector<vector<int>>&vis)
    {
        int old=image[i][j];
        image[i][j]=req;
        vis[i][j]=1;
        int n=image.size();
        int m=image[0].size();
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
        for(auto it:dir)
        {
            int ni=i+it.first;
            int nj=j+it.second;
            if(ni>=0 && ni<n &&  nj>=0 && nj<m && image[ni][nj]==old && !vis[ni][nj])
            {
                rec(ni,nj,image,req,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int req) {

        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
      
                    rec(sr,sc,image,req,vis);
           
        return image;
        
    }
};