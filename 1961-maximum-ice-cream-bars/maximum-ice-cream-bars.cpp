class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int temp=0;
        for(auto it:costs){
            if(temp+it<=coins){
                ans++;
                temp+=it;
            }
            else
            break;
        }
        return ans;
        
    }
};