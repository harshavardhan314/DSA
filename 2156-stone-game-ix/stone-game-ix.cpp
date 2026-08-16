class Solution {
public:
    bool stoneGameIX(vector<int>& s) {


        
        int n=s.size();
       
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]%3]++;
        }
        if(mp[0]%2==0)return mp[1]>0 && mp[2]>0;
        return abs(mp[1]-mp[2])>2;
        

        
    }
};