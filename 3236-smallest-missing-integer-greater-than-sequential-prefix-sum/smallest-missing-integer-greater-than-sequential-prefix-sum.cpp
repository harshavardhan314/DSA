class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        pre[0]=nums[0];
        int val=-1;
        for(int i=1;i<n;i++){
           if(nums[i]!=nums[i-1]+1){
            val=pre[i-1];
            break;
           }
           else{
            pre[i]=pre[i-1]+nums[i];
           }
        }
        if(val==-1)val=pre.back();
        while(1){
            if(mp.find(val)==mp.end())
            return val;
            val++;
        }
        return 0;
    }
};