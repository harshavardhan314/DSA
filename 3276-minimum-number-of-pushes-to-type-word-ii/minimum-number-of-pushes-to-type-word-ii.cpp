class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(auto it:word){
            mp[it-'a']++;
        }
        int ans=0;
        sort(mp.rbegin(),mp.rend());
        for(int i=0;i<26;i++){
            int freq=mp[i];
            int c=i/8+1;
            ans+=freq*c;
        }
        return ans;
    }
};