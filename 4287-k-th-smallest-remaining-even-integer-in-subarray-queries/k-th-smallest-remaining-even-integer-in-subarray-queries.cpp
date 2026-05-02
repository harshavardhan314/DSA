
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& q) {

        int n=nums.size();
        vector<int>pre(n,0);
        if(nums[0]%2==0)pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
            if(nums[i]%2==0)pre[i]++;
        }
        vector<int>ans;

        for(auto it:q){
            int l=it[0];
            int r=it[1];
            int k=it[2];

            int left=l>0?pre[l-1]:0;
            int right=pre[r];

            int lo=k;
            int hi=k+(right-left);
            int res=hi;

            while(lo<=hi){
                
                long long  mid=lo+(hi-lo)/2;

                long long  curr=2LL*mid;

                int idx=upper_bound(nums.begin(),nums.end(),curr)-nums.begin();

                int evens_used=idx>0?pre[idx-1]:0;

                int rem=mid-(evens_used-left);

                if(rem>=k){
                    res=mid;
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }


                
            }

            ans.push_back(2*res);

        }


        return ans;







        
    }
};