int reverse(int n){
    int res=0;
    while(n>0){
        res=res*10+n%10;
        n=n/10;
    }
    return res;
}
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        int n=nums.size();
        map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){

            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            int val=reverse(nums[i]);
            mp[val]=i;

        }
        if(ans==INT_MAX)return -1;
        return ans;

        
    }
};