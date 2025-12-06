class Solution {
public:
    bool make(vector<int>temp,int target,int k)
    {
        
        vector<int>&nums=temp;
        int n=temp.size();

        for(int i=0;i<n-1;i++)
        {
           if(nums[i]!=target && k>0)
           {
            nums[i]*=-1;
            nums[i+1]*=-1;
            k--;
           }
        }
        
        for(auto it:nums)
        {
            if(it!=target)
            return false;
        }
        return true;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        bool ans=make(nums,1,k) || make(nums,-1,k);
        for(auto it:nums)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return ans;

        
    }
};