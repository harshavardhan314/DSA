bool can_make(int day,vector<int>&arr,int adj,int need){
    int n=arr.size();
    int cnt=0;
    int no_bouquets=0;
    for(int i=0;i<n;i++){

        if(arr[i]<=day){
            cnt++;
        }
        else{
            no_bouquets+=cnt/adj;
            cnt=0;
        }
    }
    no_bouquets+=cnt/adj;
    return no_bouquets>=need;
}


class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {

        int l=1;
        int h=*max_element(arr.begin(),arr.end());

        int ans=-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(can_make(mid,arr,k,m)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};