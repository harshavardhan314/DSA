class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &v)
    {

        int n = v.size();
        int cnt = 1;
        vector<int> val;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                cnt++;
            }
            else
            {
                prev = cnt;
                cnt = 1;
            }
            ans = max({ans, cnt / 2, min(prev, cnt)});
        }

        return ans;
    }
};