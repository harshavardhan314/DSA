class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        k=k%n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int new_place=(i+k)%n;
            mp[new_place]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=mp[i];
        }
        
        
        // T.c=O(n)
        // S.c=O(n)
        
    }
};