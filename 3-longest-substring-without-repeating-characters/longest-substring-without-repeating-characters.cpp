class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        map<char,int>mp;
        int ans=0;
        int n=s.size();
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};