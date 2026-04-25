int check(map<char,int>&mp){
    int ans=0;
    for(auto [ch,freq]:mp){
        ans=max(ans,freq);
    }
    return ans;
}
class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();

        int l=0;
        int ans=0;
        map<char,int>mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(r-l+1-check(mp)>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);

        }
        return ans;


        
    }
};