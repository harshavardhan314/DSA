class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int ans=n+2;
        int sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            if(mp[nums[r]]==1)sum+=nums[r];
            while(sum>=k && l<=r){
                ans=min(ans,r-l+1);
                if(mp[nums[l]]==1)sum-=nums[l];
                mp[nums[l]]--;
                l++;
            }
        }
        if(ans==n+2)return -1;
        return ans;
        
    }
};