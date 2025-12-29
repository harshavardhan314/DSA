class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(int idx,unordered_map<string,vector<string>>&mp,string curr,string next)
    {
       if(curr.size()==1)
       return true;
       if(idx==curr.size()-1)
       {
            if(dp.count(next))return dp[next];
        return dp[next]=solve(0,mp,next,"");
       }
       string temp=curr.substr(idx,2);
       if(!mp.count(temp))return false;
       for(auto it:mp[temp])
       {
        if(solve(idx+1,mp,curr,next+it))return true;
       }
       return false;

    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<string>>mp;
        for(auto it:allowed)
        {
            mp[it.substr(0,2)].push_back(it.substr(2));
        }
        return solve(0,mp,bottom,"");

        
    }
};