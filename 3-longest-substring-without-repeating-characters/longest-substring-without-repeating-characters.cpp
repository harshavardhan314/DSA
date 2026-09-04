class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int l=0;
        int ans=0;
        map<char,int>mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(l<r && mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};