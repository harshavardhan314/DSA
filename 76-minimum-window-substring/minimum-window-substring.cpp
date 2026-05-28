class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }
        int l=0;
        int st_idx=-1;
        int min_len=1e9;
        int n=s.size();
        int m=t.size();
        int cnt=0;
        for(int r=0;r<n;r++){
            // >0 indicates that char is in t..
            if(mp[s[r]]>0)cnt++;
            mp[s[r]]--;
            while(cnt==m){
                
                if(r-l+1<min_len){
                    st_idx=l;
                    min_len=r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)cnt--;
                l++;

            }
        }
        if(st_idx==-1)return "";
        return s.substr(st_idx,min_len);
    }
};