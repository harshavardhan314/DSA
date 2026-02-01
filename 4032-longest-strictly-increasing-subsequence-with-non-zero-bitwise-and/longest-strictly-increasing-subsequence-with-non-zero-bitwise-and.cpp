class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){

            for(int j=0;j<32;j++){
                
                if(nums[i]&(1LL<<j))
                    mp[j].push_back(nums[i]);
            }
        }
        int ans=0;
        for(auto it:mp){
            vector<int>temp=it.second;

            vector<int>lis;

            if(!temp.empty())lis.push_back(temp[0]);

            for(int i=1;i<temp.size();i++){
                int idx=lower_bound(lis.begin(),lis.end(),temp[i])-lis.begin();
                if(idx<lis.size())
                lis[idx]=temp[i];
                else
                lis.push_back(temp[i]);
            }
            
            int current_len=lis.size();
           
            ans=max(ans,current_len);
        }

        return ans;
        
        
    }
};