class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {

        int n=m.size();
        int mm=m[0].size();

        for(int j=0;j<mm;j++){
            for(int i=1;i<n;i++){
                if(m[i][j]==1){
                    m[i][j]+=m[i-1][j];
                }
                
            }
            
        }
        int res=0;
        for(int i=0;i<n;i++){
            vector<int>h;
            for(int j=0;j<mm;j++){
                h.push_back(m[i][j]);
            }

            sort(h.rbegin(),h.rend());
            for(int j=0;j<mm;j++){
                res=max(res,h[j]*(j+1));
            }
        }
        return res;

        
    }
};