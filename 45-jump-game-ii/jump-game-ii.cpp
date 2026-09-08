class Solution {
public:
    int jump(vector<int>& nums) {
        
        int steps=1;
        int prev=nums[0];
        int curr_max=0;
        int n=nums.size();
        if(n==1)return 0;
        for(int i=1;i<n;i++){
            if(i>prev){
                steps++;
                prev=curr_max;
                curr_max=0;
            }
            curr_max=max(curr_max,i+nums[i]);
        }
        return steps;
        
    }
};