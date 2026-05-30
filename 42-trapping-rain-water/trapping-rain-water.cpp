class Solution {
public:
    int trap(vector<int>& nums) {

        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left=prefix[i];
            int right=suffix[i];
            ans+=min(left,right)-nums[i];
        }
        return ans;

        
    }
};