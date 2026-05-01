class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums.push_back(nums[i]);
        }
        vector<int>pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
            
        }
        int l=0;
        int res=INT_MIN;
        int temp=0;
        for(int r=0;r<n;r++){
            temp+=nums[r]*r;
        }
       
        res=max(res,temp);
        for(int r=n;r<nums.size();r++){
            int middle_sum=pre[r-1]-pre[l];
           
            temp-=middle_sum;
            
            temp+=nums[r]*(n-1);
            
            
            res=max(res,temp);
            l++;

        }
        return res;

        
    }
};