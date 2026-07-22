class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            vector<int>temp(i+1,1);
            res.push_back(temp);
        }
        // for(auto it:res){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=2;i<n;i++){
            for(int j=1;j<res[i].size()-1;j++){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;

        // T.c=o(n*m)
        // s.c=O(N*M)
        
    }
};