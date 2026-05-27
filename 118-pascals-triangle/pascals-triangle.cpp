class Solution {
public:
    vector<vector<int>> generate(int n) {

        if(n==1){
            return {{1}};
        }
        vector<vector<int>>res;
        res.push_back({1});

        for(int i=1;i<n;i++){
            vector<int>curr_row;
            curr_row.push_back(1);

            for(int j=0;j<res[i-1].size();j++){
                if(j+1<res[i-1].size()){
                    curr_row.push_back(res[i-1][j] + res[i-1][j+1]);
                }
            }
            curr_row.push_back(1);

            res.push_back(curr_row);
        }

        return res;
        
    }
};