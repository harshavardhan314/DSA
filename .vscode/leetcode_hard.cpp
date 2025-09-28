class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int cnt_1=0;
        map<int,int>mp;
        while(r<nums.size())
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]<=0)
                mp.erase(nums[l]);
                l++;
            }
            cnt_1+=(r-l)+1;
            r++;


        }
        l=0;
        r=0;
        mp.clear();
        int cnt_2=0;
         while(r<nums.size())
        {
            mp[nums[r]]++;
            while(mp.size()>=k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]<=0)
                mp.erase(nums[l]);
                l++;
            }
            cnt_2+=(r-l)+1;
            r++;


        }

        return cnt_1-cnt_2;
    }
};