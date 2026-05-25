class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        multiset<int> ms;

        vector<int> ans = nums;

        int pos = -1;

        for(int i = n - 1; i >= 0; i--) {

            auto it = ms.upper_bound(nums[i]);

            if(it != ms.end()) {

                ans[i] = *it;

                ms.erase(it);

                ms.insert(nums[i]);

                pos = i + 1;

                break;
            }

            ms.insert(nums[i]);
        }

        
        if(pos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        for(auto x : ms) {
            ans[pos++] = x;
        }

        nums = ans;
    }
};