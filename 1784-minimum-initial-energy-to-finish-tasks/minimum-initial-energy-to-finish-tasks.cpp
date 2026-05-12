class Solution {
public:

    bool check(long long mid, vector<pair<int,int>>& vp){

        long long energy = mid;

        for(auto &[actual, minimum] : vp){

            if(energy < minimum)
                return false;

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        vector<pair<int,int>> vp;

        for(auto &t : tasks){
            int actual = t[0];
            int minimum = t[1];

            vp.push_back({actual, minimum});
        }

        sort(vp.begin(), vp.end(),
            [](auto &a, auto &b){

                return (a.second - a.first) >
                       (b.second - b.first);
            });

        long long l = 1;
        long long h = 1e18;

        long long ans = h;

        while(l <= h){

            long long mid = l + (h-l)/2;

            if(check(mid, vp)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return (int)ans;
    }
};