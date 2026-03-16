int get(int x,int t){
    int y=0;
    bool match=true;
    for(int i=30;i>=0;i--){

        if(match && (t&(1LL<<i)) && !(x&(1LL<<i)))match=false;

        if(match)y|=x&(1LL<<i);
        else y|=t&(1LL<<i);
    }
    return y-x;
}

class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n=nums.size();
        int mask=0;

        for(int i=30;i>=0;i--){

            vector<int>cost;
            for(int j=0;j<nums.size();j++){
                cost.push_back(get(nums[j],mask|(1LL<<i)));
            }

            sort(cost.begin(),cost.end());
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=cost[j];
                if(sum>k)break;
            }
            if(sum<=k)mask|=(1LL<<i);
        }
        return mask;
        
        
    }
};