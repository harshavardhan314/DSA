class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<pair<int,int>>>mp;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int diff=arr[i]-arr[i-1];
            mp[diff].push_back({arr[i-1],arr[i]});
        }
        auto it=mp.begin();
        vector<pair<int,int>>ans=it->second;
        vector<vector<int>>vals;
        for(auto it:ans)
        {
            vals.push_back({it.first,it.second});
        }
        return vals;
        
    }
};