int find_ans(vector<int>&nums,int k){
    int l=0;
    map<int,int>mp;
    int ans=0;
    int n=nums.size();
    for(int r=0;r<n;r++){
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
        }
        ans+=(r-l+1);
    }
    return ans;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return find_ans(nums,k)-find_ans(nums,k-1);
        
    }
};