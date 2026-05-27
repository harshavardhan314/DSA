class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {


        // brute..
        int n=nums.size();
        set<vector<int>>st;
        unordered_map<long long int,int>mp;
        for(auto it:nums)mp[it]++;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    
                    mp[nums[i]]--;
                    mp[nums[j]]--;
                    mp[nums[k]]--;

                        long long int sum=1LL*nums[i]+nums[j]+nums[k];
                        long long rem=target-sum;
                        if(mp.find(rem)!=mp.end() && mp[rem]>0){
                            vector<int>temp{nums[i],nums[j],nums[k],(int)rem};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }

                    mp[nums[i]]++;
                    mp[nums[j]]++;
                    mp[nums[k]]++;
                    
                }
            }
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};