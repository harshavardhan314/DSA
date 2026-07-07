#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Manacher {
public: 
    vector<int> temp;
    vector<int> p;

    Manacher(vector<int>& nums) {
        temp.push_back(-2);
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(-1);
            temp.push_back(nums[i]);
        }
        temp.push_back(-1);
        temp.push_back(-3);
        p.assign(temp.size(), 1);
    }

    void build() {
        int l = 1;
        int r = 1;
        int n = temp.size();

        
        for (int i = 1; i < n - 1; i++) {
            int mirror = l + r - i;
                p[i]=max(1,min(r-i,p[mirror]));


            while (i + p[i] < n && i - p[i] >= 0 && temp[i + p[i]] == temp[i - p[i]]) {
                p[i]++;
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
};

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        Manacher m(nums);
        m.build();
        
        vector<long long> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        
        long long ans = 0;
        
        for (int i = 0; i < m.p.size(); i++) {
            int len = m.p[i] - 1;
            if (len <= 0) continue; 
            int l = (i - len) / 2;
            int r = (i + len) / 2 - 1;

            if (l <= r && l >= 0 && r < n) {
                long long val = pre[r];
                if (l - 1 >= 0) {
                    val -= pre[l - 1];
                }
                ans = max(ans, val);
            }
        }
        return ans;
    }
};