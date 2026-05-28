class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;
        mp['a']=-1;
        mp['b']=-1;
        mp['c']=-1;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
            int min_val=min({mp['a'],mp['b'],mp['c']});
            ans+=min_val+1;
        }
        return ans;

    }
};