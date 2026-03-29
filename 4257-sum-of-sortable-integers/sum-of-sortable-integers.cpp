bool can(vector<int>& nums,int k) {

    int n=nums.size();
    
    int mini=0;

    for(int i=0;i<n;i+=k){

        if(nums[i]<mini)return false;
        
        int maxii=nums[i];
        int cnt=0;
        for(int j=i;j<i+k;j++){
            if(nums[j]<mini)return false;
            if(nums[j]>nums[i+(j+1)%k])cnt++;
            maxii=max(maxii,nums[j]);
        }
        if(cnt>1)return false;
        
        mini=maxii;

    }
    return true;


 
}

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            if(n%i!=0)continue;

            if(can(nums,i)){cout<<i<<endl;ans+=i;}
        }

        return ans;
    }
};