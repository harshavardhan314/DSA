class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {

        map<int,int>freq;
    
        int n=a.size();
        vector<int>ans(n,0);
        int common=0;

        for(int i=0;i<n;i++){
            
            freq[a[i]]++;
            if(freq[a[i]]==2)common++;
            freq[b[i]]++;
            if(freq[b[i]]==2)common++;
            ans[i]=common;
        }
        return ans;
        
    }
};