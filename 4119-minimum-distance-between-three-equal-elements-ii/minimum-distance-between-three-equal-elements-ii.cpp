class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                mp[nums[i]].push_back(i);
            }
        int ans=INT_MAX;
        for(auto it:mp)
            {
                vector<int>temp=mp[it.first];
                for(int i=0;i+2<temp.size();i++)
                    {
                        int dist=temp[i+1]-temp[i]+temp[i+2]-temp[i+1]+temp[i+2]-temp[i];
                        ans=min(ans,dist);
                    }
            }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};