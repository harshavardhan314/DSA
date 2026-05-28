class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[l]<=arr[mid]){
                ans=min(ans,arr[l]);
                l=mid+1;
            }
            else {
                ans=min(ans,arr[mid]);
                h=mid-1;
            }
        }
        return ans;
        
    }
};