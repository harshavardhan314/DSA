class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int st=nums[0];
        int i=0;
      while(i<nums.size()){
        if(st==nums[i]){st++;i++;}
        else{
            while(st<nums[i]){
                ans.push_back(st);
                st++;
            }
          
        }
      }
       return ans;
    }
   
};