class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        int min_element=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            int profit=prices[i]-min_element;
            ans=max(ans,profit);
            min_element=min(min_element,prices[i]);
        }
        return ans;
        
    }
};