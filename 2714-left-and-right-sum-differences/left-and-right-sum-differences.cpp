class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        suff[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suff[j]=suff[j+1]+nums[j];

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
           int left= i-1>=0?pre[i-1]:0;
           int right=i+1<n?suff[i+1]:0;
           ans.push_back(abs(left-right));
        }
        return ans;


        
    }
};