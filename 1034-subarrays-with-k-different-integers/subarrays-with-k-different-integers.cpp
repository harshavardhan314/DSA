int find_subarray(vector<int>&nums,int k){

    map<int,int>mp;
    int l=0;
    int n=nums.size();
    int ans=0;
    for(int r=0;r<n;r++){
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
        }
        int len=r-l+1;
        ans+=len;
    }
    return ans;

}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find_subarray(nums,k)-find_subarray(nums,k-1);
    }
};