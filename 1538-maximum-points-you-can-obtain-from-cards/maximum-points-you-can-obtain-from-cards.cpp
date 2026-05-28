class Solution {
public:
    int maxScore(vector<int>& arr, int k) {

        int n=arr.size();
        vector<int>pre(n+1,0);
        vector<int>suff(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+arr[i];
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,pre[i]+suff[n-k+i]);
        }
        return ans;
        
    }
};