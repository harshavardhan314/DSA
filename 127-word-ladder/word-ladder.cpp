class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {

        queue<pair<string,int>>q;
        q.push({bw,1});
        unordered_set<string>mp(wl.begin(),wl.end());
        mp.erase(bw);
        while(!q.empty()){
            auto[s,count]=q.front();
            if(s==ew){
                return count;
            }
            q.pop();
            for(int i=0;i<s.size();i++){
                char prev=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    
                    if(mp.find(s)!=mp.end()){
                        q.push({s,count+1});
                        mp.erase(s);
                    }
                }
                s[i]=prev;
            }
        }    
        return 0;    
    }
};