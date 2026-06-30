class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        map<char,int>mp;
        int ans=0;
        int n=s.size();
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp.size()==3){
                ans+=n-r;
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(mp.find(s[l]));
                l++;
            }
        }
        return ans;
        
    }
};