class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,2),suff(n,2);
        int ans=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
                pre[i] = pre[i-1]+1;
        }
        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i] == nums[i+2]-nums[i+1])
                suff[i] =suff[i+1]+ 1;
        }
        ans=*max_element(pre.begin(),pre.end())+1;
        ans=*max_element(suff.begin(),suff.end())+1;
        for(int i=0;i<n;i++){
            if(i>0){
                ans=max(ans,pre[i-1]+1);
            }
            if(i<n-1){
                ans=max(ans,suff[i+1]+1);
            }
            if(i>0 && i<n-1){
                int diff=(nums[i+1]-nums[i-1]);

                if(diff%2==0){
                    diff=diff/2;
                    if((i>1 && nums[i-1]-nums[i-2] == diff) && (i<=n-3 && nums[i+2] - nums[i+1]==diff)){
                        ans=max(ans,pre[i-1]+suff[i+1]+1);
                    }
                    else if(i>1 && nums[i-1]-nums[i-2]==diff)
                        ans=max(ans,pre[i-1]+2);
                    else if(i<=n-3 && nums[i+2]-nums[i+1] == diff)
                        ans=max(ans,suff[i+1]+2);
                    else
                        ans=max(ans,3);

                }
            }
        }
        if(ans>n)
            ans=n;
        

        return ans;
        
            
    }
};