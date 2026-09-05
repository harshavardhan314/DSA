class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>maxii(n,0);
        for(int i=0;i<n;i++){
            maxii[i]=nums[i];
            if(i>0)
            maxii[i]=max(maxii[i],maxii[i-1]);
        }
        vector<int>minii(n);
        for(int i=n-1;i>=0;i--){
            minii[i]=nums[i];
            if(i+1<n)
            minii[i]=min(minii[i],minii[i+1]);
        }
        for(int i=0;i<n;i++){
            int diff=maxii[i]-minii[i];
            
            if(diff<=k)return i;
        }
        
        return -1;

        
    }
};