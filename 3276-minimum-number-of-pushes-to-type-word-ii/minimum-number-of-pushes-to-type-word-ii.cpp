class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto it:word){
            mp[it]++;
        }
        vector<pair<int,char>>vp;
        for(auto it:mp){
            vp.push_back({it.second,it.first});
        }
        sort(vp.rbegin(),vp.rend());
        int ones=8,twos=8,threes=8,four=8;
        int ans=0;
        for(auto &[freq,c]:vp){

            
            if(ones>0){
                ans+=freq;
                ones-=1;
                freq=0;
            }
            else if(twos>0){
                ans+=freq*2;
                twos-=1;
                freq=0;
            }
            else if(threes>0){
                ans+=freq*3;
                threes-=1;
                 freq=0;
            }
            else{
                ans+=freq*4;
                four-=1;
            }
            
        }
        return ans;
    }
};