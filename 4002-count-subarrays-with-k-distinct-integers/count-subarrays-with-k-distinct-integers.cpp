

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {

        int r1=-1;
        int r2=-1;
        map<int,int>f1,f2;
        long long ans=0;
        int n=nums.size();
        int mfreq=0;
        for(int l=0;l<n;l++){
            while(r2<n  && f2.size()<k+1){
                r2++;
                if(r2<n) f2[nums[r2]]++;
            }

            while(r1<n && mfreq<k){
                r1++;
                if(r1<n){
                f1[nums[r1]]++;
                if(f1[nums[r1]]==m)mfreq++;
                }
                
            }

            if (r1<r2)ans+=(r2-r1);

            f2[nums[l]]--;
            if(f2[nums[l]]==0)f2.erase(nums[l]);
            f1[nums[l]]--;
            if(f1[nums[l]]==m-1)mfreq--;

        }
        return ans;
        
        
    }
};