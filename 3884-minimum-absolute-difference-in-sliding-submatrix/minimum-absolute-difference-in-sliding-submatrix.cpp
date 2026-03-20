class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        vector<vector<int>>ans;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                
                if(i+k-1<n && j+k-1<m){
                vector<int>vals;
                for(int ni=i;ni<=i+k-1;ni++){
                    for(int nj=j;nj<=j+k-1;nj++){
                        vals.push_back(grid[ni][nj]);
                    }
                }

                if(vals.size()==1)temp.push_back(0);
                else{
                    sort(vals.begin(),vals.end());
                    int diff=INT_MAX;
                    for(int i=0;i+1<vals.size();i++){
                        if(vals[i]!=vals[i+1])
                        diff=min(diff,vals[i+1]-vals[i]);
                    }
                    if(diff!=INT_MAX)
                    temp.push_back(diff);
                    else
                    temp.push_back(0);
                }
                
                }
            }
            if(!temp.empty())ans.push_back(temp);
        }
        return ans;
    }
};