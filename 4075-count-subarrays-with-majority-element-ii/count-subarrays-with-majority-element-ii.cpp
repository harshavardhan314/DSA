class Solution {
public:
    vector<int> merge(vector<int> &left, vector<int> &right, long long &ans) {
        int l = 0, r = 0;
        int n = left.size();
        int m = right.size();

        int cnt = 0;
        vector<int> temp;

        while (l < n && r < m) {
            if (left[l] < right[r]) {
                temp.push_back(left[l]);
                l++;
                cnt++;
            } else {
                temp.push_back(right[r]);
                ans += cnt;
                r++;
            }
        }

        while (l < n) {
            temp.push_back(left[l]);
            l++;
        }

        while (r < m) {
            temp.push_back(right[r]);
            ans += cnt;
            r++;
        }

        return temp;
    }

    vector<int> merge_sort(vector<int> &nums, long long &ans, int l, int r) {
        if (l == r)
            return {nums[l]};

        int mid = (l + r) / 2;

        vector<int> left = merge_sort(nums, ans, l, mid);
        vector<int> right = merge_sort(nums, ans, mid + 1, r);

        return merge(left, right, ans);
    }

    long long countMajoritySubarrays(vector<int> &nums, int target) {
        int n = nums.size();

       
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        long long ans = 0;

        merge_sort(pref, ans, 0, n);

        return ans;
    }
};