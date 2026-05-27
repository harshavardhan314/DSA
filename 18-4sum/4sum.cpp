class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {


        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        // fix the first two points and then search for remaining two using two pointer approach..
        vector<vector<int>>res;
        for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1])continue;

            for(int j=i+1;j<n;j++){

                if(j>i+1 && nums[j]==nums[j-1])continue;

                int low=j+1;
                int high=n-1;

                while(low<high){
                    long long sum=1LL * nums[i] + nums[j] + nums[low] + nums[high];

                    if(sum<target){
                        low++;
                    }
                    else if(sum>target){
                        high--;
                    }
                    else{
                        vector<int>temp{nums[i],nums[j],nums[low],nums[high]};
                        res.push_back(temp);
                        low++;
                        high--;
                        while(low<high && nums[low]==nums[low-1])low++;
                        while(low<high && nums[high]==nums[high+1])high--;
                    }
                }


            }
        }
        return res;

    }
};