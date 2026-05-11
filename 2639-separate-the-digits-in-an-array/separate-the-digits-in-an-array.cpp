
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int temp=nums[i];
            while(temp>0){
                ans.push_back(temp%10);
                temp=temp/10;
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};