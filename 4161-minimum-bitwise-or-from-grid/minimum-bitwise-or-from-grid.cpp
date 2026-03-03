class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;

        for(int i=19;i>=0;i--){
            int b=1LL<<i;
            int mask=ans|(b-1);

            bool valid=true;
            for(auto &row:grid){
                bool is_col=false;
                for(auto x:row){
                    if( ( x & mask ) == x)is_col=true;
                }
                if(!is_col)valid=false;
            }
            if(!valid)
            ans=ans|b;
        }
        return ans;
        
    }
};