class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<vector<int>>>mp;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int diff=arr[i]-arr[i-1];
            mp[diff].push_back({arr[i-1],arr[i]});
        }
        auto it=mp.begin();
        return it->second;
        
    }
};