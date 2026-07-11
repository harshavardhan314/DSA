int find_ways(int idx, int val, vector<int>& temp, vector<vector<int>>& dp) {
    if (val == 0) return 1;
    if (idx == temp.size()) return 0;

    if (dp[idx][val] != -1)
        return dp[idx][val];

    int take = 0;
    if (val >= temp[idx])
        take = find_ways(idx, val - temp[idx], temp, dp);

    int skip = find_ways(idx + 1, val, temp, dp);

    return dp[idx][val] = take + skip;
}

class Solution {
public:
    vector<int> findCoins(vector<int>& ways) {

        
        
        int n=ways.size();
        vector<int>temp;
        for(int i=0;i<n;i++){

            vector<vector<int>>dp(n,vector<int>(i+3,-1));
           int no_ways =find_ways(0,i+1,temp,dp);
           
           if(no_ways==ways[i]-1){
            temp.push_back(i+1);
           }
           else if(no_ways==ways[i])continue;
           else{
            return {};
           }
           
            
        }
        return temp;

    }
};