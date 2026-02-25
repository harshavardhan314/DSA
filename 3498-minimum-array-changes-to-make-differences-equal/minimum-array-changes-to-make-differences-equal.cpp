class Solution {
public:
    int minChanges(vector<int>& arr, int k) {
        vector<int>diff(k+10,0);
        int n=arr.size();
        for(int i=0;i<n/2;i++){
            int d=abs(arr[i]-arr[n-1-i]);
            int max_diff=max(max(arr[i],arr[n-i-1]),k-min(arr[i],arr[n-i-1]));
            diff[0]++;// for single op
            diff[d]--;// exactly zero op
            diff[d+1]++;
            diff[max_diff+1]++;// for two op
        }
        int ans=n;
        for(int i=1;i<=k;i++){
            diff[i]+=diff[i-1];
            ans=min(ans,diff[i]);
        }
        ans=min(ans,diff[0]);
        return ans;
        
    }
};