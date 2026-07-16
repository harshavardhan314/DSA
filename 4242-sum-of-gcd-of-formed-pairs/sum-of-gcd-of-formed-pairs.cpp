class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        int mx=nums[0];
        for(int i=1;i<n;i++){
            mx=max(nums[i],mx);
            pre[i]=gcd(nums[i],mx);
            
        }
        sort(pre.begin(),pre.end());
        int l=0;
        int r=n-1;
        long long  ans=0;
      
        while(l<r){
            ans+=gcd(pre[l],pre[r]);
            l++;
            r--;
        }
        return ans;


        
    }
};