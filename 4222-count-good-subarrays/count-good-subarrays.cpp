class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {

        int n=nums.size();

        vector<int>left(n,0),right(n,n-1);

        vector<int>prev_bit(31,-1),next_bit(31,n);

        for(int i=0;i<31;i++){

            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i))prev_bit[i]=j;
                else{
                    
                    left[j]=max(left[j],prev_bit[i]+1);
                }
            }
        }

        for(int i=0;i<31;i++){

            for(int j=n-1;j>=0;j--)
            {
                if(nums[j]&(1<<i))next_bit[i]=j;
                else{
                    
                    right[j]=min(right[j],next_bit[i]-1);
                }
            }
        }
        long long ans=0;

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int l=left[i],r=right[i];
            if(mp.count(nums[i])) l=max( l,mp[nums[i]]+1);
            mp[nums[i]]=i;

            ans+=1LL*(i-l+1)*(r-i+1);


        }

        return ans;



    }
};