class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        
        multiset<int>ms;
        for(auto it:g){
            ms.insert(it);
        }
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            
            auto it=ms.upper_bound(s[i]);
            if(it==ms.begin()) continue;
            it--;
            ms.erase(ms.find(*it));
            ans++;
        }
        return ans;
    }
};