class Solution {
public:
    int maxScore(vector<int>& a, int k) {

        int n=a.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=a[i];
            
        }
        ans=max(ans,sum);
        int l=k-1;
        int r=n-1;
        while(l>=0){
            sum-=a[l];
            sum+=a[r];
            ans=max(ans,sum);
            l--;
            r--;
        }
        return ans;
        
    }
};