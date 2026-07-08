class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int prev=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=prev){
                cnt++;
               
            }
            else{
                cnt=1;
            }
            prev=nums[i];
            prefix[i]=cnt;

        }
        prev=INT_MAX;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=prev){
                
                cnt++;
            }
            else{
                cnt=1;
                
            }
            prev=nums[i];
            suffix[i]=cnt;
        }
        // for(auto it:prefix){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:suffix){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=1;i<n-1;i++){
            int prev_len=prefix[i-1];
            int next_len=suffix[i+1];
            if(nums[i-1]<=nums[i+1]){
                ans=max(ans,prev_len+next_len+1);
            }
            else{
                ans=max(ans,prev_len+1);
                ans=max(ans,next_len+1);
            }
        }
        
        ans=max(ans,suffix[1]+1);
        ans=max(ans,prefix[n-2]+1);
        
        
        return ans;
    }
};