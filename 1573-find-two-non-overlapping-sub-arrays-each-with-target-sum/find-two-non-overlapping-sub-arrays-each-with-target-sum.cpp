


class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        vector<int>prefix(n,1e9);
        int l=0;
        int best=1e9;
        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            if(sum==target)best=min(best,r-l+1);
            prefix[r]=best;

        }
        vector<int>suffix(n,1e9);
        best=1e9;
        sum=0;
        int r=n-1;
        for(int l=n-1;l>0;l--){
            sum+=arr[l];
            while(sum>target && r>=l){
                sum-=arr[r];
                r--;
            }
            if(sum==target)best=min(best,r-l+1);
            suffix[l]=best;
        }
        int ans=1e9;
        for(int i=0;i<n-1;i++){
            if(suffix[i]!=1e9 && prefix[i]!=1e9){
                ans=min(ans,prefix[i]+suffix[i+1]);
            }
        }
        if(ans>n){
            return -1;
        }
        return ans;

        
        
        
    }
};