class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string req="balloon";
        map<char,int>mp;
        for(auto it:text){
            mp[it]++;
        }
        int ans=INT_MAX;
        for(auto it:req){
            if(it=='l' || it=='o'){
                ans=min(ans,mp[it]/2);
            }
            else
            ans=min(ans,mp[it]);
        }
        
        return ans;
        
    }
};