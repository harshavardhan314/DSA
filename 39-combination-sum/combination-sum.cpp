class Solution {
public:
    void solve(int idx,vector<int>&v,int target,vector<vector<int>>&ans,vector<int>&temp)
    {
       
            if(target==0)
            {
                ans.push_back(temp);
                return;
            }
            
        for(int i=idx;i<v.size();i++)
        {
           

            if(v[i]>target)
            break;
            temp.push_back(v[i]);
             solve(i,v,target-v[i],ans,temp);
             temp.pop_back();  
        }
      

    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {

        sort(v.begin(),v.end());

        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,v,target,ans,temp);
       
        return ans;
    }
};