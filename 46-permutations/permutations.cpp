class Solution {
public:
    vector<vector<int>>rec(vector<int>&nums,unordered_set<int>st,vector<vector<int>>&res,  vector<int>&temp){
        int n=nums.size();
        
        if(st.size()==nums.size()){
            res.push_back(temp);
        }
      
        for(int i=0;i<n;i++){

            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
            st.insert(nums[i]);
            rec(nums,st,res,temp);
            temp.pop_back();
            st.erase(nums[i]);
            }
            
        }
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>st;
        vector<vector<int>>res;
        vector<int>temp;
        return rec(nums,st,res,temp);
        
        
    }
};